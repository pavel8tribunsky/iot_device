cmake_minimum_required(VERSION 3.16)

# List of include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    CMSIS/Device/ST/STM32F4xx/Include
    CMSIS/Include
    STM32F4xx_HAL_Driver/Inc
    STM32F4xx_HAL_Driver/Inc/Legacy
    USB/middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
    USB/middlewares/ST/STM32_USB_Device_Library/Core/Inc
    USB/usb_device/App
    USB/usb_device/Target
)

target_sources(${PROJECT_NAME} PRIVATE
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c
    USB/middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c
    USB/middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c
    USB/middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c
    USB/middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c
    USB/usb_device/App/usb_device.c
    USB/usb_device/App/usbd_cdc_if.c
    USB/usb_device/App/usbd_desc.c
    USB/usb_device/Target/usbd_conf.c
)

# Подключение библиотеки semihosting'а.
#target_link_options(${PROJECT_NAME} PRIVATE -l rdimon $<$<C_COMPILER_ID:GNU>:-specs=rdimon.specs>)