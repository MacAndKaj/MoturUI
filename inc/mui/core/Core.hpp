/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MOTURUI_CORE_CORE_HPP
#define MOTURUI_CORE_CORE_HPP

#include <mui/core/connection/ConnectionManager.hpp>
#include <mui/core/connection/IDBusBuilder.hpp>
#include <mui/core/connection/NetworkManagerProxy.hpp>
#include <mui/interface/InterfaceManager.hpp>

#include <memory>

namespace mui::core
{

class Core// : public ICore
{
public:
    Core(mui::interface::InterfaceManager& interface_manager, const std::string& password);
    virtual ~Core() = default;

protected:
    void handleTriggerUpdateAccessPoints();
    void handleConnectAccessPoint(const std::string& ap);

private:
    mui::interface::InterfaceManager& m_interface_manager;
    std::shared_ptr<connection::IDBusBuilder> m_dbus_builder;
    std::unique_ptr<connection::ConnectionManager> m_connection_manager;
};

} // namespace mui::core

#endif // MOTURUI_CORE_CORE_HPP
