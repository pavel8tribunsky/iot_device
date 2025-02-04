cmake_minimum_required(VERSION 3.16)

# List of include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    inc
)

target_sources(${PROJECT_NAME} PRIVATE
    src/board_specific.c
    src/crc.c
    src/gpio.c
    src/main.c
    src/spi.c
    src/stm32f4xx_hal_msp.c
    src/stm32f4xx_hal_timebase_tim.c
    src/stm32f4xx_it.c
    src/syscalls.c
    src/sysmem.c
    src/system_stm32f4xx.c
    src/usart.c
    startup_stm32f401xc.s
)

# Подключение библиотеки semihosting'а.
#target_link_options(${PROJECT_NAME} PRIVATE -l rdimon $<$<C_COMPILER_ID:GNU>:-specs=rdimon.specs>)
