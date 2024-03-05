#ifndef HAL_UTILS
#define HAL_UTILS
#include <cstdint>

namespace hal
{
  template <typename T>
  T bit_mask(T pos_0)
  {
    return (1 << pos_0);
  }

  template <typename T, typename... Pos>
  T bit_mask(T pos_0, Pos... pos_n)
  {
    return (1 << pos_0) | bit_mask(pos_n...);
  }

  // template <typename T, typename... Position>
  // T &write_one(T &x, Position... pos0_n)
  // {
  //  x |= bit_mask(pos0_n...);
  ////  return x;

  static std::uint8_t get_reg(std::uint8_t address)
  {
    return *reinterpret_cast<volatile std::uint8_t *>(address);
  }

  static bool get_bit(std::uint8_t address, std::uint8_t bit_pos)
  {
    return static_cast<bool>(get_reg(address) & (1 << bit_pos));
  }

  static void set_reg(const std::uint8_t address, std::uint8_t data)
  {
    *reinterpret_cast<volatile std::uint8_t *>(address) =
        static_cast<std::uint8_t>(data);
  }
} // namespace hal
#endif // MCAL_UTILS