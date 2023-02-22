cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(test
        LANGUAGES CXX C)

add_executable(${PROJECT_NAME}
    test.cpp
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD ${CMAKE_CXX_STANDARD})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_${CMAKE_CXX_STANDARD})

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wc++20-compat-pedantic>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W3 /wd4251>)

target_link_libraries(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/bgfx/.build/libbgfxDebug.a
    ${CMAKE_SOURCE_DIR}/bgfx/.build/libbxDebug.a
    ${CMAKE_SOURCE_DIR}/bgfx/.build/libbimgDebug.a
    ${CMAKE_SOURCE_DIR}/bgfx/.build/libbimg_decodeDebug.a
    ${CMAKE_SOURCE_DIR}/bgfx/.build/libbimg_encodeDebug.a
    dl
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_SOURCE_DIR}/bgfx/include
        ${CMAKE_SOURCE_DIR}/bx/include
        ${CMAKE_SOURCE_DIR}/bimg/include
)