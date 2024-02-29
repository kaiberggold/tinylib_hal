set( sources
    src/atmega328p/mcal_reg.h
    src/atmega328p/mcal_usart.h
    src/atmega328p/mcal_usart.cpp
    src/atmega328p/mcal_digital_out.h
    src/atmega328p/mcal_digital_out.cpp
    include/mcal_utils.h
)

add_avr_library (mcal ${sources})

target_include_directories (mcal PUBLIC include)
# some .h files are in the src directory
target_include_directories (mcal PUBLIC src)
target_include_directories (mcal PUBLIC src/atmega328p)
