/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */

#include <view/ConnectionButton.hpp>

#include <QPushButton>

namespace view
{

static const QString connectText = "Connect";
static const QString disconnectText = "Disconnect";

ConnectionButton::ConnectionButton(QPushButton& button)
    : m_button(button)
{
}

void ConnectionButton::setConnectText()
{
    m_button.setText(connectText);
}

void ConnectionButton::setDisconnectText()
{
    m_button.setText(disconnectText);
}

} // namespace view
