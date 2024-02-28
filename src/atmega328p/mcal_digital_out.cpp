  #include "mcal_digital_out.h"
  #include "mcal_reg.h"

  void mcal::dio::McalDigitalOut::set_bit(bool value) const
  {
    if (value)
    {
        *reinterpret_cast<volatile std::uint8_t*>(mcal::r::portb)|=static_cast<std::uint8_t>(mcal::r::bit5);
    }
    else
    {
        *reinterpret_cast<volatile std::uint8_t*>(mcal::r::portb)&=static_cast<std::uint8_t>(~mcal::r::bit5);
    }
  }   