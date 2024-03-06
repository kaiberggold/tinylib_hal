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

} // namespace hal

#endif // HAL_REG