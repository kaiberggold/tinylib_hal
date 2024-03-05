#ifndef HAL_USART
#define HAL_USART

#include "hal_digital_port.h"
#include "hal_reg.h"
#include "hal_reg_access.h"
#include "hal_utils.h"
#include <array>
#include <cstdint>

namespace hal
{
  class HalUsart
  {
  private:
  public:
    void init(const std::uint32_t baud_rate);
    void transmit_byte_no_blocking(std::uint8_t data);
    bool buffer_is_empty();
  };

} // namespace hal
#endif // HAL_USART