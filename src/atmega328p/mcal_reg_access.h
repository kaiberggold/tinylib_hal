#ifndef MCAL_REG_ACCESS
#define MCAL_REG_ACCESS
#include <cstdint>
#include <mcal_reg.h>
#include <stdbool.h>
#include "mcal_utils.h"

namespace hal
{
  template <typename addr_t, typename reg_t, addr_t addr>
  struct McalRegAccess
  {
    static void set_reg(reg_t val)
    {
      *reinterpret_cast<volatile addr_t *>(addr) = static_cast<reg_t>(val);
    }
    static void reg_and(reg_t val)
    {
      *reinterpret_cast<volatile addr_t *>(addr) &= static_cast<reg_t>(val);
    }
    static reg_t get_reg() { return *reinterpret_cast<volatile addr_t *>(addr); }

    template <typename... Pos>
    static void set_bits(Pos &&...pos)
    {
      *reinterpret_cast<volatile addr_t *>(addr) |=
          static_cast<reg_t>(mcal::bit_mask(std::forward<Pos>(pos)...));
    }
  };

} // namespace hal
#endif // MCAL_REG_ACCESS