cmake_minimum_required(VERSION 3.16)

project(DiffAlgoEval VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()
set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/resources/photosurface.rc")

qt_add_executable(DiffAlgoEval
    DiffAlgoEval.ui
    ${app_icon_resource_windows}
    main.cpp
)

target_link_libraries(DiffAlgoEval PRIVATE Qt6::Widgets)

set_target_properties(DiffAlgoEval PROPERTIES
    WIN32_EXECUTABLE ON
)

install(TARGETS DiffAlgoEval RUNTIME DESTINATION bin)