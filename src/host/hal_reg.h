#ifndef HAL_REG
#define HAL_REG

#include <array>
#include <cstdint>

namespace hal
{

    constexpr std::uint8_t sfr_offset = 0x20U;
    // USART
    constexpr std::uint8_t UCSR0A = 0xC0;
    constexpr std::uint8_t UCSR0B = 0xC1;
    constexpr std::uint8_t UCSR0C = 0xC2;
    constexpr std::uint8_t UBRR0L = 0xC4; // offset??
    constexpr std::uint8_t UBRR0H = 0xC5; // offset??
    constexpr std::uint8_t UDR0 = 0xC6;   // offset??

    // USART bit values
    constexpr std::uint8_t MPCM0 = 0U;
    constexpr std::uint8_t U2X0 = 1U;
    constexpr std::uint8_t UPE0 = 2u;
    constexpr std::uint8_t DOR0 = 3U;
    constexpr std::uint8_t FE0 = 4U;
    constexpr std::uint8_t UDRE0 = 5U;
    constexpr std::uint8_t TXC0 = 6U;
    constexpr std::uint8_t RXC0 = 7U;

    constexpr std::uint8_t TXB80 = 0U;
    constexpr std::uint8_t RXB80 = 1U;
    constexpr std::uint8_t UCSZ02 = 2U;
    constexpr std::uint8_t TXEN0 = 3U;
    constexpr std::uint8_t RXEN0 = 4U;
    constexpr std::uint8_t UDRIE0 = 5U;
    constexpr std::uint8_t TXCIE0 = 6U;
    constexpr std::uint8_t RXCIE0 = 7U;

    constexpr std::uint8_t UCPOL0 = 0U;
    constexpr std::uint8_t UCSZ00 = 1U;
    constexpr std::uint8_t UCPHA0 = 1U;
    constexpr std::uint8_t UCSZ01 = 2U;
    constexpr std::uint8_t UDORD0 = 2U;
    constexpr std::uint8_t USBS0 = 3U;
    constexpr std::uint8_t UPM00 = 4U;
    constexpr std::uint8_t UPM01 = 5U;
    constexpr std::uint8_t UMSEL00 = 6U;
    constexpr std::uint8_t UMSEL01 = 7U;

    constexpr std::uint8_t UDR0_0 = 0U;
    constexpr std::uint8_t UDR0_1 = 1U;
    constexpr std::uint8_t UDR0_2 = 2U;
    constexpr std::uint8_t UDR0_3 = 3U;
    constexpr std::uint8_t UDR0_4 = 4U;
    constexpr std::uint8_t UDR0_5 = 5U;
    constexpr std::uint8_t UDR0_6 = 6U;
    constexpr std::uint8_t UDR0_7 = 7U;

    // i2C
    constexpr std::array<std::uint8_t, 1> TWBR = {0xB8};
    constexpr std::array<std::uint8_t, 1> TWSR = {0xB9};
    constexpr std::array<std::uint8_t, 1> TWCR = {0xBC};
    constexpr std::array<std::uint8_t, 1> TWDR = {0xBB};

    // I2c Bits
    constexpr std::uint8_t TWIE = 0U;
    constexpr std::uint8_t TWEN = 2U;
    constexpr std::uint8_t TWWC = 3U;
    constexpr std::uint8_t TWSTO = 4U;
    constexpr std::uint8_t TWSTA = 5U;
    constexpr std::uint8_t TWEA = 6U;
    constexpr std::uint8_t TWINT = 7U;

    constexpr std::uint8_t TWPS0 = 0U;
    constexpr std::uint8_t TWPS1 = 1U;
    constexpr std::uint8_t TWS3 = 3U;
    constexpr std::uint8_t TWS4 = 4U;
    constexpr std::uint8_t TWS5 = 5U;
    constexpr std::uint8_t TWS6 = 6U;
    constexpr std::uint8_t TWS7 = 7U;

    constexpr std::uint8_t TTWD0 = 0U;
    constexpr std::uint8_t TTWD1 = 1U;
    constexpr std::uint8_t TTWD2 = 2U;
    constexpr std::uint8_t TTWD3 = 3U;
    constexpr std::uint8_t TTWD4 = 4U;
    constexpr std::uint8_t TTWD5 = 5U;
    constexpr std::uint8_t TTWD6 = 6U;
    constexpr std::uint8_t TTWD7 = 7U;

    // ports
    constexpr std::array<std::uint8_t, 4> ddr = {
        0x04U + sfr_offset, 0x07U + sfr_offset, 0x0AU + sfr_offset,
        0x0DU + sfr_offset};

    constexpr std::array<std::uint8_t, 4> port = {
        0x05U + sfr_offset, 0x08U + sfr_offset, 0x0BU + sfr_offset,
        0x0EU + sfr_offset};

    constexpr std::uint8_t ddrb = 0x04U + sfr_offset;
    constexpr std::uint8_t portb = 0x05U + sfr_offset;
    constexpr std::uint8_t pinb = 0x03U + sfr_offset;

    constexpr std::uint8_t ddrc = 0x07U + sfr_offset;
    constexpr std::uint8_t portc = 0x08U + sfr_offset;
    constexpr std::uint8_t pinc = 0x06U + sfr_offset;

    constexpr std::uint8_t ddrd = 0x0AU + sfr_offset;
    constexpr std::uint8_t portd = 0x0BU + sfr_offset;
    constexpr std::uint8_t pind = 0x09U + sfr_offset;

    constexpr std::uint8_t ddre = 0x0DU + sfr_offset;
    constexpr std::uint8_t porte = 0x0EU + sfr_offset;
    constexpr std::uint8_t pine = 0x0CU + sfr_offset;

    // Bits
    constexpr std::array<std::uint8_t, 8> pbits = {
        1U, 1U << 1U, 1U << 2U, 1U << 3U, 1U << 4U, 1U << 5U, 1U << 6U, 1U << 7U};

    // timers
    constexpr std::array<std::uint8_t, 3> TCCR134A = {0x80U, 0x90U, 0xA0U};
    constexpr std::array<std::uint8_t, 3> TCCR134B = {0x81U, 0x91U, 0xA1U);
    constexpr std::array<std::uint8_t, 3> TCCR134C = (0x82U, 0x92U, 0xA2U);
    constexpr std::array<std::uint8_t, 5> TIMSK01234 = {0x6EU, 0x6FU, 0x70U, 0x71U, 0x72U}

    // timer bits
    constexpr std::uint8_t WGM10 = 0;
    constexpr std::uint8_t WGM11 = 1;
    constexpr std::uint8_t COM1B0 = 4;
    constexpr std::uint8_t COM1B1 = 5;
    constexpr std::uint8_t COM1A0 = 6;
    constexpr std::uint8_t COM1A1 = 7;

    constexpr std::uint8_t CS10 = 0;
    constexpr std::uint8_t CS11 = 1;
    constexpr std::uint8_t CS12 = 2;
    constexpr std::uint8_t WGM12 = 3;
    constexpr std::uint8_t WGM13 = 4;
    constexpr std::uint8_t ICES1 = 6;
    constexpr std::uint8_t ICNC1 = 7;
    constexpr std::uint8_t FOC1B = 6U;
    constexpr std::uint8_t FOC1A = 7U;

    constexpr std::array<std::uint16_t, 3> TCNT134 = (0x84U, 0x94U, 0xA4U);
    constexpr std::array<std::uint8_t, 3> TCNT134L = (0x84U, 0x94U, 0xA4U);
    constexpr std::array<std::uint8_t, 3> TCNT134H = (0x85U, 0x95U, 0xA5U);
    constexpr std::array<std::uint16_t, 3> ICR134 = (0x86U, 0x96U, 0xA6U);
    constexpr std::array<std::uint8_t, 3> ICR134L = (0x86U, 0x96U, 0xA6U);
    constexpr std::array<std::uint8_t, 3> ICR134H = (0x87U, 0x97U, 0xA7U);
    constexpr std::array<std::uint16_t, 3> OCR134A = (0x88U, 0x98U, 0xA8U);
    constexpr std::array<std::uint8_t, 3> OCR134AL = (0x88U, 0x98U, 0xA8U);
    constexpr std::array<std::uint8_t, 3> OCR134AH = (0x89U, 0x99U, 0xA9U);
    constexpr std::array<std::uint16_t, 3> OCR134B = (0x8AU, 0x9AU, 0xAAU);
    constexpr std::array<std::uint8_t, 3> OCR134BL = (0x8AU, 0x9AU, 0xAAU);
    constexpr std::array<std::uint8_t, 3> OCR134BH = (0x8BU, 0x9BU, 0xABU);

    constexpr std::uint8_t TOIE0 = 0U;
    constexpr std::uint8_t OCIE0A = 1U;
    constexpr std::uint8_t OCIE0B = 2U;

    constexpr std::uint8_t TOIE1 = 0U;
    constexpr std::uint8_t OCIE1A = 1U;
    constexpr std::uint8_t OCIE1B = 2U;
    constexpr std::uint8_t ICIE1 = 5U;

    constexpr std::uint8_t TOIE2 = 0U;
    constexpr std::uint8_t OCIE2A = 1U;
    constexpr std::uint8_t OCIE2B = 2U;

} // namespace hal

#endif // HAL_REG