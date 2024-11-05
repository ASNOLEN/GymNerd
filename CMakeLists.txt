cmake_minimum_required(VERSION 3.29)
project(GymNerd)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(UI_FILES
        mainwindow.ui
        userinfo.ui
        statscreen.ui
)

set(SRC_FILES
        gymnerds.cpp
        mainwindow.cpp
        userinfo.cpp
        statscreen.cpp
        calculations.cpp
        calculations.h
        BackgroundWidget.h
)

qt6_add_resources(RESOURCES resources.qrc)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${UI_FILES} ${RESOURCES})

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
