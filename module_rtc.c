#include <stdint.h>
#include "regbase.h"
#include "reg_access.h"

// RTC_BASE

#define RTC_CONTROL_HIGH (RTC_BASE + 0)
#define RTC_CONTROL_LOW (RTC_BASE + 0x04)

#define RTC_PRESCALER_LOAD_HIGH (RTC_BASE + 0x08)
#define RTC_PRESCALER_LOAD_LOW (RTC_BASE + 0x0C)

#define RTC_DIV_HIGH (RTC_BASE + 0x10)
#define RTC_DIV_LOW (RTC_BASE + 0x14)

#define RTC_COUNTER_HIGH (RTC_BASE + 0x18)
#define RTC_COUNTER_LOW (RTC_BASE + 0x1C)

#define RTC_ALARM_HIGH (RTC_BASE + 0x20)
#define RTC_ALARM_LOW (RTC_BASE + 0x24)

void time_manager_RTC_init(void) {
  while((REG_16(RTC_CONTROL_LOW) & (1u << 5u)) != 1u << 5u){ } // Last RTC write finished

  REG_16(RTC_CONTROL_LOW) |= 1u << 4u; // Enter configuration mode 
  while((REG_16(RTC_CONTROL_LOW) & (1u << 5u)) != 1u << 5u){ } // Last RTC write finished

  REG_16(RTC_PRESCALER_LOAD_LOW) |= 0x7FFFu; // 1 sec for 32768 Hz of LSE
  while((REG_16(RTC_CONTROL_LOW) & (1u << 5u)) != 1u << 5u){ } // Last RTC write finished

  REG_16(RTC_ALARM_LOW) |= 10u; // 10 sec
  while((REG_16(RTC_CONTROL_LOW) & (1u << 5u)) != 1u << 5u){ } // Last RTC write finished

  REG_16(RTC_CONTROL_LOW) &= ~(1u << 1u); // Clear alarm flag (as HAL does in generated code)
  while((REG_16(RTC_CONTROL_LOW) & (1u << 5u)) != 1u << 5u){ } // Last RTC write finished

  REG_16(RTC_CONTROL_HIGH) |= 1u << 1u; // Enable RTC alarm interrupt
  while((REG_16(RTC_CONTROL_LOW) & (1u << 5u)) != 1u << 5u){ } // Last RTC write finished

  REG_16(RTC_CONTROL_LOW) &= ~(1u << 4u); // Leave cofiguration mode
  while((REG_16(RTC_CONTROL_LOW) & (1u << 5u)) != 1u << 5u){ } // Last RTC write finished
}
