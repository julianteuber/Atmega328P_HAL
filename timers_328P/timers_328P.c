/*
 * timers_328P.c
 *
 * Created: 05.05.2020
 * Author : Julian Teuber
 */

#include "timers_328P.h"

uint8_t timer_waveform_generation_mode(TIMER_NUMBER timerNumber, WAVE_GENERATION_MODE wgMode)
{
	if(timerNumber == TIMER0)
	{
		switch(wgMode)
		{
			case WG_MODE_0:
				TCCR0A &= (~((1 << WGM01)|(1 << WGM00)));
				TCCR0B &= (~(1 << WGM02));
				break;
			case WG_MODE_1:
				TCCR0A = (TCCR0A & 0xF0) | (1 << WGM00);
				TCCR0B &= (~(1 << WGM02));
				break;
			case WG_MODE_2:
				TCCR0A = (TCCR0A & 0xF0) | (1 << WGM01);
				TCCR0B &= (~(1 << WGM02));
				break;
			case WG_MODE_3:
				TCCR0A = (TCCR0A & 0xF0) | ((1 << WGM00)|(1 << WGM01));
				TCCR0B &= (~(1 << WGM02));
				break;
			case WG_MODE_4:
				TCCR0A &= (~((1 << WGM01)|(1 << WGM00)));
				TCCR0B |= (1 << WGM02);
				break;
			case WG_MODE_5:
				TCCR0A = (TCCR0A & 0xF0) | (1 << WGM00);
				TCCR0B |= (1 << WGM02);
				break;
			case WG_MODE_6:
				TCCR0A = (TCCR0A & 0xF0) | (1 << WGM01);
				TCCR0B |= (1 << WGM02);
				break;
			case WG_MODE_7:
				TCCR0A = (TCCR0A & 0xF0) | ((1 << WGM00)|(1 << WGM01));
				TCCR0B |= (1 << WGM02);
				break;
			default: return 0;	/* error: waveform generation mode not available for this timer */
		}
		return 1;
	}
	
	if(timerNumber == TIMER1)
	{
		switch(wgMode)
		{
			case WG_MODE_0:
				TCCR1A &= ~((1 << WGM10)|(1 << WGM11));
				TCCR1B &= ~((1 << WGM12)|(1 << WGM13));
				break;
			case WG_MODE_1:
				TCCR1A = (TCCR1A & ~(1 << WGM11)) | (1 << WGM10);
				TCCR1B &= ~((1 << WGM12)|(1 << WGM13));
				break;
			case WG_MODE_2:
				TCCR1A = (TCCR1A & ~(1 << WGM10)) | (1 << WGM11);
				TCCR1B &= ~((1 << WGM12)|(1 << WGM13));
				break;
			case WG_MODE_3:
				TCCR1A |= ((1 << WGM10)|(1 << WGM11));
				TCCR1B &= ~((1 << WGM12)|(1 << WGM13));
				break;
			case WG_MODE_4:
				TCCR1A &= ~((1 << WGM10)|(1 << WGM11));
				TCCR1B = (TCCR1B & ~(1 << WGM13)) | (1 << WGM12);
				break;
			case WG_MODE_5:
				TCCR1A = (TCCR1A & ~(1 << WGM11)) | (1 << WGM10);
				TCCR1B = (TCCR1B & ~(1 << WGM13)) | (1 << WGM12);
				break;
			case WG_MODE_6:
				TCCR1A = (TCCR1A & ~(1 << WGM10)) | (1 << WGM11);
				TCCR1B = (TCCR1B & ~(1 << WGM13)) | (1 << WGM12);
				break;
			case WG_MODE_7:
				TCCR1A |= ((1 << WGM10)|(1 << WGM11));
				TCCR1B = (TCCR1B & ~(1 << WGM13)) | (1 << WGM12);
				break;
			case WG_MODE_8:
				TCCR1A &= ~((1 << WGM10)|(1 << WGM11));
				TCCR1B = (TCCR1B & ~(1 << WGM12)) | (1 << WGM13);
				break;
			case WG_MODE_9:
				TCCR1A = (TCCR1A & ~(1 << WGM11)) | (1 << WGM10);
				TCCR1B = (TCCR1B & ~(1 << WGM12)) | (1 << WGM13);
				break;
			case WG_MODE_10:
				TCCR1A = (TCCR1A & ~(1 << WGM10)) | (1 << WGM11);
				TCCR1B = (TCCR1B & ~(1 << WGM12)) | (1 << WGM13);
				break;
			case WG_MODE_11:
				TCCR1A |= ((1 << WGM10)|(1 << WGM11));
				TCCR1B = (TCCR1B & ~(1 << WGM12)) | (1 << WGM13);
				break;
			case WG_MODE_12:
				TCCR1A &= ~((1 << WGM10)|(1 << WGM11));
				TCCR1B |= ((1 << WGM12)|(1 << WGM13));
				break;
			case WG_MODE_13:
				TCCR1A = (TCCR1A & ~(1 << WGM11)) | (1 << WGM10);
				TCCR1B |= ((1 << WGM12)|(1 << WGM13));
				break;
			case WG_MODE_14:
				TCCR1A = (TCCR1A & ~(1 << WGM10)) | (1 << WGM11);
				TCCR1B |= ((1 << WGM12)|(1 << WGM13));
				break;
			case WG_MODE_15:
				TCCR1A |= ((1 << WGM10)|(1 << WGM11));
				TCCR1B |= ((1 << WGM12)|(1 << WGM13));
				break;
			default: return 0;	/* error: waveform generation mode not available for this timer */
		}
		return 1;
	}
	
	if(timerNumber == TIMER2)
	{
		switch(wgMode)
		{
			case WG_MODE_0:
				TCCR2A &= (~((1 << WGM21)|(1 << WGM20)));
				TCCR2B &= (~(1 << WGM22));
				break;
			case WG_MODE_1:
				TCCR2A = (TCCR2A & 0xF0) | (1 << WGM20);
				TCCR2B &= (~(1 << WGM22));
				break;
			case WG_MODE_2:
				TCCR2A = (TCCR2A & 0xF0) | (1 << WGM21);
				TCCR2B &= (~(1 << WGM22));
				break;
			case WG_MODE_3:
				TCCR2A = (TCCR2A & 0xF0) | ((1 << WGM20)|(1 << WGM21));
				TCCR2B &= (~(1 << WGM22));
				break;
			case WG_MODE_4:
				TCCR2A &= (~((1 << WGM21)|(1 << WGM20)));
				TCCR2B |= (1 << WGM22);
				break;
			case WG_MODE_5:
				TCCR2A = (TCCR2A & 0xF0) | (1 << WGM20);
				TCCR2B |= (1 << WGM22);
				break;
			case WG_MODE_6:
				TCCR2A = (TCCR2A & 0xF0) | (1 << WGM21);
				TCCR2B |= (1 << WGM22);
				break;
			case WG_MODE_7:
				TCCR2A = (TCCR2A & 0xF0) | ((1 << WGM20)|(1 << WGM21));
				TCCR2B |= (1 << WGM22);
				break;
			default: return 0;	/* error: waveform generation mode not available for this timer */
		}
		return 1;
	}
	return 0; /* error: timerNumber does not exist */
}

uint8_t timer_compare_mode(TIMER_NUMBER timerNumber, OUTPUT_COMPARE_REGISTER ocReg, OUTPUT_COMPARE_MODE ocMode)
{
	if(ocReg == OUTPUT_COMPARE_REGA)
	{
		if(timerNumber == TIMER0)
		{
			switch(ocMode)
			{
				case CO_MODE_0: TCCR0A &= ~((1<<COM0A0)|(1<<COM0A1)); break;
				case CO_MODE_1: TCCR0A = (TCCR0A & ~(1<<COM0A1)) | (1<<COM0A0); break;
				case CO_MODE_2: TCCR0A = (TCCR0A & ~(1<<COM0A0)) | (1<<COM0A1); break;
				case CO_MODE_3: TCCR0A |= ((1<<COM0A1) | (1<<COM0A0)); break;
				default: return 0;
			}
			return 1;
		}
		
		if(timerNumber == TIMER1)
		{
			switch(ocMode)
			{
				case CO_MODE_0: TCCR1A &= ~((1<<COM1A0)|(1<<COM1A1)); break;
				case CO_MODE_1: TCCR1A = (TCCR1A & ~(1<<COM1A1)) | (1<<COM1A0); break;
				case CO_MODE_2: TCCR1A = (TCCR1A & ~(1<<COM1A0)) | (1<<COM1A1); break;
				case CO_MODE_3: TCCR1A |= ((1<<COM1A1) | (1<<COM1A0)); break;
				default: return 0;
			}
			return 1;
		}
		
		if(timerNumber == TIMER2)
		{
			switch(ocMode)
			{
				case CO_MODE_0: TCCR2A &= ~((1<<COM2A0)|(1<<COM2A1)); break;
				case CO_MODE_1: TCCR2A = (TCCR2A & ~(1<<COM2A1)) | (1<<COM2A0); break;
				case CO_MODE_2: TCCR2A = (TCCR2A & ~(1<<COM2A0)) | (1<<COM2A1); break;
				case CO_MODE_3: TCCR2A |= ((1<<COM2A1) | (1<<COM2A0)); break;
				default: return 0;
			}
			return 1;
		}
		return 0;
	}
	if(ocReg == OUTPUT_COMPARE_REGB)
	{
		if(timerNumber == TIMER0)
		{
			switch(ocMode)
			{
				case CO_MODE_0: TCCR0B &= ~((1<<COM0B0)|(1<<COM0B1)); break;
				case CO_MODE_1: TCCR0B = (TCCR0B & ~(1<<COM0B1)) | (1<<COM0B0); break;
				case CO_MODE_2: TCCR0B = (TCCR0B & ~(1<<COM0B0)) | (1<<COM0B1); break;
				case CO_MODE_3: TCCR0B |= ((1<<COM0B1) | (1<<COM0B0)); break;
				default: return 0;
			}
			return 1;
		}
		
		if(timerNumber == TIMER1)
		{
			switch(ocMode)
			{
				case CO_MODE_0: TCCR1B &= ~((1<<COM1B0)|(1<<COM1B1)); break;
				case CO_MODE_1: TCCR1B = (TCCR1B & ~(1<<COM1B1)) | (1<<COM1B0); break;
				case CO_MODE_2: TCCR1B = (TCCR1B & ~(1<<COM1B0)) | (1<<COM1B1); break;
				case CO_MODE_3: TCCR1B |= ((1<<COM1B1) | (1<<COM1B0)); break;
				default: return 0;
			}
			return 1;
		}
		
		if(timerNumber == TIMER2)
		{
			switch(ocMode)
			{
				case CO_MODE_0: TCCR2B &= ~((1<<COM2B0)|(1<<COM2B1)); break;
				case CO_MODE_1: TCCR2B = (TCCR2B & ~(1<<COM2B1)) | (1<<COM2B0); break;
				case CO_MODE_2: TCCR2B = (TCCR2B & ~(1<<COM2B0)) | (1<<COM2B1); break;
				case CO_MODE_3: TCCR2B |= ((1<<COM2B1) | (1<<COM2B0)); break;
				default: return 0;
			}
			return 1;
		}
		return 0;
	}
	return 0;
	
}

uint8_t timer_clock_select(TIMER_NUMBER timerNumber, CLOCK_SOURCE clkSource)
{
	if (timerNumber == TIMER0)
	{
		switch(clkSource)
		{
			case CLOCK_NC:			TCCR0B &= ~((1<<CS02)|(1<<CS01)|(1<<CS00)); break;
			case CLOCK_PRESC_0:		TCCR0B = (TCCR0B & ~((1<<CS01)|(1<<CS02))) | (1<<CS00); break;
			case CLOCK_PRESC_8:		TCCR0B = (TCCR0B & ~((1<<CS00)|(1<<CS02))) | (1<<CS01); break;
			case CLOCK_PRESC_64:	TCCR0B = (TCCR0B & ~(1<<CS02)) | ((1<<CS00)|(1<<CS01)); break;
			case CLOCK_PRESC_256:	TCCR0B = (TCCR0B & ~((1<<CS00)|(1<<CS01))) | (1<<CS02); break;
			case CLOCK_PRESC_1024:	TCCR0B = (TCCR0B & ~(1<<CS01)) | ((1<<CS00)|(1<<CS02)); break;
			case CLOCK_EXT_EDGEF:	TCCR0B = (TCCR0B & ~(1<<CS00)) | ((1<<CS01)|(1<<CS02)); break;
			case CLOCK_EXT_EDGER:	TCCR0B |= ((1<<CS00)|(1<<CS01)|(1<<CS02)); break;
			default: return 0; 	/* error: clock source not available for this timer */
		}
		return 1;
	}
	
	if (timerNumber == TIMER1)
	{
		switch(clkSource)
		{
			case CLOCK_NC:			TCCR1B &= ~((1<<CS12)|(1<<CS11)|(1<<CS10)); break;
			case CLOCK_PRESC_0:		TCCR1B = (TCCR1B & ~((1<<CS11)|(1<<CS12))) | (1<<CS10); break;
			case CLOCK_PRESC_8:		TCCR1B = (TCCR1B & ~((1<<CS10)|(1<<CS12))) | (1<<CS11); break;
			case CLOCK_PRESC_64:	TCCR1B = (TCCR1B & ~(1<<CS12)) | ((1<<CS10)|(1<<CS11)); break;
			case CLOCK_PRESC_256:	TCCR1B = (TCCR1B & ~((1<<CS10)|(1<<CS11))) | (1<<CS12); break;
			case CLOCK_PRESC_1024:	TCCR1B = (TCCR1B & ~(1<<CS11)) | ((1<<CS10)|(1<<CS12)); break;
			case CLOCK_EXT_EDGEF:	TCCR1B = (TCCR1B & ~(1<<CS10)) | ((1<<CS11)|(1<<CS12)); break;
			case CLOCK_EXT_EDGER:	TCCR1B |= ((1<<CS10)|(1<<CS11)|(1<<CS12)); break;
			default: return 0; 	/* error: clock source not available for this timer */
		}
		return 1;
	}
	
	if (timerNumber == TIMER2)
	{
		switch(clkSource)
		{
			case CLOCK_NC:			TCCR2B &= ~((1<<CS22)|(1<<CS21)|(1<<CS20)); break;
			case CLOCK_PRESC_0:		TCCR2B = (TCCR2B & ~((1<<CS21)|(1<<CS22))) | (1<<CS20); break;
			case CLOCK_PRESC_8:		TCCR2B = (TCCR2B & ~((1<<CS20)|(1<<CS22))) | (1<<CS21); break;
			case CLOCK_PRESC_32:	TCCR2B = (TCCR2B & ~(1<<CS22)) | ((1<<CS20)|(1<<CS21)); break;
			case CLOCK_PRESC_64:	TCCR2B = (TCCR2B & ~((1<<CS20)|(1<<CS21))) | (1<<CS22); break;
			case CLOCK_PRESC_128:	TCCR2B = (TCCR2B & ~(1<<CS21)) | ((1<<CS20)|(1<<CS22)); break;
			case CLOCK_PRESC_256:	TCCR2B = (TCCR2B & ~(1<<CS20)) | ((1<<CS21)|(1<<CS22)); break;
			case CLOCK_PRESC_1024:	TCCR2B |= ((1<<CS20)|(1<<CS21)|(1<<CS22)); break;
			default: return 0; 	/* error: clock source not available for this timer */
		}
		return 1;
	}
	return 0; /* error: timerNumber does not exist */
}

uint8_t timer_stop(TIMER_NUMBER timerNumber)
{
	timer_clock_select(timerNumber, CLOCK_NC);
	return 1;
}

uint8_t timer_power(TIMER_NUMBER timerNumber, POWER_STATE powerState)
{
	if(powerState == POWER_UP)
	{
		switch(timerNumber)
		{
			case TIMER0: PRR &= ~(1<<PRTIM0); break;
			case TIMER1: PRR &= ~(1<<PRTIM1); break;
			case TIMER2: PRR &= ~(1<<PRTIM2); break;
			default: return 0;
		}
		return 1;
	}
	if(powerState == POWER_DOWN)
	{
		switch(timerNumber)
		{
			case TIMER0: PRR |= (1<<PRTIM0); break;
			case TIMER1: PRR |= (1<<PRTIM1); break;
			case TIMER2: PRR |= (1<<PRTIM2); break;
			default: return 0;
		}
		return 1;
	}
	return 0;
}

void timer_powerup(TIMER_NUMBER timerNumber)
{
	switch(timerNumber)
	{
		case TIMER0: PRR &= ~(1<<PRTIM0); break;
		case TIMER1: PRR &= ~(1<<PRTIM1); break;
		case TIMER2: PRR &= ~(1<<PRTIM2); break;
		default: return;
	}
	return;
}

void timer_powerdown(TIMER_NUMBER timerNumber)
{
	switch(timerNumber)
	{
		case TIMER0: PRR |= (1<<PRTIM0); break;
		case TIMER1: PRR |= (1<<PRTIM1); break;
		case TIMER2: PRR |= (1<<PRTIM2); break;
		default: return;
	}
	return;
}

extern void timer_set(TIMER_NUMBER timerNumber, uint16_t value)
{
	switch(timerNumber)
	{
		case TIMER1: TCNT1 = value; break;
		case TIMER0: TCNT0 = (uint8_t)value; break;
		case TIMER2: TCNT2 = (uint8_t)value; break;
		default: return;
	}
	return;
}

void timer_compare_pin_enable(TIMER_NUMBER timerNumber, OUTPUT_COMPARE_REGISTER ocReg)
{
	if(ocReg == OUTPUT_COMPARE_REGA)
	{
		switch(timerNumber)
		{
			case TIMER0: DDRD |= (1<<PORTD6); break;
			case TIMER1: DDRB |= (1<<PORTB1); break;
			case TIMER2: DDRB |= (1<<PORTB3); break;
			default: return;
		}
		return;
	}
	
	if(ocReg == OUTPUT_COMPARE_REGB)
	{
		switch(timerNumber)
		{
			case TIMER0: DDRD |= (1<<PORTD5); break;
			case TIMER1: DDRB |= (1<<PORTB2); break;
			case TIMER2: DDRD |= (1<<PORTD3); break;
			default: return;
		}
		return;
	}
	return;
}

void timer_set_compare_val(TIMER_NUMBER timerNumber, OUTPUT_COMPARE_REGISTER ocReg, uint16_t value)
{
	if(ocReg == OUTPUT_COMPARE_REGA)
	{
		switch(timerNumber)
		{
			case TIMER1: OCR1A = value; break;
			case TIMER0: OCR0A = (uint8_t)value; break;
			case TIMER2: OCR2A = (uint8_t)value; break;
			default: return;
		}
		return;
	}
	if(ocReg == OUTPUT_COMPARE_REGB)
	{
		switch(timerNumber)
		{
			case TIMER1: OCR1B = value; break;
			case TIMER0: OCR0B = (uint8_t)value; break;
			case TIMER2: OCR2B = (uint8_t)value; break;
			default: return;
		}
		return;
	}
	return;
}

void timer_interrupt_enable(TIMER_NUMBER timerNumber, INTERRUPT_SOURCE irqSource)
{
	if (timerNumber == TIMER0)
	{
		switch(irqSource)
		{
			case OUTPUT_COMPARE_A: TIMSK0 |= (1 << OCIE0A); break;
			case OUTPUT_COMPARE_B: TIMSK0 |= (1 << OCIE0B); break;
			case OVERFLOW_FLAG: TIMSK0 |= (1 << TOIE0); break;
			default: return;
		}
		return;
	}
	
	if (timerNumber == TIMER1)
	{
		switch(irqSource)
		{
			case INPUT_CAPTURE: TIMSK1 |= (1 << ICIE1); break;
			case OUTPUT_COMPARE_A: TIMSK1 |= (1 << OCIE1A); break;
			case OUTPUT_COMPARE_B: TIMSK1 |= (1 << OCIE1B); break;
			case OVERFLOW_FLAG: TIMSK1 |= (1 << TOIE1); break;
			default: return;
		}
		return;
	}
	
	if (timerNumber == TIMER2)
	{
		switch(irqSource)
		{
			case OUTPUT_COMPARE_A: TIMSK2 |= (1 << OCIE2A); break;
			case OUTPUT_COMPARE_B: TIMSK2 |= (1 << OCIE2B); break;
			case OVERFLOW_FLAG: TIMSK2 |= (1 << TOIE2); break;
			default: return;
		}
		return;
	}
}

void timer_interrupt_disable(TIMER_NUMBER timerNumber, INTERRUPT_SOURCE irqSource)
{
	if (timerNumber == TIMER0)
	{
		switch(irqSource)
		{
			case OUTPUT_COMPARE_A: TIMSK0 &= ~(1 << OCIE0A); break;
			case OUTPUT_COMPARE_B: TIMSK0 &= ~(1 << OCIE0B); break;
			case OVERFLOW_FLAG: TIMSK0 &= ~(1 << TOIE0); break;
			default: return;
		}
		return;
	}
	
	if (timerNumber == TIMER1)
	{
		switch(irqSource)
		{
			case INPUT_CAPTURE: TIMSK1 &= ~(1 << ICIE1); break;
			case OUTPUT_COMPARE_A: TIMSK1 &= ~(1 << OCIE1A); break;
			case OUTPUT_COMPARE_B: TIMSK1 &= ~(1 << OCIE1B); break;
			case OVERFLOW_FLAG: TIMSK1 &= ~(1 << TOIE1); break;
			default: return;
		}
		return;
	}
	
	if (timerNumber == TIMER2)
	{
		switch(irqSource)
		{
			case OUTPUT_COMPARE_A: TIMSK2 &= ~(1 << OCIE2A); break;
			case OUTPUT_COMPARE_B: TIMSK2 &= ~(1 << OCIE2B); break;
			case OVERFLOW_FLAG: TIMSK2 &= ~(1 << TOIE2); break;
			default: return;
		}
		return;
	}
}