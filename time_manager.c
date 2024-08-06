#include "regbase.h"
#include <stdio.h>
#include <stdint.h>
#include "mcu_init.h"
#include "module_EXTI.h"
#include "module_rtc.h"
#include "module_GPIO.h"
#include "reg_access.h"

void RTC_Alarm_IRQHandler(void) {
  // irq
  REG(GPIO_BASE_PORT_C + 0x0C) ^= 1u << 13u;
}

int main(void) {
  time_manager_init();
  time_manager_EXTI_enable();
  time_manager_RTC_init();
  time_manager_GPIO_init();

  while(1){
    // main loop
  }
  return 0;
}
