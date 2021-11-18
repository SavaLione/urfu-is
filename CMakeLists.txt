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
isl_create_project(ISL_GUI_PROJECT            "0_gui"            "0.0.1")   # Графическое приложение со всеми шифрами
isl_create_project(ISL_ADDITIVE_PROJECT       "1_additive"       "0.0.1")   # Аддитивный шифр
isl_create_project(ISL_MULTIPLICATIVE_PROJECT "2_multiplicative" "0.0.1")   # Мультипликативный шифр
isl_create_project(ISL_AFFINE_PROJECT         "3_affine"         "0.0.1")   # Аффинный шифр
isl_create_project(ISL_AUTOKEY_PROJECT        "4_autokey"        "0.0.1")   # Автоключевой шифр
isl_create_project(ISL_PLAYFAIR_PROJECT       "5_playfair"       "0.0.1")   # Шифр Плейфера
isl_create_project(ISL_VIGENERE_PROJECT       "6_vigenere"       "0.0.1")   # Шифр Виженера
isl_create_project(ISL_HILL_PROJECT           "7_hill"           "0.0.1")   # Шифр Хилла
isl_create_project(ISL_TRANSPOSITION_PROJECT  "8_transposition"  "0.0.1")   # Шифр перестановки


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

#################################################################################
#                                     Sources                                   #
#################################################################################
# cipher additive
set(ISL_CIPHER_ADDITIVE_SRC
    src/cipher/additive/additive.h
    src/cipher/additive/additive.cpp
)

# cipher multiplicative
set(ISL_CIPHER_MULTIPLICATIVE_SRC
    src/cipher/multiplicative/multiplicative.h
    src/cipher/multiplicative/multiplicative.cpp
)

# cipher affine
set(ISL_CIPHER_AFFINE_SRC
    src/cipher/affine/affine.h
    src/cipher/affine/affine.cpp
)

# cipher autokey
set(ISL_CIPHER_AUTOKEY_SRC
    src/cipher/autokey/autokey.h
    src/cipher/autokey/autokey.cpp
)

# cipher playfair
set(ISL_CIPHER_PLAYFAIR_SRC
    src/cipher/playfair/playfair.h
    src/cipher/playfair/playfair.cpp
)

# cipher vigenere
set(ISL_CIPHER_VIGENERE_SRC
    src/cipher/vigenere/vigenere.h
    src/cipher/vigenere/vigenere.cpp
)

# cipher hill
set(ISL_CIPHER_HILL_SRC
    src/cipher/hill/hill.h
    src/cipher/hill/hill.cpp
)

# cipher transposition
set(ISL_CIPHER_TRANSPOSITION_SRC
    src/cipher/transposition/transposition.h
    src/cipher/transposition/transposition.cpp
)

# ciphers
set(ISL_CIPHER_SRC
    ${ISL_CIPHER_ADDITIVE_SRC}
    ${ISL_CIPHER_MULTIPLICATIVE_SRC}
    ${ISL_CIPHER_AFFINE_SRC}
    ${ISL_CIPHER_AUTOKEY_SRC}
    ${ISL_CIPHER_PLAYFAIR_SRC}
    ${ISL_CIPHER_VIGENERE_SRC}
    ${ISL_CIPHER_HILL_SRC}
    ${ISL_CIPHER_TRANSPOSITION_SRC}
)

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
    ${ISL_CIPHER_SRC}
    ${ISL_CORE_SRC}
    ${ISL_GUI_SRC}
    ${ISL_IO_SRC}
)

### apps 1 - 8
set(ISL_CIPHER_ADDITIVE_SRC_MAIN       src/cipher/additive/additive_main.cpp             ${ISL_CIPHER_ADDITIVE_SRC})
set(ISL_CIPHER_MULTIPLICATIVE_SRC_MAIN src/cipher/multiplicative/multiplicative_main.cpp ${ISL_CIPHER_MULTIPLICATIVE_SRC})
set(ISL_CIPHER_AFFINE_SRC_MAIN         src/cipher/affine/affine_main.cpp                 ${ISL_CIPHER_AFFINE_SRC})
set(ISL_CIPHER_AUTOKEY_SRC_MAIN        src/cipher/autokey/autokey_main.cpp               ${ISL_CIPHER_AUTOKEY_SRC})
set(ISL_CIPHER_PLAYFAIR_SRC_MAIN       src/cipher/playfair/playfair_main.cpp             ${ISL_CIPHER_PLAYFAIR_SRC})
set(ISL_CIPHER_VIGENERE_SRC_MAIN       src/cipher/vigenere/vigenere_main.cpp             ${ISL_CIPHER_VIGENERE_SRC})
set(ISL_CIPHER_HILL_SRC_MAIN           src/cipher/hill/hill_main.cpp                     ${ISL_CIPHER_HILL_SRC})
set(ISL_CIPHER_TRANSPOSITION_SRC_MAIN  src/cipher/transposition/transposition_main.cpp   ${ISL_CIPHER_TRANSPOSITION_SRC})

#################################################################################
#                                     Executable                                #
#################################################################################
isl_executable(ISL_GUI_PROJECT            ISL_SRC)                              # Графическое приложение со всеми шифрами
isl_executable(ISL_ADDITIVE_PROJECT       ISL_CIPHER_ADDITIVE_SRC_MAIN)         # Аддитивный шифр
isl_executable(ISL_MULTIPLICATIVE_PROJECT ISL_CIPHER_MULTIPLICATIVE_SRC_MAIN)   # Мультипликативный шифр
isl_executable(ISL_AFFINE_PROJECT         ISL_CIPHER_AFFINE_SRC_MAIN)           # Аффинный шифр
isl_executable(ISL_AUTOKEY_PROJECT        ISL_CIPHER_AUTOKEY_SRC_MAIN)          # Автоключевой шифр
isl_executable(ISL_PLAYFAIR_PROJECT       ISL_CIPHER_PLAYFAIR_SRC_MAIN)         # Шифр Плейфера
isl_executable(ISL_VIGENERE_PROJECT       ISL_CIPHER_VIGENERE_SRC_MAIN)         # Шифр Виженера
isl_executable(ISL_HILL_PROJECT           ISL_CIPHER_HILL_SRC_MAIN)             # Шифр Хилла
isl_executable(ISL_TRANSPOSITION_PROJECT  ISL_CIPHER_TRANSPOSITION_SRC_MAIN)    # Шифр перестановки

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

#################################################################################
#                                 Output directory                              #
#################################################################################
isl_out(${ISL_ADDITIVE_PROJECT})        # Аддитивный шифр
isl_out(${ISL_MULTIPLICATIVE_PROJECT})  # Мультипликативный шифр
isl_out(${ISL_AFFINE_PROJECT})          # Аффинный шифр
isl_out(${ISL_AUTOKEY_PROJECT})         # Автоключевой шифр
isl_out(${ISL_PLAYFAIR_PROJECT})        # Шифр Плейфера
isl_out(${ISL_VIGENERE_PROJECT})        # Шифр Виженера
isl_out(${ISL_HILL_PROJECT})            # Шифр Хилла
isl_out(${ISL_TRANSPOSITION_PROJECT})   # Шифр перестановки
isl_out(${ISL_GUI_PROJECT})             # Графическое приложение со всеми шифрами