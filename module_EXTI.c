#include <stdint.h>
#include "regbase.h"
#include "reg_access.h"

// EXTI_BASE

#define EXTI_INTERRUPT_MASK (EXTI_BASE + 0)
#define EXTI_EVENT_MASK (EXTI_BASE + 0x04)
#define EXTI_RISING_TRIGGER (EXTI_BASE + 0x08)
#define EXTI_FALLING_TRIGGER (EXTI_BASE + 0x0C)
#define EXTI_SOFTWARE_INTERRUPT (EXTI_BASE + 0x10)
#define EXTI_PENDING (EXTI_BASE + 0x14)

void time_manager_EXTI_enable(void) {
  REG(EXTI_INTERRUPT_MASK) |= 1u << 17u;
  REG(EXTI_RISING_TRIGGER) |= 1u << 17u;
}
