#ifndef MCAL_DIGITAL_PORT
#define MCAL_DIGITAL_PORT
#include <stdbool.h>
#include <cstdint>
#include <mcal_reg.h>


namespace hal
{
        template<typename addr_t, typename reg_t, const std::uint8_t port_idx>
        struct McalDigitalPort
        {
            static void set_port(reg_t val)
            {
                *reinterpret_cast<volatile addr_t*>(hal::port[port_idx])=static_cast<reg_t>(val);
            }
            static reg_t get_port()
            {
                return *reinterpret_cast<volatile addr_t*>(hal::port[port_idx]);
            }
            static void set_to_out_mask(reg_t val)
            {
                //Set port value to 0
                *reinterpret_cast<volatile addr_t*>(hal::port[port_idx])&=!(static_cast<reg_t>(val));
                //set to output
                *reinterpret_cast<volatile std::uint8_t*>(hal::ddr[port_idx])|=static_cast<reg_t>(val);
  
            }
            static void set_bit(reg_t val)
            {
                *reinterpret_cast<volatile addr_t*>(hal::port[port_idx])|=static_cast<reg_t>(1U << val);
            }
            static void set_bits(reg_t val1, reg_t val2)
            {
                *reinterpret_cast<volatile addr_t*>(hal::port[port_idx])|=static_cast<reg_t>(1U << val1|1U<<val2);
            }
            
        };

}
#endif // MCAL_DIGITAL_PORT