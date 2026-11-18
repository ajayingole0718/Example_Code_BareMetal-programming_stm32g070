#include <stdint.h>
#include "stm32g070xx.h"

#include "FreeRTOS.h"
#include "task.h"
#include "timer.h"
uint32_t SystemCoreClock = 16000000;

void gpio_init(void){
	RCC->IOPENR |=  (1U<<0);
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~ (1U<<11);
}

void Task_A(void *pvPramater){
	gpio_init();
	while(1){
		GPIOA->ODR |= (1U<<5);
		vTaskDelay(pdMS_TO_TICKS(1000));
		GPIOA->ODR &=~ (1U<<5);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void Task_B(void *pv){
	uint16_t brightness=0;
	while(1){
    	for(brightness = 0; brightness < 1000; brightness++){
    		TIM3->CCR1 = brightness;
    		vTaskDelay(pdMS_TO_TICKS(2));
    	}

    	for(brightness  = 999; brightness  > 0; brightness --){
    		TIM3->CCR1 = brightness;
    		vTaskDelay(pdMS_TO_TICKS(2));
    	}
	}
}

int main (void){
	//uint16_t brightness=0;

	tim3_init();
	xTaskCreate(Task_A, "task 2", 100, NULL, 2, NULL);
	xTaskCreate(Task_B, "task 3", 100, NULL, 2, NULL);
	vTaskStartScheduler();
    while(1){
//    	for(brightness = 0; brightness < 1000; brightness++){
//    		TIM3->CCR1 = brightness;
//    		for(int i=0; i<5000; i++){}
//    	}
//
//    	for(brightness  = 999; brightness  > 0; brightness --){
//    		TIM3->CCR1 = brightness;
//    		for(int i=0; i<5000; i++){}
//    	}
    }

}


