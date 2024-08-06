#include <stdint.h>
#include "regbase.h"
#include "reg_access.h"

// GPIO_BASE

#define GPIOC_CONFIG_LOW (GPIO_BASE_PORT_C + 0)
#define GPIOC_CONFIG_HIGH (GPIO_BASE_PORT_C + 0x04)
#define GPIOC_INPUT_DATA (GPIO_BASE_PORT_C + 0x08)
#define GPIOC_OUTPUT_DATA (GPIO_BASE_PORT_C + 0x0C)
#define GPIOC_SET_RESET (GPIO_BASE_PORT_C + 0x10)
#define GPIOC_RESET (GPIO_BASE_PORT_C + 0x14)
#define GPIOC_CONFIG_LOCK (GPIO_BASE_PORT_C + 0x18)

void time_manager_GPIO_init(void) {
  volatile uint32_t portC_config = REG(GPIOC_CONFIG_HIGH);
  portC_config &= ~(3u << 22u); 
  portC_config &= ~(3u << 20u);
  portC_config |= (0 << 22u); 
  portC_config |= (1u << 20u); 
  REG(GPIOC_CONFIG_HIGH) = portC_config;
}
