project(MOTURUI_VIEW)

add_library(${PROJECT_NAME}
    # HEADER
    ${MOTORUI_HEADERS}/mui/view/AccessPointsComboBox.hpp
    ${MOTORUI_HEADERS}/mui/view/ConnectionButton.hpp
    ${MOTORUI_HEADERS}/mui/view/ConnectionStatusLed.hpp
    ${MOTORUI_HEADERS}/mui/view/ConnectionStatusText.hpp
    ${MOTORUI_HEADERS}/mui/view/MainWindow.hpp
    ${MOTORUI_HEADERS}/mui/view/UpdateAccessPointsButton.hpp
    ${MOTORUI_HEADERS}/mui/view/ViewManager.hpp
    ${MOTORUI_HEADERS}/mui/view/ViewState.hpp

    # SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/AccessPointsComboBox.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionButton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionStatusLed.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionStatusText.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UpdateAccessPointsButton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ViewManager.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${MOTORUI_HEADERS}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE MOTURUI_INTERFACE
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
)
