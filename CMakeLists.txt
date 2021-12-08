#################################################################################
# Copyright (c) 2021, Savely Pototsky (SavaLione)
# All rights reserved.
#################################################################################
# Checking the minimum version
cmake_minimum_required (VERSION 3.13.1)

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")               # default

#################################################################################
#                               Macros and functions                            #
#################################################################################
# Output directory
function(isl_out arg_project)
    set_target_properties(${arg_project}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endfunction(isl_out)

# make executable
macro(isl_executable arg_project arg_sources)
    add_executable(${${arg_project}} ${${arg_sources}})
    target_include_directories(${${arg_project}} PUBLIC ${PROJECT_SOURCE_DIR}/src)
endmacro(isl_executable)

# create project
macro(isl_create_project arg_project arg_project_name arg_project_version)
    set(${arg_project} ${arg_project_name})
    set(${arg_project}_VERSION ${arg_project_version})
    project(${${arg_project}}
        VERSION ${${arg_project}_VERSION}
        LANGUAGES CXX
    )
endmacro(isl_create_project)

#################################################################################
#                                     Projects                                  #
#################################################################################
isl_create_project(ISL_GUI_PROJECT            "0_gui"            "0.0.1")       # Графическое приложение со всеми шифрами

#################################################################################
#                                    Libraries                                  #
#################################################################################
# OpenGL
find_package(OpenGL REQUIRED)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

set(GLFW_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/glfw/include" CACHE PATH "GLFW lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glfw)

# imgui
set(IMGUI_BUILD_BACKEND_OPENGL3 ON CACHE BOOL "" FORCE)
set(IMGUI_BUILD_BACKEND_GLFW ON CACHE BOOL "" FORCE)

set(IMGUI_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/imgui/include" CACHE PATH "imgui lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/imgui)

# spdlog
set(SPDLOG_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/spdlog/include" CACHE PATH "spdlog lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/spdlog)

# cipher
set(CIPHER_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/cipher/include" CACHE PATH "cipher lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/cipher)

#################################################################################
#                                     Sources                                   #
#################################################################################
# core
set(ISL_CORE_SRC
    src/core/compiler_version.h
    src/core/compiler_version.cpp
    src/core/isl.h
    src/core/isl.cpp
    src/core/settings.h
    src/core/settings.cpp
)

# gui
set(ISL_GUI_SRC
    src/gui/gui.h
    src/gui/gui.cpp
    src/gui/imgui_stdlib.h
    src/gui/imgui_stdlib.cpp
)

# io
set(ISL_IO_SRC
    src/io/logger.h
    src/io/logger.cpp
)

# isl gui main application
set(ISL_SRC
    ${ISL_CORE_SRC}
    ${ISL_GUI_SRC}
    ${ISL_IO_SRC}
)

#################################################################################
#                                     Executable                                #
#################################################################################
isl_executable(ISL_GUI_PROJECT            ISL_SRC)                              # Графическое приложение со всеми шифрами

#################################################################################
#                                Libraries include                              #
#################################################################################
# OpenGL
target_link_libraries(${ISL_GUI_PROJECT} ${OPENGL_gl_LIBRARY})
target_include_directories(${ISL_GUI_PROJECT} PUBLIC ${OPENGL_INCLUDE_DIR})

# GLFW
target_link_libraries(${ISL_GUI_PROJECT} glfw)
target_include_directories(${ISL_GUI_PROJECT} PUBLIC ${GLFW_INCLUDE_DIR})

# imgui
target_link_libraries(${ISL_GUI_PROJECT} imgui imgui_glfw imgui_opengl3)
target_include_directories(${ISL_GUI_PROJECT} PUBLIC ${IMGUI_INCLUDE_DIR})

# spdlog
target_link_libraries(${ISL_GUI_PROJECT} spdlog)
target_include_directories(${ISL_GUI_PROJECT} PUBLIC ${SPDLOG_INCLUDE_DIR})

# cipher
target_link_libraries(${ISL_GUI_PROJECT} cipher)
target_include_directories(${ISL_GUI_PROJECT} PUBLIC ${CIPHER_INCLUDE_DIR})

#################################################################################
#                                 Output directory                              #
#################################################################################
isl_out(glfw)                           # Библиотека glfw
isl_out(imgui)                          # Библиотека imgui
isl_out(imgui_glfw)                     # Библиотека imgui_glfw
isl_out(imgui_opengl3)                  # Библиотека imgui_opengl3
isl_out(spdlog)                         # Библиотека spdlog
isl_out(cipher)                         # Библиотека cipher
isl_out(ISL_GUI_PROJECT)                # Графическое приложение