/*
 * spi.h
 *
 *  Created on: Sep 5, 2025
 *      Author: Ajay Ingole
 */

#ifndef SPI_H_
#define SPI_H_
#include "stm32g070xx.h"
void SPIgpioa_init(void);
void SPI_config(void);
void SPI_transmit(uint8_t *data, uint8_t size);
void cs_enable(void);
void cs_disable(void);
void SPI_receive(uint8_t *data);


#endif /* SPI_H_ */
