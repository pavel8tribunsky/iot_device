cmake_minimum_required(VERSION 3.16)

# List of include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    # console
    ic_drivers/src/ds18b20
    ic_drivers/src/w25qxx
    ioLibrary_Driver/Ethernet
    ioLibrary_Driver/Ethernet/W5500
    ioLibrary_Driver/Internet/DHCP
    ioLibrary_Driver/Internet/DNS    
#   logc/
)

target_sources(${PROJECT_NAME} PRIVATE
    # console/commands.c
    # console/console.c
    ic_drivers/src/ds18b20/ds18x20.c
    ic_drivers/src/w25qxx/w25qxx.c
    ioLibrary_Driver/Ethernet/W5500/w5500.c
    ioLibrary_Driver/Ethernet/socket.c
    ioLibrary_Driver/Ethernet/wizchip_conf.c
    ioLibrary_Driver/Internet/DHCP/dhcp.c
    ioLibrary_Driver/Internet/DNS/dns.c
#   logc/log.c
)

# Подключение библиотеки semihosting'а.
#target_link_options(${PROJECT_NAME} PRIVATE -l rdimon $<$<C_COMPILER_ID:GNU>:-specs=rdimon.specs>)
