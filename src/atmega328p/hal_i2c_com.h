#ifndef HAL_I2C_COM
#define HAL_I2C_COM
#include <cstdint>

namespace hal
{
    template <typename addr_t, typename reg_t, reg_t bus_idx, std::uint32_t freq>
    struct HalI2CCom
    {

        static void start()
        {
            HalRegAccess<addr_t, reg_t, hal::TWCR[bus_idx]>::reg_set_bits(hal::TWINT, hal::TWEN, hal::TWSTA);
        }
        static void stop()
        {
            HalRegAccess<addr_t, reg_t, hal::TWCR[bus_idx]>::reg_set_bits(hal::TWINT, hal::TWEN, hal::TWSTO);
        }
        static void send(reg_t data)
        {
            HalRegAccess<addr_t, reg_t, hal::TWDR[bus_idx]>::reg_set(static_cast<reg_t>(data));
            HalRegAccess<addr_t, reg_t, hal::TWCR[bus_idx]>::reg_set_bits_only(hal::TWINT, hal::TWEN);
        }
        static bool transmission_active()
        {
            // TODO: reg_bit_set()
            return !hal::reg_bit_set(hal::TWCR[bus_idx], hal::TWINT);
        }
        static void init()
        {
            // Prescaler 1. TODO: adjustable prescalers
            HalRegAccess<addr_t, reg_t, hal::TWSR[bus_idx]>::reg_reset_bits(hal::TWPS0, hal::TWPS1);
            // set speed. TODO: adjustable prescalers
            HalRegAccess<addr_t, reg_t, hal::TWBR[bus_idx]>::reg_set(static_cast<reg_t>(((F_CPU) / (freq)) - UINT32_C(16)) / UINT32_C(2));
            //  enable
            HalRegAccess<addr_t, reg_t, hal::TWCR[bus_idx]>::reg_set_bits(hal::TWEN);
        }
    };

} // namespace hal
#endif