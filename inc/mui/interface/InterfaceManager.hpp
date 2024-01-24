/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MOTURUI_INTERFACE_INTERFACEMANAGER_HPP
#define MOTURUI_INTERFACE_INTERFACEMANAGER_HPP

#include <mui/interface/CoreCallbacks.hpp>
#include <mui/interface/ViewCallbacks.hpp>

#include <memory>

namespace mui::interface
{
class InterfaceManager
{
public:
    virtual ~InterfaceManager() = default;
    void setCoreCallbacks(std::shared_ptr<CoreCallbacks> core_callbacks);
    void setViewCallbacks(std::shared_ptr<ViewCallbacks> view_callbacks);

    void triggerUpdateAccessPoints();
    void updateAccessPoints(const std::vector<std::string>& aps);
    void connectAccessPoint(const std::string& ap);
    //TODO:
    // ViewFacade& view(); // it will allow tu use interface_manager.view().updateAccessPoints(aps);
    // CoreFacade& core(); // it will allow tu use interface_manager.core().triggerUpdateAccessPoints();

private:
    std::shared_ptr<CoreCallbacks> m_core_callbacks;
    std::shared_ptr<ViewCallbacks> m_view_callbacks;
};

} // namespace mui::interface

#endif // MOTURUI_INTERFACE_INTERFACEMANAGER_HPP
