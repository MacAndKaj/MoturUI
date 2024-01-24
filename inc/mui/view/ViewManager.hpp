/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef MUI_VIEW_VIEWMANAGER_HPP
#define MUI_VIEW_VIEWMANAGER_HPP

#include <mui/view/MainWindow.hpp>

#include <mui/view/AccessPointsComboBox.hpp>
#include <mui/view/ConnectionButton.hpp>
#include <mui/view/ConnectionStatusLed.hpp>
#include <mui/view/ConnectionStatusText.hpp>
#include <mui/view/UpdateAccessPointsButton.hpp>
#include <mui/view/ViewState.hpp>
#include <mui/interface/InterfaceManager.hpp>

#include <ui_MainWindow.h>

#include <QObject>

#include <memory>

namespace mui::view
{

class ViewManager : public QObject
{
    Q_OBJECT

public:
    explicit ViewManager(mui::interface::InterfaceManager& interface_manager);

protected:
    void initUiElementsControllers();
    void initSignals();
    void initCoreInterface();

private:
    Ui::MainWindow m_uiMainWindow;
    MainWindow m_mainWindow;
    mui::interface::InterfaceManager& m_interface_manager;
    ViewState m_current_state;

    std::unique_ptr<AccessPointsComboBox> m_access_points_combo_box;
    std::unique_ptr<ConnectionButton> m_connection_button;
    std::unique_ptr<UpdateAccessPointsButton> m_trigger_access_points_update_button;
    std::unique_ptr<ConnectionStatusLed> m_led;
    std::unique_ptr<ConnectionStatusText> m_text;
};

} // namespace mui::view

#endif // MUI_VIEW_VIEWMANAGER_HPP
