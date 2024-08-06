#include <stdint.h>
#include "regbase.h"
#include "mcu_init.h"
#include "reg_access.h"

// RCC_BASE

#define RCC_CLOCK_CONTROL (RCC_BASE + 0x00)
#define RCC_CONFIGURE (RCC_BASE + 0x04)
#define RCC_INTERRUPT (RCC_BASE + 0x08)
#define RCC_APB2_RESET (RCC_BASE + 0x0C)
#define RCC_APB1_RESET (RCC_BASE + 0x10)
#define RCC_AHB_ENABLE (RCC_BASE + 0x14)
#define RCC_APB2_ENABLE (RCC_BASE + 0x18)
#define RCC_APB1_ENABLE (RCC_BASE + 0x1c)
#define RCC_BACKUP_CONTROL (RCC_BASE + 0x20)
#define RCC_STATUS (RCC_BASE + 0x24)

void mcu_init(void) {
  //
}

void time_manager_init(void) {
  REG(RCC_APB2_ENABLE) |= 1 << 4; // clock port C
  REG(RCC_BACKUP_CONTROL) |=  1 << 8; // RTC clock source - LSE
  for (volatile uint32_t count = 0; count < 10;) {
    count++;
  } 
  REG(RCC_BACKUP_CONTROL) |=  1 << 15; // clock RTC 
  REG(RCC_BACKUP_CONTROL) |=  1 ; // LSE enable
  for (volatile uint32_t count = 0; count < 10;) {
    count++;
  } 
}
