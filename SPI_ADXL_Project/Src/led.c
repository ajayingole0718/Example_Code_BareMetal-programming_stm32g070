/*
 * led.c
 *
 *  Created on: Sep 5, 2025
 *      Author: Ajay Ingole
 */
#include "led.h"

void led_gpioaINIT(void){
	RCC->IOPENR |= (1U<<0);
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~ (1U<<11);
}

void LED_ON(void){
	GPIOA->ODR |= (1U<<5);
}
void LED_OFF(void){
	GPIOA->ODR &=~ (1U<<5);
}

void delay(void){
	//for(int i=0; i<1000000; i++){}
}
