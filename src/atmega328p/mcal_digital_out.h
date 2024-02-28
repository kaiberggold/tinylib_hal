#ifndef MMAL_DIGITAL_OUT
  #define MMAL_DIGITAL_OUT
  #include <stdbool.h>
#include <cstdint>
#include <mcal_reg.h>


namespace mcal
{
    namespace dio
    {
        class McalDigitalOut
        {
            mcal::r::port_type port_id;
            std::uint8_t bit;    
        public:
            McalDigitalOut(const mcal::r::port_type p, const std::uint8_t b):port_id(p), bit(b)
            {
               //Set port value to 0
               *reinterpret_cast<volatile std::uint8_t*>(mcal::r::portb)&=static_cast<std::uint8_t>(~mcal::r::bit5);
               //set to output
               *reinterpret_cast<volatile std::uint8_t*>(mcal::r::ddr[port_id])|=mcal::r::bit5;
            }
            void set_bit(bool value) const;
        };
    }

}
#endif // MCAL_USART