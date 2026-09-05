cmake_minimum_required(VERSION 3.10)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" PROJECT_NAME ${PROJECT_NAME})

project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)

set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "$<1:${CMAKE_CURRENT_SOURCE_DIR}/bin>")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/*.c)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}
)



if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  if(NOT MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE -g -O0 -Wall -Wextra -Wpedantic -ffreestanding)
    target_link_options(${PROJECT_NAME} PRIVATE -nostdlib -nodefaultlibs -nostartfiles)
  else()
    target_compile_options(${PROJECT_NAME} PRIVATE /Zi /O0 /W4)
    target_link_options(${PROJECT_NAME} PRIVATE /NODEFAULTLIB)
  endif()
else()
  if(NOT MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE -O3 -Wall -Wextra -Wpedantic -ffreestanding)
    target_link_options(${PROJECT_NAME} PRIVATE -nostdlib -nodefaultlibs -nostartfiles)
  else()
    target_compile_options(${PROJECT_NAME} PRIVATE /O3 /W4)
    target_link_options(${PROJECT_NAME} PRIVATE /NODEFAULTLIB)
  endif()
endif()
