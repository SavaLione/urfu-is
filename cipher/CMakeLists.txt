#################################################################################
# Copyright (c) 2021, Savely Pototsky (SavaLione)
# All rights reserved.
#################################################################################
# Checking the minimum version
cmake_minimum_required (VERSION 3.13.1)

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")               # default

#################################################################################
#                                       Options                                 #
#################################################################################
option(ISL_BUILD_STATIC_LIBRARY "Build static library" OFF)                     # Build static library

option(ISL_BUILD_ADDITIVE_PROJECT       "Build additive main test"       ON)    # Аддитивный шифр
option(ISL_BUILD_MULTIPLICATIVE_PROJECT "Build multiplicative main test" ON)    # Мультипликативный шифр
option(ISL_BUILD_AFFINE_PROJECT         "Build affine main test"         ON)    # Аффинный шифр
option(ISL_BUILD_AUTOKEY_PROJECT        "Build autokey main test"        ON)    # Автоключевой шифр
option(ISL_BUILD_PLAYFAIR_PROJECT       "Build playfair main test"       ON)    # Шифр Плейфера
option(ISL_BUILD_VIGENERE_PROJECT       "Build vigenere main test"       ON)    # Шифр Виженера
option(ISL_BUILD_HILL_PROJECT           "Build hill main test"           ON)    # Шифр Хилла
option(ISL_BUILD_TRANSPOSITION_PROJECT  "Build transposition main test"  ON)    # Шифр перестановки

#################################################################################
#                               Macros and functions                            #
#################################################################################
# Output directory
macro(isl_out arg_project)
    set_target_properties(${${arg_project}}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # exec
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # runtime
    )
endmacro(isl_out)

# make executable
macro(isl_executable arg_project arg_sources)
    add_executable(${${arg_project}} ${${arg_sources}})
    target_include_directories(${${arg_project}} PUBLIC ${PROJECT_SOURCE_DIR}/src)
endmacro(isl_executable)

# include cipher library
macro(isl_library_include arg_project)
    target_link_libraries(${${arg_project}} ${ISL_CIPHER_LIBRARY})
    target_include_directories(${${arg_project}} PUBLIC ${PROJECT_SOURCE_DIR}/include)
endmacro(isl_library_include)

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
isl_create_project(ISL_CIPHER_LIBRARY         "cipher"           "0.0.1")   # Библиотека cipher

isl_create_project(ISL_ADDITIVE_PROJECT       "1_additive"       "0.0.1")   # Аддитивный шифр
isl_create_project(ISL_MULTIPLICATIVE_PROJECT "2_multiplicative" "0.0.1")   # Мультипликативный шифр
isl_create_project(ISL_AFFINE_PROJECT         "3_affine"         "0.0.1")   # Аффинный шифр
isl_create_project(ISL_AUTOKEY_PROJECT        "4_autokey"        "0.0.1")   # Автоключевой шифр
isl_create_project(ISL_PLAYFAIR_PROJECT       "5_playfair"       "0.0.1")   # Шифр Плейфера
isl_create_project(ISL_VIGENERE_PROJECT       "6_vigenere"       "0.0.1")   # Шифр Виженера
isl_create_project(ISL_HILL_PROJECT           "7_hill"           "0.0.1")   # Шифр Хилла
isl_create_project(ISL_TRANSPOSITION_PROJECT  "8_transposition"  "0.0.1")   # Шифр перестановки

#################################################################################
#                                     Sources                                   #
#################################################################################
# cipher library sources
set(ISL_CIPHER_LIBRARY_SRC
    src/cipher/additive.cpp
    src/cipher/multiplicative.cpp
    src/cipher/affine.cpp
    src/cipher/autokey.cpp
    src/cipher/playfair.cpp
    src/cipher/vigenere.cpp
    src/cipher/hill.cpp
    src/cipher/transposition.cpp
    src/cipher/key.cpp
)

### apps 1 - 8
set(ISL_CIPHER_ADDITIVE_SRC_MAIN       test/additive_main.cpp)
set(ISL_CIPHER_MULTIPLICATIVE_SRC_MAIN test/multiplicative_main.cpp)
set(ISL_CIPHER_AFFINE_SRC_MAIN         test/affine_main.cpp)
set(ISL_CIPHER_AUTOKEY_SRC_MAIN        test/autokey_main.cpp)
set(ISL_CIPHER_PLAYFAIR_SRC_MAIN       test/playfair_main.cpp)
set(ISL_CIPHER_VIGENERE_SRC_MAIN       test/vigenere_main.cpp)
set(ISL_CIPHER_HILL_SRC_MAIN           test/hill_main.cpp)
set(ISL_CIPHER_TRANSPOSITION_SRC_MAIN  test/transposition_main.cpp)

#################################################################################
#                                     Library                                   #
#################################################################################
# Библиотека cipher
if(ISL_BUILD_STATIC_LIBRARY)
    add_library(${ISL_CIPHER_LIBRARY} STATIC ${ISL_CIPHER_LIBRARY_SRC})
else()
    add_library(${ISL_CIPHER_LIBRARY} SHARED ${ISL_CIPHER_LIBRARY_SRC})
endif()

target_include_directories(${ISL_CIPHER_LIBRARY} PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(${ISL_CIPHER_LIBRARY} PUBLIC ${PROJECT_SOURCE_DIR}/include)

#################################################################################
#                                     Executable                                #
#################################################################################
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
isl_library_include(ISL_ADDITIVE_PROJECT)                                       # Подключаем к "Аддитивный шифр" библиотеку cipher
isl_library_include(ISL_MULTIPLICATIVE_PROJECT)                                 # Подключаем к "Мультипликативный шифр" библиотеку cipher
isl_library_include(ISL_AFFINE_PROJECT)                                         # Подключаем к "Аффинный шифр" библиотеку cipher
isl_library_include(ISL_AUTOKEY_PROJECT)                                        # Подключаем к "Автоключевой шифр" библиотеку cipher
isl_library_include(ISL_PLAYFAIR_PROJECT)                                       # Подключаем к "Шифр Плейфера" библиотеку cipher
isl_library_include(ISL_VIGENERE_PROJECT)                                       # Подключаем к "Шифр Виженера" библиотеку cipher
isl_library_include(ISL_HILL_PROJECT)                                           # Подключаем к "Шифр Хилла" библиотеку cipher
isl_library_include(ISL_TRANSPOSITION_PROJECT)                                  # Подключаем к "Шифр перестановки" библиотеку cipher

#################################################################################
#                                 Output directory                              #
#################################################################################
isl_out(ISL_CIPHER_LIBRARY)
isl_out(ISL_ADDITIVE_PROJECT)
isl_out(ISL_MULTIPLICATIVE_PROJECT)
isl_out(ISL_AFFINE_PROJECT)
isl_out(ISL_AUTOKEY_PROJECT)
isl_out(ISL_PLAYFAIR_PROJECT)
isl_out(ISL_VIGENERE_PROJECT)
isl_out(ISL_HILL_PROJECT)
isl_out(ISL_TRANSPOSITION_PROJECT)