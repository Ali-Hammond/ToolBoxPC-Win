cmake_minimum_required(VERSION 3.16)

project(ToolBoxPC-Win VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    cpuusage.cpp    # Ensure cpuusage.cpp is included
    cpuusage.h      # Ensure cpuusage.h is included
    gpuusage.cpp    # Ensure gpuusage.cpp is included
    gpuusage.h      # Ensure gpuusage.h is included
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ToolBoxPC-Win
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(ToolBoxPC-Win
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(ToolBoxPC-Win PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Finalize the executable if Qt version is 6
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ToolBoxPC-Win)
endif()

set_target_properties(ToolBoxPC-Win PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Link required libraries
target_link_libraries(ToolBoxPC-Win PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    d3d11.lib
    dxgi.lib
    wbemuuid
    ole32
    comsupp.lib
)

include(GNUInstallDirs)
install(TARGETS ToolBoxPC-Win
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(CMAKE_GENERATOR_PLATFORM x64)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ToolBoxPC-Win)
endif()
