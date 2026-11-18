/*
 * timer.c
 *
 *  Created on: Oct 6, 2026
 *      Author: HP
 */

#include "timer.h"

void tim1_init(void){
	RCC->IOPENR |= (1U<<0);		//clock gpio A

	//set the pa6 to alt mode
	GPIOA->MODER &=~ (1U<<16);
	GPIOA->MODER |= (1U<<17);

	//	Set alternate function type
	GPIOA->AFR[1] &=~ (1U<<0);
	GPIOA->AFR[1] |= (1U<<1);
	GPIOA->AFR[1] &=~ (1U<<2);
	GPIOA->AFR[1] &=~ (1U<<3);

	// ENABLE CLOCK FOR THE TIM3

	RCC->APBENR2 |= (1U<<11);

	//Set the time clock to 1 MHZ
	TIM1->PSC = 16 - 1;
	//Set the auto reload resisto to 1000 ticks
	TIM1->ARR = 1000 - 1;
	// configure the channel 1 to the PWM mode
	TIM1->CCMR1 &=~ (1U<<4);
	TIM1->CCMR1 |= (1U<<5);
	TIM1->CCMR1 |= (1U<<6);

	//Your duty cycle changes wait smoothly for the next PWM cycle to start. OC1PE	output compare 1 preload enable
	TIM1->CCMR1 |= (1U<<3);
	//Auto reload preload enable
	TIM1->CR1 |= (1U<<7);
	//ENABLE CHANNLE 1 OUTPUT PIN CONNECTION
	TIM1->CCER |= (1U<<0);

	// 6. CRITICAL FOR ADVANCED TIMERS: Enable Main Output (MOE bit in BDTR)
	TIM1->BDTR |= (1U<<15);
	//START THE TIME3 COUNTER
	TIM1->CR1 |= (1U<<0);

}
