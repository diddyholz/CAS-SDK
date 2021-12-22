#ifndef _RTC_H
#define _RTC_H

#include <stdint.h>

#define DAY_SUN 0
#define DAY_MON 1
#define DAY_TUE 2
#define DAY_WED 3
#define DAY_THU 4
#define DAY_FRI 5
#define DAY_SAT 6

#define RTC_INT_DISABLE 0
#define RTC_INT_1DIV256 1
#define RTC_INT_1DIV64  2
#define RTC_INT_1DIV16  3
#define RTC_INT_1DIV4   4
#define RTC_INT_1DIV2   5
#define RTC_INT_1SEC    6
#define RTC_INT_2SEC    7

typedef struct
{
  uint8_t reserved : 1; // Reserved and set to 0
  uint8_t tens : 3; 		// The second digit (0 - 5)
  uint8_t ones : 4; 		// The first digit (0 - 9)
} rtc_counter_seconds_s;

typedef struct
{
  uint8_t reserved : 1; // Reserved and set to 0
  uint8_t tens : 3; 		// The second digit (0 - 5)
  uint8_t ones : 4; 		// The first digit (0 - 9)
} rtc_counter_minutes_s;

typedef struct
{
  uint8_t reserved : 2; // Reserved and set to 0
  uint8_t tens : 2; 		// The second digit (0 - 2)
  uint8_t ones : 4; 		// The first digit (0 - 9)
} rtc_counter_hours_s;

typedef struct
{
  uint8_t reserved : 5; 	// Reserved and set to 0
  uint8_t dayOfWeek : 3; 	// The day of the week (starting from sunday)
} rtc_counter_days_of_week_s;

typedef struct
{
  uint8_t reserved : 2; // Reserved and set to 0
  uint8_t tens : 2; 		// The second digit (0 - 3)
  uint8_t ones : 4; 		// The first digit (0 - 9)
} rtc_counter_dates_s;

typedef struct
{
  uint8_t reserved : 3; // Reserved and set to 0
  uint8_t tens : 1; 		// The second digit (0 - 1)
  uint8_t ones : 4; 		// The first digit (0 - 9)
} rtc_counter_months_s;

typedef struct
{
  uint8_t thousands : 4; 	// The fourth digit (0 - 9)
  uint8_t hundreds : 4; 	// The third digit (0 - 9)
  uint8_t tens : 4; 			// The second digit (0 - 9)
  uint8_t ones : 4; 			// The first digit (0 - 9)
} rtc_counter_years_s;

typedef struct
{
  uint8_t interrupt : 1; 				// This is set when an interrupt appears. Reset it to acknowledge the interrupt.
  uint8_t interrupt_period : 3; // Set how often interrupts happen
  uint8_t halt_rtc : 1; 				// Set to disable the oscillator for the RTC (This will completely halt it and the counters)
  uint8_t unknown : 1; 					// I have absolutely no idea what this does. Please check the prizm wiki RTC page and try to understand it :D 
  uint8_t reset_divider : 1; 		// Set to reset the divider circuit
  uint8_t counter_enable : 1; 	// Enable and disable all counters (the rtc itself will still continue pulsing)
} rtc_control_reg_s;

extern rtc_counter_seconds_s* rtc_counter_seconds; 					// Pointer to the counter for seconds (stored as digits). Stop the RTC before writing to this register.
extern rtc_counter_minutes_s* rtc_counter_minutes; 					// Pointer to the counter for minutes (stored as digits). Stop the RTC before writing to this register.
extern rtc_counter_hours_s* rtc_counter_hours; 							// Pointer to the counter for hours (stored as digits). Stop the RTC before writing to this register.
extern rtc_counter_days_of_week_s* rtc_counter_day_of_week; // Pointer to the counter for the day of the week (stored as digits). Stop the RTC before writing to this register.
extern rtc_counter_dates_s* rtc_counter_dates; 							// Pointer to the counter for dates (stored as digits). Stop the RTC before writing to this register.
extern rtc_counter_months_s* rtc_counter_months; 						// Pointer to the counter for months (stored as digits). Stop the RTC before writing to this register.
extern rtc_counter_years_s* rtc_counter_years; 							// Pointer to the counter for years (stored as digits). Stop the RTC before writing to this register.
extern rtc_control_reg_s* rtc_control_reg; 									// Pointer to the RTC control register

// Note that the RTC has to be stopped, whenever you want to overwrite a counter!
#endif
