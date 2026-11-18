#include <stdint.h>
#include "stm32g070xx.h"
#include "led.h"
#include "spi.h"
uint8_t received_data[5]={0};
int main (void){
	uint8_t tx_buffer[5] = {0xA5, 0x53, 0x2A, 0x7E, 0x00};
 	uint8_t size = sizeof tx_buffer / sizeof tx_buffer[0];

	led_gpioaINIT();
	SPIgpioa_init();
	SPI_config();
	while(1){
		cs_enable();
		SPI_transmit(tx_buffer, size);
		cs_disable();
		LED_ON();
		delay();
		cs_enable();
		SPI_receive(received_data);
		cs_disable();
		LED_OFF();
		delay();
	}

	return 0;

}


