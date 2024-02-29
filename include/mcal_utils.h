#include <cstdint>

namespace mcal
    {
        static std::uint8_t get_reg(std::uint8_t address)
        {
            return *reinterpret_cast<volatile std::uint8_t*>(address); 
        }


        static bool  get_bit(std::uint8_t address,std::uint8_t bit_pos)
        {
            return static_cast<bool>(get_reg(address)&(1 <<bit_pos));
        }
        
        static void  set_reg(const std::uint8_t address,std::uint8_t data)
        {
            *reinterpret_cast<volatile std::uint8_t*>(address) = static_cast<std::uint8_t>(data);
        }
    }