/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */

#include <mui/view/ConnectionStatusText.hpp>

#include <QString>
#include <QLabel>

namespace mui::view
{

static const QString disconnectedText = "Disconnected";
static const QString connectedText = "Connected";
static const QString inProgressText = "Connecting in progress";

ConnectionStatusText::ConnectionStatusText(QLabel& label)
    : m_label(label)
{
}

void ConnectionStatusText::setConnected()
{
    m_label.setText(connectedText);
}

void ConnectionStatusText::setDisconnected()
{
    m_label.setText(disconnectedText);
}

void ConnectionStatusText::setConnectingInProgress()
{
    m_label.setText(inProgressText);
}


} // namespace mui::view
