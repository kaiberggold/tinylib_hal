#ifndef HAL_INTERRUPT_FUNCTIONS
#define HAL_INTERRUPT_FUNCTIONS
#include <stdint.h>
#include <hal_reg.h>
#include <hal_reg_access.h>

// Manually define the SPCR register address

namespace hal
{
    inline void enable_all_interrupts() noexcept { asm volatile("sei"); }
    inline void disable_all_interrupts() noexcept { asm volatile("cli"); }

    template <typename addr_t, typename reg_t, reg_t port_idx>
    static void enable_pin_change_port() noexcept
    {
        HalRegAccess<addr_t, reg_t, hal::PCICR>::reg_set_bits(1 << port_idx);
    }

    template <typename addr_t, typename reg_t, reg_t pin_idx>
    static void enable_pin_change_pin() noexcept
    {
        HalRegAccess<addr_t, reg_t, hal::PCMSK[pin_idx >> 3]>::reg_set_bits(pin_idx % 8);
    }

}
#endif