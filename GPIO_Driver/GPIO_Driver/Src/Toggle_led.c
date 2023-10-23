/*
 *	Author: Shrikant Tipartiwar (Embedded_Siri)
 *
 */

#include <stdint.h>
#include "stm32f407.h"
#include "stm32f407_gpio_driver.h"

void delay(void)
{
	for (uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
    GPIO_Handle_t GpioLed;


    GpioLed.pGPIOx = GPIOD;

    GpioLed.GPIO_Config.GPIO_PinNumber = GPIO_PIN_NO_12 |GPIO_PIN_NO_13 | GPIO_PIN_NO_14 | GPIO_PIN_NO_15;
    GpioLed.GPIO_Config.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_Config.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_Config.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_Config.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLed);

    while(1) {
    	delay();
    	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, GPIO_PIN_SET);
    	delay();
    	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, GPIO_PIN_RESET);
    }
	return 0;
}
