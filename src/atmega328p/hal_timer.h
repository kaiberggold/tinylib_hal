#ifndef HAL_TIMER
#define HAL_TIMER
#include "hal_reg.h"
#include <hal_reg_access.h>
#include <timer_if.h>
namespace hal
{
    template <typename addr_t, typename reg_t, typename timer_t, timer_t timer_idx>

    struct TimerT : public utils::TimerIf<TimerT<addr_t, reg_t, timer_t, timer_idx>, addr_t, reg_t, timer_t, timer_idx>
    {
        static void init_impl(timer_t start_time)
        {
            // TCCR1A = 0x00;         // OC2A and OC2B disconnected; Wave Form Generator: Normal Mode
            // TCCR1B = (1 << CS12);  // prescaler = 256; alternative: 1024 (set CS12 and CS10)
            // TIMSK1 = (1 << TOIE1); // interrupt when TCNT1 is overflowed
            // TCNT1 = counterStart;
            HalRegAccess<addr_t, reg_t, hal::TCCR134A[0]>::reg_set(0x00U);
            HalRegAccess<addr_t, reg_t, hal::TCCR134B[0]>::reg_set_bits_only(hal::CS12);
            HalRegAccess<addr_t, reg_t, hal::TIMSK01234[1]>::reg_set_bits_only(hal::TOIE1);
            HalRegAccess<addr_t, std::uint16_t, hal::TCNT134[0]>::reg_set(start_time);
        }
        static void irq_reset_impl(timer_t start_time)
        {
            std::uint8_t sreg = hal::HalRegAccess<std::uint8_t, std::uint8_t, hal::SREG>::get_reg();
            hal::disable_all_interrupts();
            hal::HalRegAccess<std::uint16_t, std::uint16_t, hal::TCNT134[0]>::reg_set(start_time);
            hal::HalRegAccess<std::uint8_t, std::uint8_t, hal::SREG>::reg_set(sreg);
        }
    };
}
#endif