cmake_minimum_required(VERSION 3.10)

project(Interact LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Interact SHARED
    "include/Offsets.h"
    "include/Game.h"
    "src/Game.cpp"
    "src/dllmain.cpp"
)

target_include_directories(Interact PUBLIC ${PROJECT_SOURCE_DIR}/include )

find_package(minhook CONFIG REQUIRED)

target_link_libraries(Interact PRIVATE minhook::minhook)

target_compile_definitions(Interact PRIVATE $<$<CONFIG:Debug>:DEBUG_MODE> $<$<CONFIG:Release>:NDEBUG> )

if(MSVC)
    target_compile_options(Interact PRIVATE /W3)
else()
    target_compile_options(Interact PRIVATE -Wall -Wextra)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O1")
set_property(TARGET Interact PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")