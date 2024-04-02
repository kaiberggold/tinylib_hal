set( sources
    src/${HAL_PATH}/hal_reg.h
    src/${HAL_PATH}/hal_usart.h
    src/${HAL_PATH}/hal_usart.cpp
    src/${HAL_PATH}/hal_reg_access.h
    src/${HAL_PATH}/hal_digital_port.h
    src/${HAL_PATH}/hal_utils.h
    src/${HAL_PATH}/hal_i2c_com.h
    src/${HAL_PATH}/hal_spi_com.h
)

add_avr_library (hal ${sources})

target_include_directories (hal PUBLIC include)
# some .h files are in the src directory
target_include_directories (hal PUBLIC src)
target_include_directories (hal PUBLIC src/${HAL_PATH})
