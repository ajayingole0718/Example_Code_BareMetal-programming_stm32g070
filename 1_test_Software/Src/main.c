#include <stdint.h>
#include "stm32g070xx.h"

#include "FreeRTOS.h"
#include "task.h"
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


int main (void){
	xTaskCreate(Task_A, "task 2", 100, NULL, 2, NULL);
	vTaskStartScheduler();
	while(1);
	return 0;

}


