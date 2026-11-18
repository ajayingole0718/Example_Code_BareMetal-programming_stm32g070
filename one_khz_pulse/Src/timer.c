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

	//SET FREQUENCY FOR THE 1KHZ
	TIM3->PSC = 16000 - 1;
	//SET THE OUTPUT ARR
	TIM3->ARR = 250 - 1;
	//configuration output comapre mode to "Toggle" mode on channel 1
	//cmapture comapre mode register
	TIM3->CCMR1 |= (1U<<4);
	TIM3->CCMR1 |= (1U<<5);
	TIM3->CCMR1 &=~ (1U<<6);

	//Initailize Compre Value  (capture compare register 1)
	TIM3->CCR1 = 0; //the pin will toggle every time CNT hits 0 (and reset via ARR)

	//enable output and start timer hardware
	//enable channle 1 output to physical pin

	TIM3->CCER |= (1U<<0);            // cc1e bit
	//enable counter
	TIM3->CR1 |= (1U<<0);			  // CNE
}
