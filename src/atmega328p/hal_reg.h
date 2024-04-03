#ifndef HAL_REG
#define HAL_REG

#include <array>
#include <cstdint>

namespace hal
{
    // offset
    constexpr std::uint8_t sfr_offset = 0x20U;

    // port indices
    constexpr std::uint8_t PORT_ID_B = 0U;
    constexpr std::uint8_t PORT_ID_C = 1U;
    constexpr std::uint8_t PORT_ID_D = 2U;
    constexpr std::uint8_t PORT_ID_E = 3U;

    // ports
    constexpr std::array<std::uint8_t, 4> DDR = {
        0x04U + sfr_offset, 0x07U + sfr_offset, 0x0AU + sfr_offset,
        0x0DU + sfr_offset};

    constexpr std::array<std::uint8_t, 4> PORT = {
        0x05U + sfr_offset, 0x08U + sfr_offset, 0x0BU + sfr_offset,
        0x0EU + sfr_offset};

    constexpr std::array<std::uint8_t, 4> PIN = {
        0x03U + sfr_offset, 0x06U + sfr_offset, 0x09U + sfr_offset,
        0x0CU + sfr_offset};

    // constexpr std::uint8_t DDRB = 0x04U + sfr_offset;
    // constexpr std::uint8_t PORTB = 0x05U + sfr_offset;
    // constexpr std::uint8_t PINB = 0x03U + sfr_offset;

    // constexpr std::uint8_t DDRC = 0x07U + sfr_offset;
    // constexpr std::uint8_t PORTC = 0x08U + sfr_offset;
    // constexpr std::uint8_t PINC = 0x06U + sfr_offset;

    // constexpr std::uint8_t DDRD = 0x0AU + sfr_offset;
    // constexpr std::uint8_t PORTD = 0x0BU + sfr_offset;
    // constexpr std::uint8_t PIND = 0x09U + sfr_offset;

    // constexpr std::uint8_t DDRE = 0x0DU + sfr_offset;
    // constexpr std::uint8_t PORTE = 0x0EU + sfr_offset;
    // constexpr std::uint8_t PINE = 0x0CU + sfr_offset;

    // Bits
    constexpr std::array<std::array<std::uint8_t, 8>, 4> P = {{{0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U},
                                                               {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U},
                                                               {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U},
                                                               {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U}}};

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

    // spi registers
    constexpr std::array<std::uint8_t, 1> SPCR = {0x2C + sfr_offset};
    constexpr std::array<std::uint8_t, 1> SPSR = {0x2D + sfr_offset};
    constexpr std::array<std::uint8_t, 1> SPDR = {0x2C + sfr_offset};

    // spi bits
    constexpr std::uint8_t SPR0 = 0U;
    constexpr std::uint8_t SPR1 = 1U;
    constexpr std::uint8_t CPHA = 2U;
    constexpr std::uint8_t CPOL = 3U;
    constexpr std::uint8_t MSTR = 4U;
    constexpr std::uint8_t DORD = 5U;
    constexpr std::uint8_t SPE = 6U;
    constexpr std::uint8_t SPIE = 7U;

    constexpr std::uint8_t SPI2X = 0U;
    constexpr std::uint8_t WCOL = 6U;
    constexpr std::uint8_t SPIF = 7U;

    constexpr std::uint8_t SPDR0 = 0U;
    constexpr std::uint8_t SPDR1 = 1U;
    constexpr std::uint8_t SPDR2 = 2U;
    constexpr std::uint8_t SPDR3 = 3U;
    constexpr std::uint8_t SPDR4 = 4U;
    constexpr std::uint8_t SPDR5 = 5U;
    constexpr std::uint8_t SPDR6 = 6U;
    constexpr std::uint8_t SPDR7 = 7U;

    // spi ports

    constexpr std::array<std::uint8_t, 1> SPI_MOSI_POS = {P[PORT_ID_B][3U]};
    constexpr std::array<std::uint8_t, 1> SPI_MOSI_PORT = {PORT[PORT_ID_B]};
    constexpr std::array<std::uint8_t, 1> SPI_MOSI_PIN = {PIN[PORT_ID_B]};
    constexpr std::array<std::uint8_t, 1> SPI_MOSI_DDR = {DDR[PORT_ID_B]};

    constexpr std::array<std::uint8_t, 1> SPI_MISO_POS = {P[PORT_ID_B][4U]};
    constexpr std::array<std::uint8_t, 1> SPI_MISO_PORT = {PORT[PORT_ID_B]};
    constexpr std::array<std::uint8_t, 1> SPI_MISO_PIN = {PIN[PORT_ID_B]};
    constexpr std::array<std::uint8_t, 1> SPI_MISO_DDR = {DDR[PORT_ID_B]};

    constexpr std::array<std::uint8_t, 1> SPI_SCK_POS = {P[PORT_ID_B][5U]};
    constexpr std::array<std::uint8_t, 1> SPI_SCK_PORT = {PORT[PORT_ID_B]};
    constexpr std::array<std::uint8_t, 1> SPI_SCK_PIN = {PIN[PORT_ID_B]};
    constexpr std::array<std::uint8_t, 1> SPI_SCK_DDR = {DDR[PORT_ID_B]};

} // namespace hal

#endif // HAL_REG