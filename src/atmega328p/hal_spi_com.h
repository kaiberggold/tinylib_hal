#ifndef HAL_SPI_COM
#define HAL_SPI_COM
#include <hal_reg.h>
#include <hal_reg_access.h>
#include <type_traits>
#include <cstdint>

namespace hal
{

    template <typename addr_t, typename reg_t, reg_t bus_idx, std::uint8_t port_idx, reg_t pin_idx, std::uint8_t clock_scaling>
    struct HalSpiCom
    {

        static constexpr void init()
        {
            static_assert(clock_scaling == 2 || clock_scaling == 4 || clock_scaling == 8 || clock_scaling == 16 || clock_scaling == 32 || clock_scaling == 64 || clock_scaling == 128, "clock_scaling must be 2,4,8,16,32,64 or 128");

            // CS to high
            HalRegAccess<addr_t, reg_t, hal::PORT[port_idx]>::reg_set_bits(pin_idx);
            // CS to output
            HalRegAccess<addr_t, reg_t, hal::DDR[port_idx]>::reg_set_bits(pin_idx);

            // MOSI to output
            HalRegAccess<addr_t, reg_t, hal::SPI_MOSI_DDR[bus_idx]>::reg_set_bits(hal::SPI_MOSI_POS[bus_idx]);
            // enable MISO pullup
            HalRegAccess<addr_t, reg_t, hal::SPI_MISO_PORT[bus_idx]>::reg_set_bits(hal::SPI_MISO_POS[bus_idx]);
            // CLock to output
            HalRegAccess<addr_t, reg_t, hal::SPI_SCK_DDR[bus_idx]>::reg_set_bits(hal::SPI_SCK_POS[bus_idx]);

            // Polarity??

            // prescaler
            switch (clock_scaling)
            {
            case 2:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_reset_bits(hal::SPR0, hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_set_bits(hal::SPI2X);
                break;
            case 4:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_reset_bits(hal::SPR0, hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_reset_bits(hal::SPI2X);
                break;
            case 8:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR0);
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_reset_bits(hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_set_bits(hal::SPI2X);
                break;
            case 16:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR0);
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_reset_bits(hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_reset_bits(hal::SPI2X);
                break;
            case 32:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_reset_bits(hal::SPR0);
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_set_bits(hal::SPI2X);
                break;
            case 64:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR0);
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_set_bits(hal::SPI2X);
                break;
            case 128:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR0);
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_reset_bits(hal::SPI2X);
                break;
            }
            // set as master, enable
            HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::MSTR, hal::SPE);
        }

        static void start()
        {
            // HalRegAccess<addr_t, reg_t, hal::TWCR[bus_idx]>::reg_set_bits(hal::TWINT, hal::TWEN, hal::TWSTA);
        }
        static void stop()
        {
            // HalRegAccess<addr_t, reg_t, hal::TWCR[bus_idx]>::reg_set_bits(hal::TWINT, hal::TWEN, hal::TWSTO);
        }
        static void send(reg_t data)
        {
            // HalRegAccess<addr_t, reg_t, hal::TWDR[bus_idx]>::reg_set(static_cast<reg_t>(data));
            // HalRegAccess<addr_t, reg_t, hal::TWCR[bus_idx]>::reg_set_bits_only(hal::TWINT, hal::TWEN);
        }

        static bool transmission_active()
        {
            // TODO: reg_bit_set()
            // return !hal::reg_bit_set(hal::TWCR[bus_idx], hal::TWINT);
        }
    };

} // namespace hal
#endif // HAL_SPI_COM