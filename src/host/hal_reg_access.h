#ifndef MCAL_REG_ACCESS
#define MCAL_REG_ACCESS
#include <cstdint>
#include <hal_reg.h>
#include <stdbool.h>
#include "hal_utils.h"
#include <iostream>
#include <string>

extern std::array<std::uint8_t, 256> _registers;
namespace hal

{
  template <typename addr_t, typename reg_t, addr_t addr>
  struct HalRegAccess
  {
    static void set_reg(reg_t val)
    {
      _registers[addr] = static_cast<reg_t>(val);
      std::cout << "Reg: " << std::to_string(addr) << " set to: " << std::to_string(_registers[addr]) << std::endl;
    }
    static void reg_and(reg_t val)
    {
      _registers[addr] &= static_cast<reg_t>(val);
      std::cout << "Reg: " << std::to_string(addr) << " set to: " << std::to_string(_registers[addr]) << std::endl;
    }
    static void reg_or(reg_t val)
    {
      _registers[addr] |= static_cast<reg_t>(val);
      std::cout << "Reg: " << std::to_string(addr) << " set to: " << std::to_string(_registers[addr]) << std::endl;
    }
    static void reg_xor(reg_t val)
    {
      _registers[addr] ^= static_cast<reg_t>(val);
      std::cout << "Reg: " << std::to_string(addr) << " set to: " << std::to_string(_registers[addr]) << std::endl;
    }

    static reg_t get_reg() { return *reinterpret_cast<volatile addr_t *>(addr); }

    // perfect forwarding of paramters, since unpacking only for the bits
    template <typename... Pos>
    static void set_bits(Pos &&...pos)
    {
      (_registers[addr]) |=
          static_cast<reg_t>(hal::bit_mask(std::forward<Pos>(pos)...));
      std::cout << "Reg: " << std::to_string(addr) << " set to: " << std::to_string(_registers[addr]) << std::endl;
    }
  };

} // namespace hal
#endif // MCAL_REG_ACCESS