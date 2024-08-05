#include "regbase.h"

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
#define RTC_COUNTER_LOW (RTC_BASE + 0x24)

volatile unsigned int REG_RTC_CRH;

