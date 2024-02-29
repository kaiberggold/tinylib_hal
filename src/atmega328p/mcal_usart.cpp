  #include "mcal_usart.h"
  #include "mcal_reg.h"
  #include "mcal_utils.h"


  void mcal::us::McalUsart::init(const std::uint16_t baud_rate)
  {
    using namespace mcal::r;
    const std::uint16_t ubrr=F_CPU/(16*baud_rate-1);
    //this->_ubrr0l=static_cast<uint8_t>(ubrr);
    //this->_ubrr0h=static_cast<uint8_t>(ubrr>>8U);
    #define BAUD 9600
    #define UBRR_VALUE (((F_CPU) + 8UL * (BAUD)) / (16UL * (BAUD)) -1UL)
    #define UBRRH_VALUE (UBRR_VALUE >> 8)
    #define UBRRL_VALUE (UBRR_VALUE & 0xff)

    *reinterpret_cast<volatile std::uint8_t*>(UBRR0L) = UBRRL_VALUE;
    *reinterpret_cast<volatile std::uint8_t*>(UBRR0H) = UBRRH_VALUE;
    
    const std::uint8_t U2X0 = 1;
    *reinterpret_cast<volatile std::uint8_t*>(UCSR0A) &= ~(1 << U2X0);
    
    
    *reinterpret_cast<volatile std::uint8_t*>(UCSR0B) = (1 << TXEN0) | (1 << RXEN0);
    // 8 data bits, 1 stop bit
    *reinterpret_cast<volatile std::uint8_t*>(UCSR0C) = (1 << UCSZ01) | (1 << UCSZ00); 
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
      return !mcal::get_bit(mcal::r::UCSR0A, mcal::r::UDRE0);
    }
  