#################################################################################
# Copyright (c) 2021, Savely Pototsky (SavaLione)
# All rights reserved.
#################################################################################
# Checking the minimum version
cmake_minimum_required (VERSION 3.13.1)

# Шифры
#   + Аддитивный шифр
#   + Мультипликативный шифр
#   + Аффинный шифр
#   * Автоключевой шифр
#   * Плейфера
#   * Виженера
#   * Хила
#   Шифр перестановки

# Аддитивный шифр
set(ISL_ADDITIVE_PROJECT "1_additive")
set(ISL_ADDITIVE_PROJECT_VERSION "0.0.1")
project(${ISL_ADDITIVE_PROJECT}
    VERSION ${ISL_ADDITIVE_PROJECT_VERSION}
    LANGUAGES CXX
)

# Мультипликативный шифр
set(ISL_MULTIPLICATIVE_PROJECT "2_multiplicative")
set(ISL_MULTIPLICATIVE_PROJECT_VERSION "0.0.1")
project(${ISL_MULTIPLICATIVE_PROJECT}
    VERSION ${ISL_MULTIPLICATIVE_PROJECT_VERSION}
    LANGUAGES CXX
)

# Аффинный шифр
set(ISL_AFFINE_PROJECT "3_affine")
set(ISL_AFFINE_PROJECT_VERSION "0.0.1")
project(${ISL_AFFINE_PROJECT}
    VERSION ${ISL_AFFINE_PROJECT_VERSION}
    LANGUAGES CXX
)

# Автоключевой шифр
set(ISL_AUTOKEY_PROJECT "4_autokey")
set(ISL_AUTOKEY_PROJECT_VERSION "0.0.1")
project(${ISL_AUTOKEY_PROJECT}
    VERSION ${ISL_AUTOKEY_PROJECT_VERSION}
    LANGUAGES CXX
)

# Шифр Плейфера
set(ISL_PLAYFAIR_PROJECT "5_playfair")
set(ISL_PLAYFAIR_PROJECT_VERSION "0.0.1")
project(${ISL_PLAYFAIR_PROJECT}
    VERSION ${ISL_PLAYFAIR_PROJECT_VERSION}
    LANGUAGES CXX
)

# Шифр Виженера
set(ISL_VIGENERE_PROJECT "6_vigenere")
set(ISL_VIGENERE_PROJECT_VERSION "0.0.1")
project(${ISL_VIGENERE_PROJECT}
    VERSION ${ISL_VIGENERE_PROJECT_VERSION}
    LANGUAGES CXX
)

# Шифр Хилла
set(ISL_HILL_PROJECT "7_hill")
set(ISL_HILL_PROJECT_VERSION "0.0.1")
project(${ISL_HILL_PROJECT}
    VERSION ${ISL_HILL_PROJECT_VERSION}
    LANGUAGES CXX
)

# Шифр перестановки
set(ISL_TRANSPOSITION_PROJECT "8_transposition")
set(ISL_TRANSPOSITION_PROJECT_VERSION "0.0.1")
project(${ISL_TRANSPOSITION_PROJECT}
    VERSION ${ISL_TRANSPOSITION_PROJECT_VERSION}
    LANGUAGES CXX
)

# Графическое приложение со всеми шифрами
set(ISL_GUI_PROJECT "0_gui")
set(ISL_GUI_PROJECT_VERSION "0.0.1")
project(${ISL_GUI_PROJECT}
    VERSION ${ISL_GUI_PROJECT_VERSION}
    LANGUAGES CXX
)

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


#################################################################################
#                                     Sources                                   #
#################################################################################

### Аддитивный шифр ###
# Core
set(ISL_ADDITIVE_CORE_SRC
    src/core/additive_main.cpp
    src/core/additive.cpp
    src/core/additive.h
)

# Sources
set(ISL_ADDITIVE_SRC
    ${ISL_ADDITIVE_CORE_SRC}
)

# executable
add_executable(${ISL_ADDITIVE_PROJECT} ${ISL_ADDITIVE_SRC})
target_include_directories(${ISL_ADDITIVE_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

### Мультипликативный шифр ###
# Core
set(ISL_MULTIPLICATIVE_CORE_SRC
    src/core/multiplicative_main.cpp
    src/core/multiplicative.cpp
    src/core/multiplicative.h
)

# Sources
set(ISL_MULTIPLICATIVE_SRC
    ${ISL_MULTIPLICATIVE_CORE_SRC}
)

# executable
add_executable(${ISL_MULTIPLICATIVE_PROJECT} ${ISL_MULTIPLICATIVE_SRC})
target_include_directories(${ISL_MULTIPLICATIVE_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

### Аффинный шифр ###
# Core
set(ISL_AFFINE_CORE_SRC
    src/core/affine_main.cpp
    src/core/affine.cpp
    src/core/affine.h
)

# Sources
set(ISL_AFFINE_SRC
    ${ISL_AFFINE_CORE_SRC}
)

# executable
add_executable(${ISL_AFFINE_PROJECT} ${ISL_AFFINE_SRC})
target_include_directories(${ISL_AFFINE_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

### Автоключевой шифр ###
# Core
set(ISL_AUTOKEY_CORE_SRC
    src/core/autokey_main.cpp
    src/core/autokey.cpp
    src/core/autokey.h
)

# Sources
set(ISL_AUTOKEY_SRC
    ${ISL_AUTOKEY_CORE_SRC}
)

# executable
add_executable(${ISL_AUTOKEY_PROJECT} ${ISL_AUTOKEY_SRC})
target_include_directories(${ISL_AUTOKEY_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

### Шифр Плейфера ###
# Core
set(ISL_PLAYFAIR_CORE_SRC
    src/core/playfair_main.cpp
    src/core/playfair.cpp
    src/core/playfair.h
)

# Sources
set(ISL_PLAYFAIR_SRC
    ${ISL_PLAYFAIR_CORE_SRC}
)

# executable
add_executable(${ISL_PLAYFAIR_PROJECT} ${ISL_PLAYFAIR_SRC})
target_include_directories(${ISL_PLAYFAIR_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

### Шифр Виженера ###
# Core
set(ISL_VIGENERE_CORE_SRC
    src/core/vigenere_main.cpp
    src/core/vigenere.cpp
    src/core/vigenere.h
)

# Sources
set(ISL_VIGENERE_SRC
    ${ISL_VIGENERE_CORE_SRC}
)

# executable
add_executable(${ISL_VIGENERE_PROJECT} ${ISL_VIGENERE_SRC})
target_include_directories(${ISL_VIGENERE_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

### Шифр Хилла ###
# Core
set(ISL_HILL_CORE_SRC
    src/core/hill_main.cpp
    src/core/hill.cpp
    src/core/hill.h
)

# Sources
set(ISL_HILL_SRC
    ${ISL_HILL_CORE_SRC}
)

# executable
add_executable(${ISL_HILL_PROJECT} ${ISL_HILL_SRC})
target_include_directories(${ISL_HILL_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

### Шифр перестановки ###
# Core
set(ISL_TRANSPOSITION_CORE_SRC
    src/core/transposition_main.cpp
    src/core/transposition.cpp
    src/core/transposition.h
)

# Sources
set(ISL_TRANSPOSITION_SRC
    ${ISL_TRANSPOSITION_CORE_SRC}
)

# executable
add_executable(${ISL_TRANSPOSITION_PROJECT} ${ISL_TRANSPOSITION_SRC})
target_include_directories(${ISL_TRANSPOSITION_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

### Графическое приложение со всеми шифрами ###
# Core
set(ISL_GUI_CORE_SRC
    src/core/gui_main.cpp
    src/core/gui_main.h
    src/core/gui.cpp
    src/core/gui.h
    src/core/additive.cpp
    src/core/additive.h
    src/core/multiplicative.cpp
    src/core/multiplicative.h
    src/core/affine.cpp
    src/core/affine.h
    src/core/autokey.cpp
    src/core/autokey.h
    src/core/playfair.cpp
    src/core/playfair.h
    src/core/vigenere.cpp
    src/core/vigenere.h
    src/core/hill.cpp
    src/core/hill.h
    src/core/transposition.cpp
    src/core/transposition.h
)

# Sources
set(ISL_GUI_SRC
    ${ISL_GUI_CORE_SRC}
)

# executable
add_executable(${ISL_GUI_PROJECT} ${ISL_GUI_SRC})
target_include_directories(${ISL_GUI_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

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