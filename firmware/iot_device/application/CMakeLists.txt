cmake_minimum_required(VERSION 3.16)

# List of include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    inc
)

target_sources(${PROJECT_NAME} PRIVATE
    src/app_general.c
)

# Подключение библиотеки semihosting'а.
#target_link_options(${PROJECT_NAME} PRIVATE -l rdimon $<$<C_COMPILER_ID:GNU>:-specs=rdimon.specs>)
