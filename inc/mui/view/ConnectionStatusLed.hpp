/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef MUI_VIEW_CONNECTIONSTATUSLED_HPP
#define MUI_VIEW_CONNECTIONSTATUSLED_HPP

#include <QPixmap>

class QLabel;

namespace mui::view
{

class ConnectionStatusLed
{
public:
    ConnectionStatusLed() = delete;
    explicit ConnectionStatusLed(QLabel& label);
    virtual ~ConnectionStatusLed() = default;

    void setConnected();
    void setDisconnected();

protected:
    void setImage(const QString& filename);

private:
    QLabel& m_label;
    QPixmap m_pixmap;
    std::string m_logPrefix;
};

} // namespace mui::view

#endif // MUI_VIEW_CONNECTIONSTATUSLED_HPP
