#include "hal_usart.h"

void hal::HalUsart::init(const std::uint32_t baud_rate)
{

  const std ::uint16_t ubrr = static_cast<std::uint16_t>(
      ((F_CPU) + UINT32_C(8) * (baud_rate)) / (UINT32_C(16) * (baud_rate)) -
      UINT32_C(1));
  std::uint8_t ul = static_cast<uint8_t>(ubrr & UINT16_C(0x00FF));
  std::uint8_t uh = static_cast<uint8_t>(ubrr >> 8U);
  hal::HalRegAccess<std::uint8_t, std::uint8_t, hal::UBRR0L>::reg_set(ul);
  hal::HalRegAccess<std::uint8_t, std::uint8_t, hal::UBRR0H>::reg_set(uh);

  const std::uint8_t U2X0 = 1;
  hal::HalRegAccess<std::uint8_t, std::uint8_t, hal::UCSR0A>::reg_and(
      (1 << U2X0));
  hal::HalRegAccess<std::uint8_t, std::uint8_t, hal::UCSR0B>::reg_set_bits(
      hal::TXEN0, hal::RXEN0);
  hal::HalRegAccess<std::uint8_t, std::uint8_t, hal::UCSR0C>::reg_set_bits(
      hal::UCSZ01, hal::UCSZ00);
}

void hal::HalUsart::transmit_byte_no_blocking(std::uint8_t data)
{
  if (this->buffer_is_empty())
  {
    hal::set_reg(hal::UDR0, data);
  }
}

bool hal::HalUsart::buffer_is_empty()
{
  return static_cast<bool>((hal::reg_bit_set(hal::UCSR0A, hal::UDRE0)));
}
