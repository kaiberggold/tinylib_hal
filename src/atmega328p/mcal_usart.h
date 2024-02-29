#ifndef MCAL_USART
  #define MCAL_USART

#include <cstdint>
#include <array>
#include <mcal_reg.h>


namespace mcal
{
    namespace us
    {
        class McalUsart
        {
        private:
            std::uint8_t _ubrr0h;
            std::uint8_t _ubrr0l;
            
        public:

            void init(const std::uint16_t baud_rate);
            void transmit_byte_no_blocking(std::uint8_t data);
            bool buffer_is_empty();
        };
    }

}
#endif // MCAL_USART