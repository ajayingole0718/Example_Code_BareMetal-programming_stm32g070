#include <stdint.h>
#include "stm32g070xx.h"
#include "FreeRTOS.h"
#include "led.h"
#include "task.h"
#include "adc.h"
#include "i2c.h"
#include "lcd.h"
uint32_t SystemCoreClock = 16000000;
uint32_t Sensor_value = 0;

void lcd_value(uint32_t value);



void Task_A(void *pvPramater){

	while(1){
		Sensor_value = adc_read();
		lcd_value(Sensor_value);
		led_on();
		vTaskDelay(pdMS_TO_TICKS(200));
		led_off();
		vTaskDelay(pdMS_TO_TICKS(200));
	}
}

void lcd_value(uint32_t value){
	char str[32];
	int i=0;
	while(value > 0){
		str[i] = value % 10 + '0';
		value = value/10;
		i++;
	}
	str[i]='\0';
	for(int j=0; j<i/2; j++){
		char temp = str[j];
		str[j] = str[i-1-j];
		str[i-1-j] = temp;
		}
	lcd_set_cursor(0, 0);
	lcd_print_string("Sensor Value");
	lcd_set_cursor(1, 0);
	lcd_print_string(str);
}


int main (void){
	adc_init();
	i2c_gpio_init();
	i2c_init();
	lcd_init();
	delay_ms(100);
	lcd_set_cursor(0, 0);
	lcd_print_string("System Online!");

	lcd_set_cursor(1, 0);
	lcd_print_string("Matrix Display");
	delay_ms(1000);

	lcd_set_cursor(0, 0);
	lcd_print_string("                                       ");

	lcd_set_cursor(1, 0);
	lcd_print_string("                                       ");

	xTaskCreate(Task_A, "task 2", 100, NULL, 2, NULL);
	vTaskStartScheduler();
	while(1);
	return 0;

}


