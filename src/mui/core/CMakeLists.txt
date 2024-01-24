project(MOTURUI_CORE_INTERFACES)

set(MOTURUI_CORE_INTERFACE_FILES
    ${MOTORUI_HEADERS}/mui/core/ICore.hpp

    ${MOTORUI_HEADERS}/mui/core/connection/IDBusBuilder.hpp
)

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} 
    INTERFACE ${MOTURUI_CORE_INTERFACE_FILES}
)

target_link_libraries(${PROJECT_NAME} INTERFACE Qt${QT_VERSION_MAJOR}::DBus)

target_include_directories(${PROJECT_NAME} INTERFACE ${MOTORUI_HEADERS})

#######################################################################


project(MOTURUI_CORE)

file(GLOB MOTURUI_CORE_SOURCES 
    #HEADERS
    ${MOTORUI_HEADERS}/mui/core/Core.hpp

    ${MOTORUI_HEADERS}/mui/core/connection/ConnectionManager.hpp
    ${MOTORUI_HEADERS}/mui/core/connection/DBusBuilder.hpp
    ${MOTORUI_HEADERS}/mui/core/connection/NetworkManagerProxy.hpp

    #SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Core.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/connection/ConnectionManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/connection/DBusBuilder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/connection/NetworkManagerProxy.cpp
)

set_property(SOURCE ${MOTURUI_CORE_SOURCES} PROPERTY SKIP_AUTOMOC ON)

add_library(${PROJECT_NAME} ${MOTURUI_CORE_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${MOTORUI_HEADERS}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE MOTURUI_CORE_INTERFACES
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE Qt${QT_VERSION_MAJOR}::DBus
)
