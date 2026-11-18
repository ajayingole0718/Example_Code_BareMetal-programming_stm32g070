/*
 * adc.c
 *
 *  Created on: Sep 19, 2026
 *      Author: HP
 */

#include "adc.h"

void adc_init(void){
	//Enable the clock access for the GPIOA
	RCC->IOPENR |=  (1U<<0);
	GPIOA->MODER |= (1U<<0);
	GPIOA->MODER |= (1U<<1);

	/*Configre the ADC*/
	//Enbale Clock Access for the ADC
	RCC->APBENR2 |= (1U<<20);
	if((ADC1->CR & ADC_ENABLE) !=0){
		ADC1->CR |= ADC_ADDIS;	//Disable the ADC 1st
	}

	while((ADC1->CR & ADC_ENABLE) != 0);	//wait for the Disablement

//	ADC1->CR |= ADC_CALibration;		// Start the ADC Calibration
//
//	while((ADC1->CR & ADC_CALibration)!=0);		//wait for the Calibration is complete

	ADC1->CFGR1 &=~ ADC_CONFIG_CONT;		//Sigle Conversion Mode
	ADC1->CFGR1 &=~ (1U<<3);				//12 Bit resolution
	ADC1->CFGR1 &=~ (1U<<4);

	ADC1->CHSELR |= ADC_CHSELR_CHO;

	ADC1->CR |= ADC_ENABLE;
	while(!(ADC1->ISR & ADC_ISR_READY));	//wait until ADC is ready to sample

}

uint32_t adc_read (void){
	ADC1->CR |=	 ADC_START_CONV;
	while(!(ADC1->ISR & ADC_EOC));
	return ADC1->DR;
}
