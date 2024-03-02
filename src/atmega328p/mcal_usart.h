#ifndef MCAL_USART
  #define MCAL_USART

#include <cstdint>
#include <array>
#include "mcal_reg.h"
#include "mcal_reg_access.h"
#include "mcal_digital_port.h"
#include "mcal_utils.h"
#include <cstdint>

namespace mcal
{
    namespace us
    {
        class McalUsart
        {
        private:
            tlm::rac::McalRegAccess<std::uint8_t, std::uint8_t,mcal::r::UCSR0A> ucsr0a;
            tlm::rac::McalRegAccess<std::uint8_t, std::uint8_t,mcal::r::UCSR0B> ucsr0b;
            tlm::rac::McalRegAccess<std::uint8_t, std::uint8_t,mcal::r::UCSR0C> ucsr0c;
            tlm::rac::McalRegAccess<std::uint8_t, std::uint8_t,mcal::r::UBRR0L> ubrr0l;
            tlm::rac::McalRegAccess<std::uint8_t, std::uint8_t,mcal::r::UBRR0H> ubrr0h;
            
            
        public:

            void init(const std::uint32_t baud_rate);
            void transmit_byte_no_blocking(std::uint8_t data);
            bool buffer_is_empty();
        };
    }

}
#endif // MCAL_USART