/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef VIEW_CONNECTIONBUTTON_HPP
#define VIEW_CONNECTIONBUTTON_HPP

class QPushButton;

namespace view
{

class ConnectionButton
{
public:
    ConnectionButton() = delete;
    explicit ConnectionButton(QPushButton& button);
    virtual ~ConnectionButton() = default;

    void setConnectText();
    void setDisconnectText();

private:
    QPushButton& m_button;
};

} // namespace view

#endif // VIEW_CONNECTIONBUTTON_HPP
