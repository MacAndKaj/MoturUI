/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MOTURUI_INTERFACE_VIEWCALLBACKS_HPP
#define MOTURUI_INTERFACE_VIEWCALLBACKS_HPP

#include <functional>
#include <string>
#include <vector>

namespace mui::interface
{

using VectorOfStrings = std::vector<std::string>;

struct ViewCallbacks
{
    std::function<void(const VectorOfStrings&)> update_access_points_cb;
};

} // namespace mui::interface

#endif // MOTURUI_INTERFACE_VIEWCALLBACKS_HPP
