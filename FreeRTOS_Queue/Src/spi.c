/*
 * spi.c
 *
 *  Created on: Aug 22, 2026
 *      Author: Ajay Ingole
 */
#include "stm32g070xx.h"

void SPgpio_init(void)
{
	/*   PA5 = SCLK, PA6 = MISO, PA7 = MOSI, PA8 = SS	*/
	RCC->IOPENR |= (1U<<0); 		//enable clock access for the GPIOA

	GPIOA->MODER &=~ (1U<<10);		//almode for sclk
	GPIOA->MODER |= (1U<<11);

	GPIOA->MODER &=~ (1U<<12);		//al mode for MISO
	GPIOA->MODER |= (1U<<13);

	GPIOA->MODER &=~ (1U<<14);		// al mode for the MOSI
	GPIOA->MODER |= (1U<<15);

	GPIOA->MODER |= (1U<<16);		// Slave select for as an Output
	GPIOA->MODER &=~ (1U<<17);

	// Set the alternate fucntion type to AF0

	GPIOA->AFR[0] &=~ (1U<<20);
	GPIOA->AFR[0] &=~ (1U<<21);
	GPIOA->AFR[0] &=~ (1U<<22);
	GPIOA->AFR[0] &=~ (1U<<23);

	GPIOA->AFR[0] &=~ (1U<<24);
	GPIOA->AFR[0] &=~ (1U<<25);
	GPIOA->AFR[0] &=~ (1U<<26);
	GPIOA->AFR[0] &=~ (1U<<27);

	GPIOA->AFR[0] &=~ (1U<<28);
	GPIOA->AFR[0] &=~ (1U<<29);
	GPIOA->AFR[0] &=~ (1U<<30);
	GPIOA->AFR[0] &=~ (1U<<31);

}
void spi_init(){
	//Enable clock access for the SPI
	RCC->APBENR2 |= (1U<<12);
	//Set clock 3, 4, 5
	SPI1->CR1 &=~ (1U<<3);
	SPI1->CR1 |= (1U<<4);
	SPI1->CR1 &=~ (1U<<5);

	// Set the clock phase and clock polarity

}


