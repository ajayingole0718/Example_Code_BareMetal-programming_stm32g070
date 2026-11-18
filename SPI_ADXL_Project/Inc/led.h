/*
 * led.h
 *
 *  Created on: Sep 5, 2025
 *      Author: Ajay Ingole
 */

#ifndef LED_H_
#define LED_H_
#include "stm32g070xx.h"
void led_gpioaINIT(void);
void LED_ON(void);
void LED_OFF(void);
void delay(void);
#endif /* LED_H_ */
