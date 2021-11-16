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
#   Автоключевой шифр
#   Плейфера
#   * Виженера
#   Хила
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

# Шифр Хилла
set(ISL_HILL_PROJECT "7_hill")
set(ISL_HILL_PROJECT_VERSION "0.0.1")
project(${ISL_HILL_PROJECT}
    VERSION ${ISL_HILL_PROJECT_VERSION}
    LANGUAGES CXX
)

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")               # default
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g")           # debug

#################################################################################
#                                    Libraries                                  #
#################################################################################

# Eigen3
#set(EIGEN_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/imgui/include" CACHE PATH "imgui lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/eigen)

#find_package (Eigen3 REQUIRED NO_MODULE)

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
target_link_libraries(${ISL_HILL_PROJECT} Eigen3::Eigen)

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

### Мультипликативный шифр ###
set_target_properties(${ISL_MULTIPLICATIVE_PROJECT}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

### Аффинный шифр ###
set_target_properties(${ISL_AFFINE_PROJECT}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

### Хилл шифр ###
set_target_properties(${ISL_HILL_PROJECT}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)