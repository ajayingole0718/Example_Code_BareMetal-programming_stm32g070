/*
 * led.h
 *
 *  Created on: Sep 19, 2026
 *      Author: HP
 */

#ifndef LED_H_
#define LED_H_
#include "stm32g070xx.h"

void gpio_init(void);
void led_on(void);
void led_off(void);

#endif /* LED_H_ */
