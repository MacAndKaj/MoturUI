/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#include <view/ViewManager.hpp>
#include <view/ConnectionButton.hpp>
#include <view/ConnectionStatusLed.hpp>
#include <view/ConnectionStatusText.hpp>

namespace view
{

ViewManager::ViewManager()
{
    m_uiMainWindow.setupUi(&m_mainWindow);

    m_led = std::make_unique<ConnectionStatusLed>(*m_uiMainWindow.connectionImage);
    m_led->setDisconnected();

    m_text = std::make_unique<ConnectionStatusText>(*m_uiMainWindow.connectionText);
    m_text->setDisconnected();

    m_button = std::make_unique<ConnectionButton>(*m_uiMainWindow.connectionButton);
    m_button->setConnectText();

    initSignals();
    m_mainWindow.show();
}

void ViewManager::initSignals()
{
    connect(m_uiMainWindow.actionQuit, &QAction::triggered, &m_mainWindow, &QMainWindow::close);

}

} // namespace view
