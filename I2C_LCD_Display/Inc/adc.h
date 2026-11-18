/*
 * adc.h
 *
 *  Created on: Sep 19, 2026
 *      Author: HP
 */

#ifndef ADC_H_
#define ADC_H_
#include "stm32g070xx.h"

#define ADC_ADDIS			(1U<<1)
#define ADC_ENABLE			(1U<<0)
#define ADC_CALibration		(1U<<31)
#define ADC_CONFIG_CONT		(1U<<13)
#define ADC_CHSELR_CHO		(1U<<0)
#define ADC_ISR_READY		(1U<<0)		// wait until ADC is ready to sample
#define ADC_START_CONV		(1U<<2)		//
#define ADC_EOC				(1U<<2)

uint32_t adc_read (void);
void adc_init(void);


#endif /* ADC_H_ */
