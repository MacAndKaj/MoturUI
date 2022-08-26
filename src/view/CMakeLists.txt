set(LIB_NAME ${APP_LIB_PREFIX}_VIEW)

add_library(${LIB_NAME}
    # HEADER
    ${MOTORUI_HEADERS}/view/ConnectionButton.hpp
    ${MOTORUI_HEADERS}/view/ConnectionStatusLed.hpp
    ${MOTORUI_HEADERS}/view/ConnectionStatusText.hpp
    ${MOTORUI_HEADERS}/view/MainWindow.hpp
    ${MOTORUI_HEADERS}/view/ViewManager.hpp

    # SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionButton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionStatusLed.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionStatusText.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ViewManager.cpp
)

target_include_directories(${LIB_NAME} PUBLIC
    ${MOTORUI_HEADERS}
)

target_link_libraries(${LIB_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)
