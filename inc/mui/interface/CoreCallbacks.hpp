/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MOTURUI_INTERFACE_CORECALLBACKS_HPP
#define MOTURUI_INTERFACE_CORECALLBACKS_HPP

#include <functional>
#include <string>

namespace mui::interface
{

struct CoreCallbacks
{
    std::function<void()> trigger_update_access_points_cb;
    std::function<void(const std::string&)> connect_access_point_cb;
};

} // namespace mui::interface

#endif // MOTURUI_INTERFACE_CORECALLBACKS_HPP
