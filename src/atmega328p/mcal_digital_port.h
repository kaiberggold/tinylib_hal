#ifndef MCAL_DIGITAL_PORT
#define MCAL_DIGITAL_PORT
#include <stdbool.h>
#include <cstdint>
#include <mcal_reg.h>
#include <mcal_reg_access.h>



namespace hal
{
        template<typename addr_t, typename reg_t, const std::uint8_t port_idx>
        struct McalDigitalPort: public McalRegAccess<addr_t,reg_t,port[port_idx]>
        {
         static void set_to_out_mask(reg_t val)
            {
                //Set port value to 0
                *reinterpret_cast<volatile addr_t*>(port[port_idx])&=!(static_cast<reg_t>(val));
                //set to output
               *reinterpret_cast<volatile std::uint8_t*>(ddr[port_idx])|=static_cast<reg_t>(val);
            }
        };

    
}
#endif // MCAL_DIGITAL_PORT