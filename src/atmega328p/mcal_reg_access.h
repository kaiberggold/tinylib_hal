#ifndef MCAL_REG_ACCESS
#define MCAL_REG_ACCESS
#include <stdbool.h>
#include <cstdint>
#include <mcal_reg.h>

namespace hal
{
        template<typename addr_t, typename reg_t, addr_t addr>
        struct McalRegAccess
        {
            static void set_reg(reg_t val)
            {
                *reinterpret_cast<volatile addr_t*>(addr)=static_cast<reg_t>(val);
            }
            static void reg_and(reg_t val)
            {
                *reinterpret_cast<volatile addr_t*>(addr)&=static_cast<reg_t>(val);
            }
            static reg_t get_reg()
            {
                return *reinterpret_cast<volatile addr_t*>(addr);
            }
             static void set_bits(reg_t val1, reg_t val2)
            {
                *reinterpret_cast<volatile addr_t*>(addr)|=static_cast<reg_t>(1U << val1|1U<<val2);
            }
        };
}



#endif // MCAL_REG_ACCESS