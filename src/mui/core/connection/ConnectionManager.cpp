/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */

#include <mui/core/connection/ConnectionManager.hpp>

#include <mui/core/connection/NetworkManagerProxy.hpp>

#include <cmath>
#include <iostream>
#include <chrono>
#include <mutex>

namespace mui::core::connection
{

ConnectionManager::ConnectionManager(std::shared_ptr<IDBusBuilder> dbus_builder, const std::string& password)
    : m_network_manager(std::make_shared<NetworkManagerProxy>(std::move(dbus_builder)))
    , m_stopped(false)
    , m_thread([this]{run();})
    , m_password(password)
{
}

ConnectionManager::~ConnectionManager()
{
    std::cout << "Stopping ConnectionManager" << std::endl;
    m_stopped = true;
    if (m_thread.joinable())
    {
        m_thread.join();
    }

    std::cout << "ConnectionManager stopped" << std::endl;
}

void ConnectionManager::run()
{
    setupWifiInterface();
    using namespace std::chrono_literals;
    while (not m_stopped)
    {
        {
            std::lock_guard<std::mutex> lock(m_queue_mutex);
            if (not m_execution_queue.empty())
            {
                auto& task = m_execution_queue.front();
                task();
                m_execution_queue.pop_front();
            }
        }

        std::this_thread::sleep_for(10ms);
    }
}

void ConnectionManager::setupWifiInterface()
{
    std::cout << "Setting up main WiFi interface" << std::endl;

    std::vector<std::string> devices = m_network_manager->getAllDevices();
    std::cout << "Found " << devices.size() << " devices" << std::endl;
    
    auto dev_iter = std::find_if(devices.begin(), devices.end(), [this](auto& dev){
        return m_network_manager->isWireless(dev);
    });
    
    std::cout   << "Wireless device - " 
                << (dev_iter !=  devices.end() ? *dev_iter : " not found")
                << std::endl;

    if (dev_iter == devices.end())
    {
        throw std::runtime_error("Wireless device not found");
    }

    m_network_manager->setCurrentDevice(*dev_iter);
}

void ConnectionManager::findAccessPoints(const std::function<void(std::vector<std::string>)>& found_aps_callback)
{
    std::lock_guard<std::mutex> lock(m_queue_mutex);
    m_execution_queue.emplace_back([this, found_aps_callback](){
        m_cached_ssids_to_aps = m_network_manager->getAllAccessPoints();
        std::vector<std::string> aps;
        std::transform(m_cached_ssids_to_aps.begin(), m_cached_ssids_to_aps.end(), std::back_inserter(aps), 
            [](auto& iter){return iter.first;});
        found_aps_callback(aps);
    });
}

void ConnectionManager::connectToAccessPoint(const std::string& ssid,
    const std::function<void(bool)>& success_callback)
{
    auto ap_path = m_cached_ssids_to_aps.at(ssid);
    std::lock_guard<std::mutex> lock(m_queue_mutex);
    m_execution_queue.emplace_back([this, ap_path, success_callback](){
        bool success = m_network_manager->addAndActivateConnection(ap_path);
        success_callback(success);
    });
}

} // namespace mui::core::connection
