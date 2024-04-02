#ifndef MCAL_REG_ACCESS
#define MCAL_REG_ACCESS
#include <cstdint>
#include <hal_reg.h>
#include <stdbool.h>
#include "hal_utils.h"

namespace hal
{
  template <typename addr_t, typename reg_t, addr_t addr>
  struct HalRegAccess
  {
    static void reg_set(reg_t val)
    {
      *reinterpret_cast<volatile addr_t *>(addr) = static_cast<reg_t>(val);
    }
    static void reg_and(reg_t val)
    {
      *reinterpret_cast<volatile addr_t *>(addr) &= static_cast<reg_t>(val);
    }
    static void reg_or(reg_t val)
    {
      *reinterpret_cast<volatile addr_t *>(addr) |= static_cast<reg_t>(val);
    }
    static void reg_xor(reg_t val)
    {
      *reinterpret_cast<volatile addr_t *>(addr) ^= static_cast<reg_t>(val);
    }

    static reg_t get_reg()
    {
      return *reinterpret_cast<volatile addr_t *>(addr);
    } // perfect forwarding of paramters, since unpacking only for the bits
    template <typename... Pos>
    static void reg_set_bits(Pos &&...pos)
    {
      *reinterpret_cast<volatile addr_t *>(addr) |=
          static_cast<reg_t>(hal::bit_mask(std::forward<Pos>(pos)...));
    }

    // perfect forwarding of paramters, since unpacking only for the bits
    template <typename... Pos>
    static void reg_set_bits_only(Pos &&...pos)
    {
      *reinterpret_cast<volatile addr_t *>(addr) =
          static_cast<reg_t>(hal::bit_mask(std::forward<Pos>(pos)...));
    }

    // perfect forwarding of paramters, since unpacking only for the bits
    template <typename... Pos>
    static void reg_reset_bits(Pos &&...pos)
    {
      *reinterpret_cast<volatile addr_t *>(addr) &=
          (!static_cast<reg_t>(hal::bit_mask(std::forward<Pos>(pos)...)));
    }
  };

} // namespace hal
#endif // MCAL_REG_ACCESS