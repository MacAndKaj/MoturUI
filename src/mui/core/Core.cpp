/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */

#include <mui/core/Core.hpp>

#include <mui/core/connection/DBusBuilder.hpp>
#include <mui/interface/CoreCallbacks.hpp>

#include <iostream>

namespace mui::core
{

Core::Core(mui::interface::InterfaceManager& interface_manager, const std::string& password)
    : m_interface_manager(interface_manager)
    , m_dbus_builder(std::make_shared<connection::DBusBuilder>())
    , m_connection_manager(std::make_unique<connection::ConnectionManager>(m_dbus_builder, password))
{
    std::cout << "Core initialized" << std::endl;

    auto cbs = std::make_shared<interface::CoreCallbacks>();
    cbs->trigger_update_access_points_cb = [this]{handleTriggerUpdateAccessPoints();};
    cbs->connect_access_point_cb = [this](const auto& ap){handleConnectAccessPoint(ap);};
    m_interface_manager.setCoreCallbacks(cbs);
}

void Core::handleTriggerUpdateAccessPoints()
{
    std::cout << "Scheduling task to update access points list" << std::endl;
    auto cb = [this](auto aps){m_interface_manager.updateAccessPoints(aps);};
    m_connection_manager->findAccessPoints(cb);
}

void Core::handleConnectAccessPoint(const std::string& ap)
{
    std::cout << "Scheduling task to connect to access point" << std::endl;
    auto cb = [](bool success){
        std::cout << "Connection success: " << std::boolalpha << success << std::endl;
    };
    m_connection_manager->connectToAccessPoint(ap, cb);
}

} // namespace mui::core
