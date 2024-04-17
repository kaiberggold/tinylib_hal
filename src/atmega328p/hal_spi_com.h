#ifndef HAL_SPI_COM
#define HAL_SPI_COM
#include <hal_reg.h>
#include <hal_reg_access.h>
#include <type_traits>
#include <cstdint>

namespace hal
{

    template <typename addr_t, typename reg_t, reg_t bus_idx, reg_t clock_scaling, reg_t spi_mode, reg_t data_order>
    struct HalSpiCom
    {

        static constexpr void init()
        {
            static_assert(clock_scaling == 2 || clock_scaling == 4 || clock_scaling == 8 || clock_scaling == 16 || clock_scaling == 32 || clock_scaling == 64 || clock_scaling == 128, "clock_scaling must be 2,4,8,16,32,64 or 128");

            // CS to high
            // HalRegAccess<addr_t, reg_t, hal::PORT[0]>::reg_set_bits(2);
            // CS to output
            // HalRegAccess<addr_t, reg_t, hal::DDR[0]>::reg_set_bits(2);
            // MOSI to output
            HalRegAccess<addr_t, reg_t, hal::SPI_MOSI_DDR[bus_idx]>::reg_set_bits(hal::SPI_MOSI_POS[bus_idx]);
            // enable MISO pullup
            HalRegAccess<addr_t, reg_t, hal::SPI_MISO_PORT[bus_idx]>::reg_set_bits(hal::SPI_MISO_POS[bus_idx]);
            // CLock to output
            HalRegAccess<addr_t, reg_t, hal::SPI_SCK_DDR[bus_idx]>::reg_set_bits(hal::SPI_SCK_POS[bus_idx]);

            // Polarity??
            reg_t tmp = HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::get_reg();
            tmp &= ~(UINT8_C(1 << hal::CPOL | 1 << hal::CPHA));
            tmp |= spi_mode & UINT8_C(3) << 2;
            HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set(tmp);

            // DORD
            if (data_order)
            {
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::DORD);
            }
            else
            {
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_reset_bits(hal::DORD);
            }
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
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_reset_bits(hal::SPR0);
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_set_bits(hal::SPI2X);
                break;
            case 16:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR0);
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_reset_bits(hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_reset_bits(hal::SPI2X);
                break;
            case 32:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR0);
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_reset_bits(hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_set_bits(hal::SPI2X);
                break;
            case 64:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR0, hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_set_bits(hal::SPI2X);
                break;
            case 128:
                HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::SPR0, hal::SPR1);
                HalRegAccess<addr_t, reg_t, hal::SPSR[bus_idx]>::reg_reset_bits(hal::SPI2X);
                break;
            }
            // set as master, enable
            HalRegAccess<addr_t, reg_t, hal::SPCR[bus_idx]>::reg_set_bits(hal::MSTR, hal::SPE);
        }

        static void send(reg_t data)
        {
            HalRegAccess<addr_t, reg_t, hal::SPDR[bus_idx]>::reg_set(static_cast<reg_t>(data));
        }

        static reg_t read()
        {
            return HalRegAccess<addr_t, reg_t, hal::SPDR[bus_idx]>::get_reg();
        }

        static bool transmission_active()
        {
            return !hal::reg_bit_set(hal::SPSR[bus_idx], hal::SPIF);
        }
    };

} // namespace hal
#endif // HAL_SPI_COM