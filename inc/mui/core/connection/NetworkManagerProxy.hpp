/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MOTURUI_CORE_CONNECTION_NETWORKMANAGERPROXY_HPP
#define MOTURUI_CORE_CONNECTION_NETWORKMANAGERPROXY_HPP

#include <mui/core/connection/IDBusBuilder.hpp>

#include <QString>

#include <memory>

namespace mui::core::connection
{
class IDBusBuilder;

class NetworkManagerProxy
{
public:
    NetworkManagerProxy(std::shared_ptr<IDBusBuilder> dbus_builder);

    void setCurrentDevice(const std::string& dev);
    std::vector<std::string> getAllDevices();
    std::unordered_map<std::string, std::string> getAllAccessPoints();
    bool isWireless(const std::string& device_path);
    bool addAndActivateConnection(const std::string& access_point_path);

private:
    std::shared_ptr<IDBusBuilder> m_dbus_builder;
    std::unique_ptr<QDBusAbstractInterface> m_network_manager_interface;
    std::string m_current_device;
};

} // namespace mui::core::connection

#endif // MOTURUI_CORE_CONNECTION_NETWORKMANAGERPROXY_HPP
