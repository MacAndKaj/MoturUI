/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#include <mui/view/ViewManager.hpp>

#include <mui/interface/ViewCallbacks.hpp>

namespace mui::view
{

ViewManager::ViewManager(mui::interface::InterfaceManager& interface_manager)
    : m_mainWindow()
    , m_interface_manager(interface_manager)
{
    m_uiMainWindow.setupUi(&m_mainWindow);

    initUiElementsControllers();
    initCoreInterface();
    initSignals();

    m_mainWindow.show();
}

void ViewManager::initUiElementsControllers()
{
    m_led = std::make_unique<ConnectionStatusLed>(*m_uiMainWindow.connectionImage);
    m_led->setDisconnected();

    m_text = std::make_unique<ConnectionStatusText>(*m_uiMainWindow.connectionText);
    m_text->setDisconnected();

    m_connection_button = std::make_unique<ConnectionButton>(*m_uiMainWindow.connectionButton);
    m_connection_button->setConnectText();

    m_trigger_access_points_update_button = 
        std::make_unique<UpdateAccessPointsButton>(*m_uiMainWindow.updateAccessPointsButton);

    m_access_points_combo_box = std::make_unique<AccessPointsComboBox>(*m_uiMainWindow.accessPointsComboBox);
}

void ViewManager::initSignals()
{
    connect(m_uiMainWindow.actionQuit, &QAction::triggered, &m_mainWindow, &QMainWindow::close);
    connect(&*m_trigger_access_points_update_button, &UpdateAccessPointsButton::triggerUpdateAccessPoints,
        [this](){m_interface_manager.triggerUpdateAccessPoints();});
    connect(&*m_access_points_combo_box, &AccessPointsComboBox::selectedAccessPointChanged, 
        [this](const auto& new_ap){m_current_state.ap_selected = new_ap;});
    connect(&*m_connection_button, &ConnectionButton::connectButtonClicked,
        [this](){m_interface_manager.connectAccessPoint(m_current_state.ap_selected);});
}

void ViewManager::initCoreInterface()
{
    auto cbs = std::make_shared<interface::ViewCallbacks>();
    cbs->update_access_points_cb = [this](const auto& arg){m_access_points_combo_box->update(arg);};
    m_interface_manager.setViewCallbacks(cbs);

    m_current_state.connected = false;
    m_current_state.ap_selected = "";
}

} // namespace mui::view
