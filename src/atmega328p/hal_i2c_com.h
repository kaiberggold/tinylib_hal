#ifndef HAL_I2C_COM
#define HAL_I2C_COM
#include <cstdint>
#include <hal_reg.h>
#include <hal_reg_access.h>

namespace hal
{
    template <typename addr_t, typename reg_t, const std::uint32_t freq, const std::uint8_t bus_idx>
    struct HalI2CCom
    {
        static void init()
        {
            // Prescaler 1. TODO: adjustable prescalers
            HalRegAccess<addr_t, reg_t, hal::TWBR[bus_idx]>::reg_reset_bits(hal::TWPS0, hal::TWPS1);
            // set speed. TODO: adjustable prescalers
            HalRegAccess<addr_t, reg_t, hal::TWBR[bus_idx]>::reg_set(static_cast<reg_t>(((F_CPU) / (freq)) - UINT32_C(16)) / UINT32_C(2));
            //  enable
            HalRegAccess<addr_t, reg_t, hal::TWCR[bus_idx]>::reg_set_bits(hal::TWEN);
        }
    };

} // namespace hal
#endif // HAL_I2C_COM