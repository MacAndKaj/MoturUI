/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */

#include <mui/interface/InterfaceManager.hpp>

#include <iostream>

namespace mui::interface
{

void InterfaceManager::setCoreCallbacks(std::shared_ptr<CoreCallbacks> core_callbacks)
{
    m_core_callbacks = core_callbacks;
}

void InterfaceManager::setViewCallbacks(std::shared_ptr<ViewCallbacks> view_callbacks)
{
    m_view_callbacks = view_callbacks;
}

void InterfaceManager::triggerUpdateAccessPoints()
{
    if (m_core_callbacks)
    {
        m_core_callbacks->trigger_update_access_points_cb();
    }
}

void InterfaceManager::updateAccessPoints(const std::vector<std::string>& aps)
{
    // replace with assert
    if (m_view_callbacks)
    {
        m_view_callbacks->update_access_points_cb(aps);
    }
}

void InterfaceManager::connectAccessPoint(const std::string& ap)
{
    if (m_core_callbacks)
    {
        m_core_callbacks->connect_access_point_cb(ap);
    }
}

} // namespace mui::interface
