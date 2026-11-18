/*
 * timer.c
 *
 *  Created on: Oct 6, 2026
 *      Author: HP
 */

#include "timer.h"

void tim3_init(void){
	RCC->IOPENR |= (1U<<0);		//clock gpio A

	//set the pa6 to alt mode
	GPIOA->MODER &=~ (1U<<12);
	GPIOA->MODER |= (1U<<13);

	//	Set alternate function type
	GPIOA->AFR[0] |= (1U<<24);
	GPIOA->AFR[0] &=~ (1U<<25);
	GPIOA->AFR[0] &=~ (1U<<26);
	GPIOA->AFR[0] &=~ (1U<<27);

	// ENABLE CLOCK FOR THE TIM3

	RCC->APBENR1 |= (1U<<1);

	//Set the time clock to 1 MHZ
	TIM3->PSC = 16 - 1;
	//Set the auto reload resisto to 1000 ticks
	TIM3->ARR = 1000 - 1;
	// configure the channel 1 to the PWM mode
	TIM3->CCMR1 &=~ (1U<<4);
	TIM3->CCMR1 |= (1U<<5);
	TIM3->CCMR1 |= (1U<<6);

	//Your duty cycle changes wait smoothly for the next PWM cycle to start. OC1PE	output compare 1 preload enable
	TIM3->CCMR1 |= (1U<<3);
	//Auto reload preload enable
	TIM3->CR1 |= (1U<<7);
	//ENABLE CHANNLE 1 OUTPUT PIN CONNECTION
	TIM3->CCER |= (1U<<0);
	//START THE TIME3 COUNTER
	TIM3->CR1 |= (1U<<0);

}
