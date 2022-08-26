/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef VIEW_CONNECTIONSTATUSTEXT_HPP
#define VIEW_CONNECTIONSTATUSTEXT_HPP

class QLabel;

namespace view
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

} // namespace view

#endif // VIEW_CONNECTIONSTATUSTEXT_HPP
