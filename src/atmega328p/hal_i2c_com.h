#ifndef HAL_I2C_COM
#define HAL_I2C_COM
#include <cstdint>
#include <hal_reg.h>
#include <hal_reg_access.h>

namespace hal
{
    template <typename addr_t, typename reg_t, const std::uint8_t idx>
    struct HalI2CCom
    {
        static void init()
        {
            // set speed
            addr_t val;
            val = 0;
            HalRegAccess<addr_t, reg_t, hal::TWBR[idx]>::reg_sset(val);
            // enable
            HalRegAccess<addr_t, reg_t, hal::TWCR[idx]>::set_bits(hal::TWEN);
        }
    };

} // namespace hal
#endif // HAL_I2C_COM