/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MUI_VIEW_UPDATEACCESSPOINTSBUTTON_HPP
#define MUI_VIEW_UPDATEACCESSPOINTSBUTTON_HPP

#include <QObject>

class QPushButton;

namespace mui::view
{

class UpdateAccessPointsButton : public QObject
{
    Q_OBJECT

public:
    UpdateAccessPointsButton() = delete;
    explicit UpdateAccessPointsButton(QPushButton& button);
    virtual ~UpdateAccessPointsButton() = default;

signals:
    void triggerUpdateAccessPoints();

private:
    QPushButton& m_button;
};

} // namespace mui::view

#endif // MUI_VIEW_UPDATEACCESSPOINTSBUTTON_HPP
