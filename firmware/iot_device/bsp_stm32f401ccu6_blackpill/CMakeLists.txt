cmake_minimum_required(VERSION 3.16)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/gcc-arm-none-eabi.cmake")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# В качестве имени проекта используем имя папки (см. tasks.json и launch.json).
get_filename_component(BASE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME ${BASE_FOLDER})

# Файл конфигурации компоновщика.
set(LINKER_FILE "${CMAKE_CURRENT_SOURCE_DIR}/core/stm32f401ccu_flash.ld")

project(${PROJECT_NAME} C CXX ASM)

add_executable(${PROJECT_NAME})

# Подключаем необходимые библиотеки.
add_subdirectory(core)
add_subdirectory(drivers)
# include_directories(../application)
add_subdirectory(../application application)
add_subdirectory(../../common common)


target_link_libraries(${PROJECT_NAME} STM32::Nano STM32::NoSys)

# Опции сборки.
target_compile_definitions(${PROJECT_NAME} PRIVATE STM32F401xC)

target_compile_options(${PROJECT_NAME} PRIVATE
    # device type (cortex-m0, cortex-m3, ..)
    -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
    # warning
    -W -Wall -Wextra
    # optimization
    $<$<CONFIG:DEBUG>:-O0>
    $<$<CONFIG:RELEASE>:-Os>
    -ffunction-sections -fdata-sections -fstack-usage
    # debug
    $<$<CONFIG:DEBUG>:-g3>
    #-Wa,-adhlns=${PROJECT_NAME}.lst
    # other
    -pipe
    # c/cxx flags
    $<$<COMPILE_LANGUAGE:CXX>:-fpermissive -fno-exceptions -fno-rtti -funsigned-bitfields -fshort-enums -Winline>
)

target_link_options(${PROJECT_NAME} PRIVATE
    -T${LINKER_FILE}
    -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
    -lc -lgcc
    -Wl,-Map=${PROJECT_NAME}.map,--no-warn-rwx-segments,--cref,--gc-sections,--print-memory-usage
)

# Артефакты сборки.
stm32_print_size_of_target(${PROJECT_NAME})
stm32_generate_binary_file(${PROJECT_NAME})
stm32_generate_hex_file(${PROJECT_NAME})
stm32_generate_lss_file(${PROJECT_NAME})
