/*
 * i2c.c
 *
 *  Created on: Sep 19, 2026
 *      Author: HP
 *
 * PA11	 = SCL
 * PA12	 = SDA                    Alternate Function type is AF6
 */

#include "i2c.h"
#define i2c2_enable		(1U<<22)
#define I2C_Slave_addr	(0x27<<1)
void i2c_gpio_init(void){
	RCC->IOPENR |=  (1U<<0);	//Enable the clock for the GPIOA
	//Set pa11
	GPIOA->MODER &=~ (1U<<22);
	GPIOA->MODER |= (1U<<23);
	//set pa12
	GPIOA->MODER &=~ (1U<<24);
	GPIOA->MODER |= (1U<<25);
	//Set Alternate Funxtion type
	GPIOA->OTYPER |= (1U<<11) | (1U<<12); // Opern Drain Configuration

    GPIOA->PUPDR &=~ ((1U<<23) | (1U<<25)); // Clear high bits
    GPIOA->PUPDR |=  ((1U<<22) | (1U<<24)); // Set low bits to activate pull-ups
	//pa11 = scl
	GPIOA->AFR[1] &=~ (1U<<12);
	GPIOA->AFR[1] |= (1U<<13);
	GPIOA->AFR[1] |= (1U<<14);
	GPIOA->AFR[1] &=~ (1U<<15);
	//pa12 = sda
	GPIOA->AFR[1] &=~ (1U<<16);
	GPIOA->AFR[1] |= (1U<<17);
	GPIOA->AFR[1] |= (1U<<18);
	GPIOA->AFR[1] &=~ (1U<<19);
}

void i2c_init(void){
	//enable the clock for the i2c2;
	RCC->APBENR1 |= i2c2_enable;
	//make the i2c is dissable the before the configuration
	I2C2->CR1 &=~ (1U<<0);

    //  Configure Timing (Example value for 100kHz I2C with a 16MHz source clock)
    // You can generate precise values using STM32CubeMX for your specific clock speed
	I2C2->TIMINGR = 0xB0420F13;

	//eNABLE THE I2C
	I2C2->CR1 |= (1U<<0);
}

void i2c_write_byte(uint8_t data){
	I2C2->CR2 = 0;		//Clear all Options
	I2C2->CR2 |= (I2C_Slave_addr & 0x3FF);			//Target Address  SADD[9:0]
	I2C2->CR2 |= (1U<<16);							//1 BYTE DATA SHOULD BE TRANSMITT IN THIS TRANSFER NBYTES[7:0]
	I2C2->CR2 |= (1U<<25);							//AUTOEND = 1 (auto stop bit)
	I2C2->CR2  |= (1U<<13);							//Genartes Start condiation

	while(!(I2C2->ISR & (1U<<1))); // TXIS BIT "The I²C peripheral needs the next byte. Please write data into TXDR."

	I2C2->TXDR = data;			//Transmit data on the data register
	while(!(I2C2->ISR & (1U<<5))); // WAIT FORT THE STOP FLAG;
	I2C2->ICR |= (1U << 5);			//CLEAR THE SOPT FLAG IN THE I2C-ISR
}
