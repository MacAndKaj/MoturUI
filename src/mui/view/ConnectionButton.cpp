/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */

#include <mui/view/ConnectionButton.hpp>

#include <QPushButton>

namespace mui::view
{

static const QString connectText = "Connect";
static const QString disconnectText = "Disconnect";

ConnectionButton::ConnectionButton(QPushButton& button)
    : m_button(button)
{
    connect(&m_button, &QPushButton::clicked, [this]{
        if (m_button.text() == connectText) emit connectButtonClicked();
    });
}

void ConnectionButton::setConnectText()
{
    m_button.setText(connectText);
}

void ConnectionButton::setDisconnectText()
{
    m_button.setText(disconnectText);
}

} // namespace mui::view
