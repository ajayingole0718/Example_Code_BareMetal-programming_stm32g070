/*
 * i2c.h
 *
 *  Created on: Sep 19, 2026
 *      Author: HP
 */

#ifndef I2C_H_
#define I2C_H_
#include "stm32g070xx.h"
void i2c_gpio_init(void);
void i2c_init(void);
void i2c_write_byte(uint8_t data);


#endif /* I2C_H_ */
