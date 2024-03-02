#ifndef MCAL_REG_ACCESS
#define MCAL_REG_ACCESS
#include <stdbool.h>
#include <cstdint>
#include <mcal_reg.h>

namespace tlm
{
    namespace rac
    {
        template<typename addr_t, typename reg_t, addr_t addr>
        struct McalRegAccess
        {
            static void set_reg(reg_t val)
            {
                *reinterpret_cast<volatile addr_t*>(addr)=static_cast<reg_t>(val);
            }
            static void set_reg_and(reg_t val)
            {
                *reinterpret_cast<volatile addr_t*>(addr)&=static_cast<reg_t>(val);
            }
            static reg_t get_reg()
            {
                return *reinterpret_cast<volatile addr_t*>(addr);
            }
        };
    }

}
#endif // MCAL_REG_ACCESS