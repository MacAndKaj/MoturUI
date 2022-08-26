/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef VIEW_MAINWINDOW_HPP
#define VIEW_MAINWINDOW_HPP

#include <QMainWindow>

namespace view
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
};

} // namespace view

#endif // VIEW_MAINWINDOW_HPP
