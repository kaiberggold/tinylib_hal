#ifndef HAL_TIMER
#define HAL_TIMER
#include "hal_reg.h"
#include <hal_reg_access.h>

namespace hal
{
    template <typename addr_t, typename reg_t, const std::uint8_t timer_idx>
    struct HalTimer : public HalRegAccess<addr_t, reg_t, TIMER[timer_idx]>
    {
        static void isr_ena()
        {
            // set to output
            // HalRegAccess<addr_t, reg_t, DDR[port_idx]>::reg_or(val);
        }
    };

}
#endif