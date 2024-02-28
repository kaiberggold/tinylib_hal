#ifndef MCAL_REG
  #define MCAL_REG

  #include <cstdint>
  #include <array>
  

  namespace mcal
  {
    namespace r
    {
      enum port_type: std::int8_t
      {
          port_b,
          port_c,
          port_d,
          port_e
      };
 

      constexpr std::uint8_t sfr_offset = 0x20U;
      //USART 
      constexpr std::uint8_t UCSR0A = 0xC0 + sfr_offset;
      constexpr std::uint8_t UCSR0B = 0xC1 + sfr_offset;
      constexpr std::uint8_t UCSR0C = 0xC2 + sfr_offset;
      constexpr std::uint8_t UBRR0L = 0xC4;
      constexpr std::uint8_t UBRR0H = 0xC5; 
      constexpr std::uint8_t TXEN0  = 0x00;
      constexpr std::uint8_t RXEN0  = 0x00;
      constexpr std::uint8_t UCSZ01  = 0x00;
      constexpr std::uint8_t UCSZ00  = 0x00;

      //ports
      constexpr std::array<std::uint8_t, 4> ddr={0x04U + sfr_offset,
                                                 0x07U + sfr_offset,
                                                 0x0AU + sfr_offset,
                                                 0x0DU + sfr_offset};

      constexpr std::uint8_t ddrb   = 0x04U + sfr_offset;
      constexpr std::uint8_t portb  = 0x05U + sfr_offset;
      constexpr std::uint8_t pinb   = 0x03U + sfr_offset;

      constexpr std::uint8_t ddrc   = 0x07U + sfr_offset;
      constexpr std::uint8_t portc  = 0x08U + sfr_offset;
      constexpr std::uint8_t pinc   = 0x06U + sfr_offset;

      constexpr std::uint8_t ddrd   = 0x0AU + sfr_offset;
      constexpr std::uint8_t portd  = 0x0BU + sfr_offset;
      constexpr std::uint8_t pind   = 0x09U + sfr_offset;

      constexpr std::uint8_t ddre   = 0x0DU + sfr_offset;
      constexpr std::uint8_t porte  = 0x0EU + sfr_offset;
      constexpr std::uint8_t pine   = 0x0CU + sfr_offset;

      //Bits
      constexpr std::uint8_t bit0  = 1U;
      constexpr std::uint8_t bit1  = 1U << 1U;
      constexpr std::uint8_t bit2  = 1U << 2U;
      constexpr std::uint8_t bit3  = 1U << 3U;
      constexpr std::uint8_t bit4  = 1U << 4U;
      constexpr std::uint8_t bit5  = 1U << 5U;
      constexpr std::uint8_t bit6  = 1U << 6U;
      constexpr std::uint8_t bit7  = 1U << 7U;
      
    }
   }

#endif // MCAL_REG