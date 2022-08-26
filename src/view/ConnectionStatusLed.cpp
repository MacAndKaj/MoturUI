/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#include <view/ConnectionStatusLed.hpp>

#include <QLabel>

#include <stdexcept>
#include <tuple>

namespace view
{
static const QString s_connectedLedFilename(":/connected_led.png");
static const QString s_disconnectedLedFilename(":/disconnected_led.png");

ConnectionStatusLed::ConnectionStatusLed(QLabel& label)
    : m_label(label)
    , m_logPrefix("[ConnectionStatusLed]")
{
}

void ConnectionStatusLed::setConnected()
{
    setImage(s_connectedLedFilename);
}

void ConnectionStatusLed::setDisconnected()
{
    setImage(s_disconnectedLedFilename);
}

void ConnectionStatusLed::setImage(const QString &filename)
{
    if (not m_pixmap.load(filename))
    {
        throw std::runtime_error("Operation not successfull");
    }

    m_label.setAlignment(Qt::AlignCenter);
    m_label.setPixmap(m_pixmap.scaledToHeight(m_label.height()));
}



} // namespace view
