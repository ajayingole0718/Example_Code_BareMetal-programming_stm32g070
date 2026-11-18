#include "stm32f401xc.h"
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"

uint32_t SystemCoreClock = 16000000;

void gpio_init(void){
}

void Task_A(void *pvPramater){
	gpio_init();
	while(1){
	}
}

void Task_B (void *pvParameter){
	gpio_init();
	while(1){
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



