#################################################################################
# Copyright (c) 2021, Savely Pototsky (SavaLione)
# All rights reserved.
#################################################################################
# Checking the minimum version
cmake_minimum_required (VERSION 3.13.1)

# Шифры
#   Аддитивный шифр
#   Мультипликативный шифр
#   Аффинный шифр
#   Автоключевой шифр
#   Плейфера
#   Бишера
#   Хила
#   Шифр перестановки

# Аддитивный шифр
set(ISL_ADDITIVE_PROJECT "1_additive")
set(ISL_ADDITIVE_PROJECT_VERSION "0.0.1")
project(${ISL_ADDITIVE_PROJECT}
    VERSION ${ISL_ADDITIVE_PROJECT_VERSION}
    LANGUAGES CXX
)

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")               # default
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g")           # debug

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

#################################################################################
#                                 Output directory                              #
#################################################################################

### Аддитивный шифр ###
set_target_properties(${ISL_ADDITIVE_PROJECT}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

