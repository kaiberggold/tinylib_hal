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
        };
    }

}
#endif // MCAL_DIGITAL_PORT