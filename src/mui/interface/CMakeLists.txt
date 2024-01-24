project(MOTURUI_INTERFACE)

file(GLOB MOTURUI_INTERFACE_SOURCES 
    #HEADERS
    ${MOTORUI_HEADERS}/mui/interface/CoreCallbacks.hpp
    ${MOTORUI_HEADERS}/mui/interface/InterfaceManager.hpp
    ${MOTORUI_HEADERS}/mui/interface/ViewCallbacks.hpp

    #SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/InterfaceManager.cpp
)

set_property(SOURCE ${MOTURUI_INTERFACE_SOURCES} PROPERTY SKIP_AUTOMOC ON)

add_library(${PROJECT_NAME} ${MOTURUI_INTERFACE_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${MOTORUI_HEADERS}
)
