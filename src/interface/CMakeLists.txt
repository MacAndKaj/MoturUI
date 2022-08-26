set(LIB_NAME ${APP_LIB_PREFIX}_INTERFACE)

add_library(${LIB_NAME}
    #HEADERS
    ${MOTORUI_HEADERS}/interface/ICommand.hpp
    ${MOTORUI_HEADERS}/interface/InterfaceManager.hpp

    #SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/InterfaceManager.cpp
)

target_include_directories(${LIB_NAME} PUBLIC
    ${MOTORUI_HEADERS}
    ${MOTORUI_AUTOGEN_HEADERS}
    ${MOTORUI_FORMS_HEADERS}
)

target_link_libraries(${LIB_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)
