#ifndef HAL_INTERRUPT_FUNCTIONS
#define HAL_INTERRUPT_FUNCTIONS
#include <stdint.h>
#include <hal_reg.h>
#include <hal_reg_access.h>

// Manually define the SPCR register address

namespace hal
{
    // template <typename addr_t, typename reg_t, addr_t addr, reg_t value>

    // inline void __attribute__((always_inline)) writeToReg()
    // {

    //     asm volatile(

    //         "sts %0, %1 \n\t"

    //         :

    //         : "M"(reinterpret_cast<volatile uint8_t *>(addr)), "r"(static_cast<uint8_t>(value))

    //         : "memory"

    //     );
    // }

    // template <typename addr_t, typename reg_t, reg_t value>

    // inline void __attribute__((always_inline)) writeToSPI()
    // {

    //     writeToReg<addr_t, reg_t, SPCR, 0x1F>();
    // }

    inline void enable_all_interrupts() noexcept { asm volatile("sei"); }
    inline void disable_all_interrupts() noexcept { asm volatile("cli"); }
}
#endif