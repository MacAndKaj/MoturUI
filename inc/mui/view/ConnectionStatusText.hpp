/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef MUI_VIEW_CONNECTIONSTATUSTEXT_HPP
#define MUI_VIEW_CONNECTIONSTATUSTEXT_HPP

class QLabel;

namespace mui::view
{

class ConnectionStatusText
{
public:
    ConnectionStatusText() = delete;
    explicit ConnectionStatusText(QLabel& label);

    void setConnected();
    void setDisconnected();
    void setConnectingInProgress();

private:
    QLabel& m_label;
};

} // namespace mui::view

#endif // MUI_VIEW_CONNECTIONSTATUSTEXT_HPP
