  #include "mcal_usart.h"
  #include "mcal_reg.h"

  void mcal::us::McalUsart::init(const std::uint32_t baud_rate)
  {
    using namespace mcal::r;
    const std::uint16_t UBRR=F_CPU/(16*baud_rate-1);
    this->_UBRR0L=static_cast<uint8_t>(UBRR&0xFF);
    this->_UBRR0H=static_cast<uint8_t>(UBRR<<8U);
    const std::uint8_t U2X0 = 0;
    *reinterpret_cast<volatile std::uint8_t*>(UCSR0A) &= ~(1 << U2X0);
    
    
    *reinterpret_cast<volatile std::uint8_t*>(UCSR0B) = (1 << TXEN0) | (1 << RXEN0);
    // 8 data bits, 1 stop bit
    *reinterpret_cast<volatile std::uint8_t*>(UCSR0C) = (1 << UCSZ01) | (1 << UCSZ00); 
  }   