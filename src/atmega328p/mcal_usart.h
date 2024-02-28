#ifndef MMAL_USART
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
            std::uint8_t _UBRR0H;
            std::uint8_t _UBRR0L;
            
        public:

            void init(const std::uint32_t baud_rate);
            void transmit_byte(std::uint8_t data);
            bool buffer_is_empty();
        };
    }

}
#endif // MCAL_USART