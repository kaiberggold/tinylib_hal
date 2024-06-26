#ifndef HAL
#define HAL

#include <hal_reg.h>
#include <hal_digital_port.h>
#include <hal_i2c_com.h>
#include <hal_spi_com.h>
#include <hal_interrupt_functions.h>
#include <hal_timer.h>

namespace hal
{
  void init();
}

#endif // HAL
