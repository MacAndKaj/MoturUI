/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef MUI_VIEW_MAINWINDOW_HPP
#define MUI_VIEW_MAINWINDOW_HPP

#include <QMainWindow>

namespace mui::view
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() = default;
};

} // namespace mui::view

#endif // MUI_VIEW_MAINWINDOW_HPP
