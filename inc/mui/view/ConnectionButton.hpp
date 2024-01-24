/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef MUI_VIEW_CONNECTIONBUTTON_HPP
#define MUI_VIEW_CONNECTIONBUTTON_HPP

#include <QObject>

class QPushButton;

namespace mui::view
{

class ConnectionButton : public QObject
{
    Q_OBJECT

public:
    ConnectionButton() = delete;
    explicit ConnectionButton(QPushButton& button);
    virtual ~ConnectionButton() = default;

    void setConnectText();
    void setDisconnectText();

signals:
    void connectButtonClicked();

private:
    QPushButton& m_button;
};

} // namespace mui::view

#endif // MUI_VIEW_CONNECTIONBUTTON_HPP
