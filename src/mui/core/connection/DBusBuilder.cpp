/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */

#include <mui/core/connection/DBusBuilder.hpp>

#include <QDBusInterface>

#include <exception>
#include <iostream>

namespace mui::core::connection
{

const QString INTROSPECTABLE_INTERFACE = "org.freedesktop.DBus.Introspectable";

DBusBuilder::DBusBuilder()
    : m_connection(QDBusConnection::systemBus())
{
}

void DBusBuilder::setBusName(const std::string& service_name)
{
    std::cout << "Setting bus name to: " << service_name << std::endl;
    m_service_name = QString::fromStdString(service_name);
}

std::unique_ptr<QDBusAbstractInterface> DBusBuilder::buildNetworkManagerInterface()
{
    const QString object_path = "/org/freedesktop/NetworkManager";
    const QString interface_name = "org.freedesktop.NetworkManager";

    auto obj = std::make_unique<QDBusInterface>(m_service_name, object_path, interface_name, m_connection);

    if (not obj->isValid())
    {
        std::cerr << "NetworkManagerInterface invalid!" << std::endl;
        throw std::runtime_error("Failed to create NetworkManager interface");
    }
    
    std::cout << "NetworkManagerInterface created" << std::endl;

    return obj;
}

std::unique_ptr<QDBusAbstractInterface> DBusBuilder::buildNetworkManagerDeviceInterface(const std::string& object_path)
{
    const QString interface_name = "org.freedesktop.NetworkManager.Device";

    auto obj = std::make_unique<QDBusInterface>(
        m_service_name, QString::fromStdString(object_path), interface_name, m_connection);

    if (not obj->isValid())
    {
        std::cerr << "Device interface invalid!" << std::endl;
        throw std::runtime_error("Failed to create Device interface");
    }
    
    std::cout << "Device interface created" << std::endl;

    return obj;
}

std::unique_ptr<QDBusAbstractInterface> DBusBuilder::buildWirelessDeviceInterface(const std::string& object_path)
{
    const QString interface_name = "org.freedesktop.NetworkManager.Device.Wireless";

    auto obj = std::make_unique<QDBusInterface>(
        m_service_name, QString::fromStdString(object_path), interface_name, m_connection);

    if (not obj->isValid())
    {
        std::cerr << "Wireless Device interface invalid!" << std::endl;
        throw std::runtime_error("Failed to create Wireless Device interface");
    }
    
    std::cout << "Wireless Device interface created" << std::endl;

    return obj;
}

std::unique_ptr<QDBusAbstractInterface> DBusBuilder::buildPropertiesInterface(const std::string& object_path)
{
    const QString interface_name = "org.freedesktop.DBus.Properties";

    auto obj = std::make_unique<QDBusInterface>(
        m_service_name, QString::fromStdString(object_path), interface_name, m_connection);

    if (not obj->isValid())
    {
        std::cerr << "Properties interface invalid!" << std::endl;
        throw std::runtime_error("Failed to create Properties interface");
    }
    
    std::cout << "Properties interface created" << std::endl;

    return obj;
}

std::unique_ptr<QDBusAbstractInterface> DBusBuilder::buildIntrospectableInterface(const std::string& object_path)
{
    const QString interface_name = "org.freedesktop.DBus.Introspectable";

    auto obj = std::make_unique<QDBusInterface>(
        m_service_name, QString::fromStdString(object_path), interface_name, m_connection);

    if (not obj->isValid())
    {
        std::cerr << "Introspectable interface invalid!" << std::endl;
        throw std::runtime_error("Failed to create Introspectable interface");
    }
    
    std::cout << "Introspectable interface created" << std::endl;

    return obj;
}

} // namespace mui::core::connection