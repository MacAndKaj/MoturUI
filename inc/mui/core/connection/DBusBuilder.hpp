/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MOTURUI_CORE_CONNECTION_DBUSBUILDER_HPP
#define MOTURUI_CORE_CONNECTION_DBUSBUILDER_HPP

#include <mui/core/connection/IDBusBuilder.hpp>

#include <QDBusConnection>
#include <QDBusInterface>

namespace mui::core::connection
{

class DBusBuilder : public IDBusBuilder
{
public:
    DBusBuilder();
    virtual ~DBusBuilder() = default;

    void setBusName(const std::string& service_name) override;

    std::unique_ptr<QDBusAbstractInterface> buildNetworkManagerInterface() override;
    std::unique_ptr<QDBusAbstractInterface> buildNetworkManagerDeviceInterface(const std::string& object_path) override;
    std::unique_ptr<QDBusAbstractInterface> buildWirelessDeviceInterface(const std::string& object_path) override;
    
    std::unique_ptr<QDBusAbstractInterface> buildPropertiesInterface(const std::string& object_path) override;
    std::unique_ptr<QDBusAbstractInterface> buildIntrospectableInterface(const std::string& object_path) override;

private:
    QDBusConnection m_connection;
    QString m_service_name;
};

} // namespace mui::core::connection

#endif // MOTURUI_CORE_CONNECTION_DBUSBUILDER_HPP
