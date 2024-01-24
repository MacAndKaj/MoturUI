/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MOTURUI_CORE_CONNECTION_CONNECTIONMANAGER_HPP
#define MOTURUI_CORE_CONNECTION_CONNECTIONMANAGER_HPP

#include <mui/core/connection/IDBusBuilder.hpp>
#include <mui/core/connection/NetworkManagerProxy.hpp>

#include <atomic>
#include <deque>
#include <functional>
#include <thread>

namespace mui::core::connection
{

class ConnectionManager
{
public:
    ConnectionManager(std::shared_ptr<IDBusBuilder> dbus_builder, const std::string& password);
    virtual ~ConnectionManager();

    void setupWifiInterface();
    void findAccessPoints(const std::function<void(std::vector<std::string>)>& callback);
    void connectToAccessPoint(const std::string& ssid, const std::function<void(bool)>& success_callback);

protected:
    void run();

private:
    std::shared_ptr<NetworkManagerProxy> m_network_manager;

    std::mutex m_queue_mutex;
    std::deque<std::function<void()>> m_execution_queue;
    std::atomic_bool m_stopped;
    std::thread m_thread;

    std::unordered_map<std::string, std::string> m_cached_ssids_to_aps;
    const std::string m_password;
};

} // namespace mui::core::connection

#endif // MOTURUI_CORE_CONNECTION_CONNECTIONMANAGER_HPP
