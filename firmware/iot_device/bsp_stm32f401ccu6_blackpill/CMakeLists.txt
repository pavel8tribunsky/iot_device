cmake_minimum_required(VERSION 3.20)
project(IOT_STM32F401CCU_BLACKPILL)

set(CMAKE_TOOLCHAIN_FILE CMakeToolchain.cmake)
set(LINKER_FILE core/stm32f401ccu_flash.ld)
set(EXECUTABLE ${PROJECT_NAME}.elf)

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(
        ${EXECUTABLE}
		../application/app_general.c
		core/Src/gpio.c
		core/Src/main.c
		core/Src/spi.c
		core/Src/stm32f4xx_hal_msp.c
		core/Src/stm32f4xx_it.c
		core/Src/syscalls.c
		core/Src/sysmem.c
		core/Src/system_stm32f4xx.c
		core/Src/usart.c
		core/src/board_specific.c
		core/startup_stm32f401xc.s
		../../common/ic_drivers/src/sx1276/sx1276.c
		../../common/ioLibrary_Driver/Ethernet/W5500/w5500.c
		../../common/ioLibrary_Driver/Ethernet/socket.c
		../../common/ioLibrary_Driver/Ethernet/wizchip_conf.c
		../../common/ioLibrary_Driver/Internet/DHCP/dhcp.c
		../../common/ioLibrary_Driver/Internet/DNS/dns.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
		drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c
		drivers/USB/middlewares/st/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c
		drivers/USB/middlewares/st/STM32_USB_Device_Library/Core/Src/usbd_core.c
		drivers/USB/middlewares/st/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c
		drivers/USB/middlewares/st/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c
		drivers/USB/usb_device/app/usb_device.c
		drivers/USB/usb_device/app/usbd_cdc_if.c
		drivers/USB/usb_device/app/usbd_desc.c
		drivers/USB/usb_device/target/usbd_conf.c
		)

target_include_directories(${EXECUTABLE} PRIVATE
		../application
		../../common/ic_drivers/src/sx1276
		../../common/ioLibrary_Driver/Ethernet/W5500
		../../common/ioLibrary_Driver/Ethernet
		../../common/ioLibrary_Driver/Internet/DHCP
		../../common/ioLibrary_Driver/Internet/DNS
		core/inc
		drivers/CMSIS/Device/ST/STM32F4xx/Include
		drivers/CMSIS/Include
		drivers/STM32F4xx_HAL_Driver/inc
		drivers/STM32F4xx_HAL_Driver/inc/Legacy
		drivers/USB/middlewares/st/STM32_USB_Device_Library/Class/CDC/Inc
		drivers/USB/middlewares/st/STM32_USB_Device_Library/Core/Inc
		drivers/USB/usb_device/app
		drivers/USB/usb_device/target
		)

target_compile_definitions(${EXECUTABLE} PRIVATE
        -DSTM32F401xC
        -DDEBUG
)

target_compile_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
        -fdata-sections -ffunction-sections
		-fstack-usage
        -Wall -Wextra
        -O0
        -g3
)

target_link_options(${EXECUTABLE} PRIVATE -T${CMAKE_SOURCE_DIR}/${LINKER_FILE}
        -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
        -specs=nano.specs -specs=nosys.specs
        -Wl,-Map=${PROJECT_NAME}.map,--cref -Wl,--gc-sections -Xlinker -print-memory-usage -Xlinker
)

# Print executable size as part of the post build process
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_SIZE_UTIL} ${EXECUTABLE})

# Create hex, bin and S-Record files after the build
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin
)
