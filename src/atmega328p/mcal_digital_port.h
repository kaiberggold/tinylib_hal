#ifndef MCAL_DIGITAL_PORT
#define MCAL_DIGITAL_PORT
#include <cstdint>
#include <mcal_reg.h>
#include <mcal_reg_access.h>
#include <stdbool.h>

namespace hal
{
  template <typename addr_t, typename reg_t, const std::uint8_t port_idx>
  struct McalDigitalPort : public McalRegAccess<addr_t, reg_t, port[port_idx]>
  {
    static void set_to_out_mask(reg_t val)
    {
      // Set port value to 0
      McalRegAccess<addr_t, reg_t, port[port_idx]>::reg_and(val);
      // set to output
      McalRegAccess<addr_t, reg_t, ddr[port_idx]>::reg_or(val);
    }
  };

} // namespace hal
#endif // MCAL_DIGITAL_PORT