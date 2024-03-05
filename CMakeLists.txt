set( sources
    src/${HAL_PATH}/mcal_reg.h
    src/${HAL_PATH}/mcal_usart.h
    src/${HAL_PATH}/mcal_usart.cpp
    src/${HAL_PATH}/mcal_reg_access.h
    src/${HAL_PATH}/mcal_digital_port.h
    src/${HAL_PATH}/mcal_utils.h
)

add_avr_library (mcal ${sources})

target_include_directories (mcal PUBLIC include)
# some .h files are in the src directory
target_include_directories (mcal PUBLIC src)
target_include_directories (mcal PUBLIC src/${HAL_PATH})
