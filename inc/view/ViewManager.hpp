/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef VIEW_VIEWMANAGER_HPP
#define VIEW_VIEWMANAGER_HPP

#include <view/MainWindow.hpp>

#include <view/ConnectionButton.hpp>
#include <view/ConnectionStatusLed.hpp>
#include <view/ConnectionStatusText.hpp>

#include <ui_MainWindow.h>

#include <QObject>

#include <memory>

namespace view
{

class ViewManager : public QObject
{
    Q_OBJECT

public:
    ViewManager();

protected:
    void initSignals();

private:
    Ui::MainWindow m_uiMainWindow;
    MainWindow m_mainWindow;

    std::unique_ptr<ConnectionButton> m_button;
    std::unique_ptr<ConnectionStatusLed> m_led;
    std::unique_ptr<ConnectionStatusText> m_text;
};

}

#endif // VIEW_VIEWMANAGER_HPP
