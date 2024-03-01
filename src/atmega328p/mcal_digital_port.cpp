#include "mcal_digital_port.h"
#include "mcal_reg.h"

  template<typename addr_t, typename reg_t, const std::uint8_t port_idx>  
  void tlm::dpo::McalDigitalPort<addr_t,reg_t,port_idx>::set_port(reg_t val) 
  {
        *reinterpret_cast<volatile addr_t*>(mcal::r::port[port_idx])=static_cast<reg_t>(val);
  }