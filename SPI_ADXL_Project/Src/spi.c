/*
 * spi.c
 *
 *  Created on: Sep 5, 2025
 *      Author: Ajay Ingole
 */
#include "spi.h"
void SPIgpioa_init(void){
	RCC->IOPENR |= (1U<<0);
	//PA1 SCLK PIN
	GPIOA->MODER &=~ (1U<<2);
	GPIOA->MODER |= (1U<<3);

	//PA6 MISO PIN
	GPIOA->MODER &=~ (1U<<12);
	GPIOA->MODER |= (1U<<13);

	//PA7 MOSI PIN

	GPIOA->MODER &=~ (1U<<14);
	GPIOA->MODER |= (1U<<15);

	/*****Alternate Function type*************/
	//PA0
	GPIOA->AFR[0] &=~ (1U<<0);
	GPIOA->AFR[0] &=~ (1U<<1);
	GPIOA->AFR[0] &=~ (1U<<2);
	GPIOA->AFR[0] &=~ (1U<<3);

	//PA6
	GPIOA->AFR[0] &=~ (1U<<24);
	GPIOA->AFR[0] &=~ (1U<<25);
	GPIOA->AFR[0] &=~ (1U<<26);
	GPIOA->AFR[0] &=~ (1U<<27);

	//PA7
	GPIOA->AFR[0] &=~ (1U<<28);
	GPIOA->AFR[0] &=~ (1U<<29);
	GPIOA->AFR[0] &=~ (1U<<30);
	GPIOA->AFR[0] &=~ (1U<<31);

	//PA8 SS or NSS Gernral Purpose Output Pin
	GPIOA->MODER |=(1U<<16);
	GPIOA->MODER &=~(1U<<16);


}
void SPI_config(void){
	RCC->APBENR2 |= (1U<<12);

	//Select the SPI speed = Peripheral Bus Clock Frequency (PCLK) / Prescaler Divider
	SPI1->CR1 |= (1U<<3);
	SPI1->CR1 &=~ (1U<<4);
	SPI1->CR1 &=~ (1U<<5);

	// Select the clock phse and Clock Polarity set into the mode 3 (bit 0 = cpha, bit 1 =cpol)
	SPI1->CR1 |= (1U<<1) | (1U<<0);

	//RXONLY Bit Full duplex
	SPI1->CR1 &=~ (1U<<10);

	//Slect the Frame Format  msb first = 0;
	SPI1->CR1 &=~ (1U<<7);

	//Select Master Configuration using MSTR bit
	SPI1->CR1 |= (1U<<2);

	//Software Slvae Managment SSM
	SPI1->CR1 |= (1U<<9);

	//Internal Slave Select SSI
	SPI1->CR1 |= (1U<<8);

	//Clear the data size bit
	SPI1->CR2 &=~ (0xFU << 8);

	//Set the data size  8 bit frame format.
	SPI1->CR2 |= (1U<<8);
	SPI1->CR2 |= (1U<<9);
	SPI1->CR2 |= (1U<<10);
	SPI1->CR2 &=~ (1U<<11);

	// SET FRXTH to 1
	SPI1->CR2 |= (1U<<12);

	// Enable the Spi
	SPI1->CR1 |= (1U<<6);
}

void SPI_transmit(uint8_t *data, uint8_t size){
	int i=0;
	uint8_t temp;
	for(i=0; i<size; i++){
		while(!(SPI1->SR & (1U<<1)));	//wait until the busy flag is set
		*(__IO uint8_t *)&SPI1->DR = data[i]; //force an 8bit access to the data register (Crucial for 8-bit/FRXTH mode)
	}
	while(!(SPI1->SR & (1U<<1)));			//wait until the busy flag is set

	// Wait for the SPI peripheral to stop being Busy (BSY is Bit 7)
	while(SPI1->SR &(1U<<7));

	//clear OVR the flag
	temp = *(__IO uint8_t *)&SPI1->DR;
	temp = SPI1->SR;
	(void)temp;
}

void SPI_receive(uint8_t *data){
	//wait for the RXNE flag to be set
	int size=5;
	for(int i=0; i<size; i++){
	while(!(SPI1->SR & (1U<<0)));
	//Read data from data register
	data[i] = *(__IO uint8_t *)SPI1->DR;
	}
}

void cs_enable(void){
	GPIOA->ODR &=~ (1U<<8);
}

void cs_disable(void){
	GPIOA->ODR |= (1U<<8);
}

