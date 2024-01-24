/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MOTURUI_CORE_CONNECTION_IDBUSBUILDER_HPP
#define MOTURUI_CORE_CONNECTION_IDBUSBUILDER_HPP

#include <QDBusInterface>

#include <memory>

namespace mui::core::connection
{

class IDBusBuilder
{
public:
    virtual ~IDBusBuilder() = default;
    
    virtual void setBusName(const std::string& service_name) = 0;
    
    virtual std::unique_ptr<QDBusAbstractInterface> buildNetworkManagerInterface() = 0;
    virtual std::unique_ptr<QDBusAbstractInterface> buildNetworkManagerDeviceInterface(const std::string& object_path) = 0;
    virtual std::unique_ptr<QDBusAbstractInterface> buildWirelessDeviceInterface(const std::string& object_path) = 0;

    virtual std::unique_ptr<QDBusAbstractInterface> buildPropertiesInterface(const std::string& object_path) = 0;
    virtual std::unique_ptr<QDBusAbstractInterface> buildIntrospectableInterface(const std::string& object_path) = 0;
};

} // namespace mui::core::connection

#endif // MOTURUI_CORE_CONNECTION_IDBUSBUILDER_HPP
