## Conpiler configuration

cmake_minimum_required(VERSION 3.22.2 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


## Path settings

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dist)
set(LINKARCH_LINKARCH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/linkarch)
set(LINKARCH_LINKARCH_CONFIG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/boardSystem)
include_directories(${LINKARCH_LINKARCH_CONFIG_INCLUDE_DIR})


## Target platforms configuration

IF(NOT DEFINED TARGET_PLATFORM_MCU)
    set(TARGET_PLATFORM_MCU "picosdk")
ENDIF()

IF(TARGET_PLATFORM_MCU STREQUAL "pcConsoleDebug")
    add_compile_definitions(TARGET_MCU_PCCONSOLEDEBUG)
ELSEIF(TARGET_PLATFORM_MCU STREQUAL "simActuator")
    add_compile_definitions(TARGET_MCU_SIMACTUATOR)
ELSEIF(TARGET_PLATFORM_MCU STREQUAL "picosdk")
    include(3rdparty/pico-sdk/pico_sdk_init.cmake)
    pico_sdk_init() 
    add_compile_definitions(TARGET_MCU_PICOSDK)

ELSE()
    message(FATAL_ERROR "Unsupported TARGET_PLATFORM_MCU: ${TARGET_PLATFORM_MCU}")

ENDIF()


IF(NOT DEFINED TARGET_PLATFORM_OS)
    set(TARGET_PLATFORM_OS "freertos")
ENDIF()

IF(TARGET_PLATFORM_OS STREQUAL "freertos")
        SET(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/FreeRTOS-Kernel)
        SET(FREERTOS_CONFIG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include/boardSystem)
        include(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)
        add_compile_definitions(TARGET_OS_FREERTOS)

ELSEIF(TARGET_PLATFORM_OS STREQUAL "posix")
    message(STATUS "Using platform OS: ${TARGET_PLATFORM_OS}")
    add_compile_definitions(TARGET_OS_POSIX)

ELSEIF(TARGET_PLATFORM_OS STREQUAL "pcConsoleDebug")
    message(STATUS "Using platform OS: ${TARGET_PLATFORM_OS}")
    add_compile_definitions(TARGET_OS_PCCONSOLEDEBUG)

ELSE()
    message(FATAL_ERROR "Unsupported TARGET_PLATFORM_OS: ${TARGET_PLATFORM_OS}")
ENDIF()


## Set the project informations

project(fw-crux
        VERSION 1.0.0
        DESCRIPTION "fw-crux: Firmware for Crux main board"
        LANGUAGES C CXX ASM)


## Linker architecture import

include(3rdparty/linkarch/linkarch.cmake)
include(3rdparty/nrf2401p/nrf24l01p.cmake)


## Get all source and header files of the project (except main.cpp)

file(GLOB_RECURSE LIB_SOURCES "src/*.c")
list(REMOVE_ITEM LIB_SOURCES "${src_dir}/main.c")
file(GLOB_RECURSE LIB_HEADERS "include/*.h")

file(GLOB_RECURSE INCLUDE_DIRS LIST_DIRECTORIES true "include/*")
set(FILTERED_INCLUDE_DIRS "")
foreach(dir ${INCLUDE_DIRS})
    if(IS_DIRECTORY ${dir})
        list(APPEND FILTERED_INCLUDE_DIRS ${dir})
    endif()
endforeach()
set(INCLUDE_DIRS ${FILTERED_INCLUDE_DIRS})


## Set main library

add_library(${PROJECT_NAME}_lib STATIC
    ${LIB_SOURCES}
    ${LIB_HEADERS}
)

target_compile_options(${PROJECT_NAME}_lib PRIVATE -Wall -Wextra)

target_include_directories(${PROJECT_NAME}_lib
    PUBLIC 
        ${INCLUDE_DIRS}
)

IF(TARGET_PLATFORM_MCU STREQUAL "picosdk")

    target_link_libraries(${PROJECT_NAME}_lib
    PUBLIC  
            pico_stdlib
            linkarch_controller
            nrf24l01p
    )

ELSEIF (TARGET_PLATFORM_MCU STREQUAL "pcConsoleDebug")
    
    target_link_libraries(${PROJECT_NAME}_lib
    PUBLIC  linkarch_controller
            nrf24l01p

    )

ELSEIF(TARGET_PLATFORM_MCU STREQUAL "simActuator")

    target_link_libraries(${PROJECT_NAME}_lib
    PUBLIC  linkarch_controller
            nrf24l01p
    )

ELSE()

    message(FATAL_ERROR "Unsupported TARGET_PLATFORM_MCU: ${TARGET_PLATFORM_MCU}")

ENDIF()


## Add executable
add_executable(${PROJECT_NAME} ${SRC_DIR}/main.c)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}_lib)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)


## Move executable to bin directory
IF(TARGET_PLATFORM_MCU STREQUAL "picosdk")

    pico_enable_stdio_usb(fw-crux 1)
    pico_enable_stdio_uart(fw-crux 0)
    pico_add_extra_outputs(fw-crux)

    add_custom_command(
        TARGET fw-crux POST_BUILD  
        COMMAND ${CMAKE_COMMAND} -E rename
        ${CMAKE_BINARY_DIR}/fw-crux.uf2
        ${CMAKE_SOURCE_DIR}/dist/fw-crux.uf2)

ELSEIF (TARGET_PLATFORM_MCU STREQUAL "pcConsoleDebug")
    add_custom_command(
        TARGET fw-crux POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/fw-crux
        ${CMAKE_SOURCE_DIR}/dist/fw-crux)

ELSEIF(TARGET_PLATFORM_MCU STREQUAL "simActuator")
    add_custom_command(
        TARGET fw-crux POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/fw-crux
        ${CMAKE_SOURCE_DIR}/dist/fw-crux)

ELSE()
    message(FATAL_ERROR "Unsupported TARGET_PLATFORM_MCU: ${TARGET_PLATFORM_MCU}")

ENDIF()

# Colorized output project description and version number
if(NOT WIN32)
  string(ASCII 27 Esc)
  set(Reset 		"${Esc}[m")
  set(BoldMagenta 	"${Esc}[1;35m")
endif()

message("${BoldMagenta} ${CMAKE_PROJECT_DESCRIPTION}" 
        " v${CMAKE_PROJECT_VERSION} ${Reset}")