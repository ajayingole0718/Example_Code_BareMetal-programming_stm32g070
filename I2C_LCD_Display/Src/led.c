/*
 * led.c
 *
 *  Created on: Sep 19, 2026
 *      Author: HP
 */

#include "led.h"

void gpio_init(void){
	RCC->IOPENR |=  (1U<<0);
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~ (1U<<11);
}

void led_on(void){
	gpio_init();
	GPIOA->ODR |= (1U<<5);
}
void led_off(void){
	gpio_init();
	GPIOA->ODR &=~ (1U<<5);
}
