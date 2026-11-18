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

void Task_B (void *pvParameter){
	gpio_init();
	int *count = (int *)pvParameter;
	while(1){
		(*count)++;
		vTaskDelay(pdMS_TO_TICKS(100));

			if(*count == 20){
				GPIOA->ODR &=~ (1U<<5);
				vTaskDelete(NULL);
			}

	}
}


int main (void){
	TaskHandle_t task_1;
	TaskHandle_t  task_2;
	BaseType_t Status;
	int count=0;
	Status = xTaskCreate(Task_A, "task 2", 100, NULL, 2, &task_1);
	configASSERT(Status == pdPASS);
	Status = xTaskCreate(Task_B, "task b", 100, &count, 2, &task_2);
	configASSERT(Status == pdPASS);
	vTaskStartScheduler();
	while(1);
	return 0;

}


