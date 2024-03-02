  #include "mcal_usart.h"


  void mcal::us::McalUsart::init(const std::uint32_t baud_rate)
  {

    using namespace mcal::r;
    const std ::uint16_t ubrr=static_cast<std::uint16_t>(((F_CPU) + UINT32_C(8) * (baud_rate)) / (UINT32_C(16) * (baud_rate)) -UINT32_C(1));
    std::uint8_t ul = static_cast<uint8_t>(ubrr&UINT16_C(0x00FF));
    std::uint8_t uh = static_cast<uint8_t>(ubrr>>8U);
    ubrr0l.set_reg(ul);
    ubrr0h.set_reg(uh);
    
    const std::uint8_t U2X0 = 1;
    ucsr0a.set_reg_and((1 << U2X0));
    ucsr0b.set_reg((1 << TXEN0) | (1 << RXEN0));
    ucsr0c.set_reg((1 << UCSZ01) | (1 << UCSZ00));
      
  }

  void mcal::us::McalUsart::transmit_byte_no_blocking(std::uint8_t data)
  {
    if  (this->buffer_is_empty())
    {
      mcal::set_reg(mcal::r::UDR0,data);
    }
  }

  bool mcal::us::McalUsart::buffer_is_empty()
    {
      return (mcal::get_bit(mcal::r::UCSR0A, mcal::r::UDRE0));
    }
  