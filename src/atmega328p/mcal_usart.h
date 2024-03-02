#ifndef MCAL_USART
  #define MCAL_USART

#include <cstdint>
#include <array>
#include "mcal_reg.h"
#include "mcal_reg_access.h"
#include "mcal_digital_port.h"
#include "mcal_utils.h"
#include <cstdint>

namespace hal
{
    class McalUsart
       {
        private:
    
            

            
            
        public:

            void init(const std::uint32_t baud_rate);
            void transmit_byte_no_blocking(std::uint8_t data);
            bool buffer_is_empty();
        };

}
#endif // MCAL_USART