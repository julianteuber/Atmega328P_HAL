/*
 * timers_328P.h
 *
 * Created: 05.05.2020
 * Author : Julian Teuber
 */

#ifndef TIMERS_328P_H_
#define TIMERS_328P_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

typedef enum{
	TIMER0,
	TIMER1,
	TIMER2
}TIMER_NUMBER;

typedef enum{
	POWER_UP,
	POWER_DOWN
}POWER_STATE;

typedef enum{
	CLOCK_NC,						// No clock source (Timer/Counter stopped)
	CLOCK_PRESC_0,					// clkI/O/(no prescaling)
	CLOCK_PRESC_8,					// clkI/O/8 (from prescaler)
	CLOCK_PRESC_32,					// clkI/O/32 (from prescaler)
	CLOCK_PRESC_64,					// clkI/O/64 (from prescaler)
	CLOCK_PRESC_128,				// clkI/O/128 (from prescaler)
	CLOCK_PRESC_256,				// clkI/O/256 (from prescaler)
	CLOCK_PRESC_1024,				// clkI/O/1024 (from prescaler)
	CLOCK_EXT_EDGEF,				// External clock source on T0 pin. Clock on falling edge.
	CLOCK_EXT_EDGER					// External clock source on T0 pin. Clock on rising edge.
}CLOCK_SOURCE;

typedef enum{
	OVERFLOW_FLAG,					// all Timer/Counters
	OUTPUT_COMPARE_A,				// all Timer/Counters
	OUTPUT_COMPARE_B,				// all Timer/Counters
	INPUT_CAPTURE					// Timer/Counter1 only
}INTERRUPT_SOURCE;

/*
Waveform Generation Mode Bit Description
TCCR2A and TCCR0A Timer/Counter Control Register A

// Mode | Operation          | TOP  | Update of OCRx at | TOV Flag Set on
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 0    | Normal             | 0xFF | Immediate         | MAX
// 1    | PWM, phase correct | 0xFF | TOP               | BOTTOM
// 2    | CTC                | OCRA | Immediate         | MAX
// 3    | Fast PWM           | 0xFF | BOTTOM            | MAX
// 4    | Reserved           | –    | –                 | –
// 5    | PWM, phase correct | OCRA | TOP               | BOTTOM
// 6    | Reserved           | –    | –                 | –
// 7    | Fast PWM           | OCRA | BOTTOM            | TOP

TCCR1A Timer/Counter Control Register A

// Mode | Timer/Counter Mode of        | Operation TOP | Update of OCR1x at | TOV1 Flag Set on |
// 0    | Normal                       | 0xFFFF        | Immediate          | MAX
// 1    | PWM, phase correct, 8-bit    | 0x00FF        | TOP                | BOTTOM
// 2    | PWM, phase correct, 9-bit    | 0x01FF        | TOP                | BOTTOM
// 3    | PWM, phase correct, 10-bit   | 0x03FF        | TOP                | BOTTOM
// 4    | CTC                          | OCR1A         | Immediate          | MAX
// 5    | Fast PWM, 8-bit              | 0x00FF        | BOTTOM             | TOP
// 6    | Fast PWM, 9-bit              | 0x01FF        | BOTTOM             | TOP
// 7    | Fast PWM, 10-bit             | 0x03FF        | BOTTOM             | TOP
// 8    | PWM, phase+frequency correct | ICR1          | BOTTOM             | BOTTOM
// 9    | PWM, phase+frequency correct | OCR1A         | BOTTOM             | BOTTOM
// 10   | PWM, phase correct           | ICR1          | TOP                | BOTTOM
// 11   | PWM, phase correct           | OCR1A         | TOP                | BOTTOM
// 12   | CTC                          | ICR1          | Immediate          | MAX
// 13   | (Reserved)                   | -             | –                  | –
// 14   | Fast PWM                     | ICR1          | BOTTOM             | TOP
// 15   | Fast PWM                     | OCR1A         | BOTTOM             | TOP
*/

typedef enum{
	WG_MODE_0,
	WG_MODE_1,
	WG_MODE_2,
	WG_MODE_3,
	WG_MODE_4,
	WG_MODE_5,
	WG_MODE_6,
	WG_MODE_7,
	WG_MODE_8,
	WG_MODE_9,
	WG_MODE_10,
	WG_MODE_11,
	WG_MODE_12,
	WG_MODE_13,
	WG_MODE_14,
	WG_MODE_15
}WAVE_GENERATION_MODE;

typedef enum{
	OUTPUT_COMPARE_REGA,
	OUTPUT_COMPARE_REGB
}OUTPUT_COMPARE_REGISTER;

typedef enum{			/* compare output function depending on waveform generator mode */
	CO_MODE_0,
	CO_MODE_1,
	CO_MODE_2,
	CO_MODE_3
}OUTPUT_COMPARE_MODE;

// function-like macros
#define timer_two_async() (ASSR |= (1 << AS2))

#define timer_stop_zero() (TCCR0B &= ~((1<<CS02)|(1<<CS01)|(1<<CS00)))
#define timer_stop_one() (TCCR1B &= ~((1<<CS12)|(1<<CS11)|(1<<CS10)))
#define timer_stop_two() (TCCR2B &= ~((1<<CS22)|(1<<CS21)|(1<<CS20)))

#define timer_clear_zero() (TCNT0 = 0x00)
#define timer_clear_one() (TCNT1 = 0x0000)
#define timer_clear_two() (TCNT2 = 0x00)

#define timer_powerup_zero() (PRR &= ~(1<<PRTIM0))
#define timer_powerup_one() (PRR &= ~(1<<PRTIM1))
#define timer_powerup_two() (PRR &= ~(1<<PRTIM2))

#define timer_powerdown_zero() (PRR |= (1<<PRTIM0))
#define timer_powerdown_one() (PRR |= (1<<PRTIM1))
#define timer_powerdown_two() (PRR |= (1<<PRTIM2))

extern uint8_t timer_waveform_generation_mode(TIMER_NUMBER timerNumber, WAVE_GENERATION_MODE wgMode);
extern uint8_t timer_clock_select(TIMER_NUMBER timerNumber, CLOCK_SOURCE clkSource);
extern uint8_t timer_compare_mode(TIMER_NUMBER timerNumber, OUTPUT_COMPARE_REGISTER ocReg, OUTPUT_COMPARE_MODE ocMode);
extern uint8_t timer_stop(TIMER_NUMBER timerNumber);
inline void timer_stop_all( void ){timer_stop_zero(); timer_stop_one(); timer_stop_two();}

extern void timer_powerup(TIMER_NUMBER timerNumber);
extern void timer_powerdown(TIMER_NUMBER timerNumber);
inline void timer_powerup_all(){timer_powerup_zero(); timer_powerup_one(); timer_powerup_two();}
inline void timer_powerdown_all(){timer_powerdown_zero(); timer_powerdown_one(); timer_powerdown_two();}
extern uint8_t timer_power(TIMER_NUMBER timerNumber, POWER_STATE powerState);

extern void timer_set(TIMER_NUMBER timerNumber, uint16_t value);
inline void timer_clear(TIMER_NUMBER timerNumber){timer_set(timerNumber, (uint16_t)0x00);}
inline void timer_clear_all( void ){timer_clear_zero(); timer_clear_one(); timer_clear_two();}
extern void timer_compare_pin_enable(TIMER_NUMBER timerNumber, OUTPUT_COMPARE_REGISTER ocReg);
extern void timer_set_compare_val(TIMER_NUMBER timerNumber, OUTPUT_COMPARE_REGISTER ocReg, uint16_t value);

extern void timer_interrupt_enable(TIMER_NUMBER timerNumber, INTERRUPT_SOURCE irqSource);
extern void timer_interrupt_disable(TIMER_NUMBER timerNumber, INTERRUPT_SOURCE irqSource);

#endif /* TIMERS_328P_H_ */