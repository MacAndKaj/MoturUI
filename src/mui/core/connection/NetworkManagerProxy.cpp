/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */

#include <mui/core/connection/NetworkManagerProxy.hpp>

#include <QByteArray>
#include <QDBusArgument>
#include <QDebug>

#include <iostream>
#include <unordered_map>
#include <vector>

namespace mui::core::connection 
{

const std::string NETWORK_MANAGER_BUS_NAME = "org.freedesktop.NetworkManager";

NetworkManagerProxy::NetworkManagerProxy(std::shared_ptr<IDBusBuilder> dbus_builder)
    : m_dbus_builder(std::move(dbus_builder))
{
    m_dbus_builder->setBusName(NETWORK_MANAGER_BUS_NAME);
    m_network_manager_interface = m_dbus_builder->buildNetworkManagerInterface();
}

void NetworkManagerProxy::setCurrentDevice(const std::string& dev)
{
    std::cout << "Current device set to object: " << dev << std::endl;
    m_current_device = dev;
}

std::vector<std::string> NetworkManagerProxy::getAllDevices()
{
    std::cout << "Calling GetAllDevices" << std::endl;
    QDBusMessage reply = m_network_manager_interface->call("GetAllDevices");
    std::vector<std::string> devices;

    QList<QVariant> arguments = reply.arguments();
    if (arguments.empty())
    {
        std::cerr   << "No arguments received in GetAllDevices reply" << std::endl;
        return {};
    }

    QVariant& argument = arguments.first();

    auto arg = argument.value<QDBusArgument>();
    if (arg.currentType() != QDBusArgument::ArrayType)
    {
        std::cerr   << "Incorrect argument type " << arg.currentType() 
                    << " Expected: " << QDBusArgument::ArrayType << std::endl;
        qDebug() << argument;
    }

    QString path;
    arg.beginArray();
    while (!arg.atEnd())
    {
        arg >> path;
        devices.emplace_back(path.toStdString());
    }
    arg.endArray();

    return devices;
}

bool NetworkManagerProxy::isWireless(const std::string& device_path)
{
    const QString device_interface_name = "org.freedesktop.NetworkManager.Device";
    const QString device_type_property_name = "DeviceType";
    const QString get_method_name = "Get";
    constexpr std::uint32_t NM_DEVICE_TYPE_WIFI = 2;

    auto properties_interface = m_dbus_builder->buildPropertiesInterface(device_path);

    QDBusMessage reply = properties_interface->call(get_method_name, device_interface_name, device_type_property_name);
    QList<QVariant> arguments = reply.arguments();
    if (arguments.empty())
    {
        std::cerr   << "No arguments received in GetAllDevices reply" << std::endl;
        return {};
    }
        
    QVariant& argument = arguments.first();

    auto arg = argument.value<QDBusVariant>().variant();
    auto dev_type = arg.value<std::uint32_t>();

    std::cout << "Device type: " << dev_type << std::endl;

    return dev_type == NM_DEVICE_TYPE_WIFI;
}

std::unordered_map<std::string, std::string> NetworkManagerProxy::getAllAccessPoints()
{
    const QString access_point_interface_name = "org.freedesktop.NetworkManager.AccessPoint";
    const QString get_all_access_points_method_name = "GetAllAccessPoints";
    const QString ssid_property_name = "Ssid";
    const QString get_method_name = "Get";
    
    auto interface = m_dbus_builder->buildWirelessDeviceInterface(m_current_device);

    QDBusMessage reply = interface->call(get_all_access_points_method_name);

    QList<QVariant> arguments = reply.arguments();
    if (arguments.empty())
    {
        std::cerr   << "No arguments received in GetAllAccessPoints reply" << std::endl;
        return {};
    }

    QVariant& argument = arguments.first();

    auto arg = argument.value<QDBusArgument>();
    if (arg.currentType() != QDBusArgument::ArrayType)
    {
        std::cerr   << "Incorrect argument type " << arg.currentType() 
                    << " Expected: " << QDBusArgument::ArrayType << std::endl;
        qDebug() << argument;
    }

    std::vector<std::string> aps;
    QString path;
    arg.beginArray();
    while (!arg.atEnd())
    {
        arg >> path;
        aps.emplace_back(path.toStdString());
    }
    arg.endArray();

    std::unordered_map<std::string, std::string> ssid_to_ap_map;

    for (auto& ap : aps)
    {
        auto properties_interface = m_dbus_builder->buildPropertiesInterface(ap);

        QDBusMessage reply = properties_interface->call(get_method_name, access_point_interface_name, ssid_property_name);
        QList<QVariant> arguments = reply.arguments();
        if (arguments.empty())
        {
            std::cerr   << "No arguments received in GetAllDevices reply" << std::endl;
            return {};
        }
            
        QVariant& argument = arguments.first();
        auto arg = argument.value<QDBusVariant>().variant();
        auto ssid = arg.value<QByteArray>();

        ssid_to_ap_map[ssid.toStdString()] = ap;
    }

    return ssid_to_ap_map;
}

bool NetworkManagerProxy::addAndActivateConnection(const std::string& access_point_path)
{
    const QString add_and_activate_connection_method_name = "AddAndActivateConnection";
    QDBusArgument settings;
    settings.beginMap();
    settings.endMap();

     QDBusMessage reply = m_network_manager_interface->call(add_and_activate_connection_method_name,
                                                            settings.asVariant(),
                                                            QString::fromStdString(m_current_device),
                                                            QString::fromStdString(access_point_path));

    qDebug() << reply;
    return false;
}

} // namespace mui::core::connection
