#ifndef MCAL_DIGITAL_PORT
#define MCAL_DIGITAL_PORT
#include <stdbool.h>
#include <cstdint>
#include <mcal_reg.h>


namespace tlm
{
    namespace dpo
    {
        template<typename addr_t, typename reg_t, const std::uint8_t port_idx>
        struct McalDigitalPort
        {
            static void set_port(reg_t val)
            {
                *reinterpret_cast<volatile addr_t*>(mcal::r::port[port_idx])=static_cast<reg_t>(val);
            }
            static reg_t get_port()
            {
                return *reinterpret_cast<volatile addr_t*>(mcal::r::port[port_idx]);
            }
            static void set_to_out_mask(reg_t val)
            {
                //Set port value to 0
                *reinterpret_cast<volatile addr_t*>(mcal::r::port[port_idx])&=!(static_cast<reg_t>(val));
                //set to output
                *reinterpret_cast<volatile std::uint8_t*>(mcal::r::ddr[port_idx])|=static_cast<reg_t>(val);
  
            }
        };
    }

}
#endif // MCAL_DIGITAL_PORT