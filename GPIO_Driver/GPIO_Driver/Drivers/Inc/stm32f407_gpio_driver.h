/*
 *	Author: Shrikant Tipartiwar (Embedded_Siri)
 *
 */

#ifndef INC_STM32F407_GPIO_DRIVER_H_
#define INC_STM32F407_GPIO_DRIVER_H_

#include "stm32f407.h"

/*
 * GPIO pin Configuration Structure
 */

typedef struct {
	uint8_t GPIO_PinNumber;  				/* Stores the pin number  */
	uint8_t GPIO_PinMode;					/* Stores the pin mode - @GPIO pin possible mode */
	uint8_t GPIO_PinSpeed;					/* Stores the output speed - @GPIO pin possible mode  */
	uint8_t GPIO_PinPuPdControl;			/* Stores the - @GPIO pin pull up and pull down configuration  */
	uint8_t GPIO_PinOPType;					/* Stores the output type - push pull / open drain   */
	uint8_t GPIO_PinAltFunMode;				/* Stores the alternate function  */
}GPIO_PinConfig_t;


/*
 * This GPIO_Handle_t Structure is like Heart of GPIO.
 * Using this we can set any GPIO port with respective configurations also.
 */

typedef struct {
	GPIO_Registers_t *pGPIOx;  				/* Holds the addr of GPIO port to which the gpio pin belongs */
	GPIO_PinConfig_t GPIO_Config; 			/* Holds the GPIO pin configuration settings */
}GPIO_Handle_t;


/*
 * GPIO pin Numbers
 */

#define GPIO_PIN_NO_0				0
#define GPIO_PIN_NO_1				1
#define GPIO_PIN_NO_2				2
#define GPIO_PIN_NO_3				3
#define GPIO_PIN_NO_4				4
#define GPIO_PIN_NO_5				5
#define GPIO_PIN_NO_6				6
#define GPIO_PIN_NO_7				7
#define GPIO_PIN_NO_8				8
#define GPIO_PIN_NO_9				9
#define GPIO_PIN_NO_10				10
#define GPIO_PIN_NO_11				11
#define GPIO_PIN_NO_12				12
#define GPIO_PIN_NO_13				13
#define GPIO_PIN_NO_14				14
#define GPIO_PIN_NO_15				15


/*
 * GPIO pin possible mode
 */

#define GPIO_MODE_IN				0
#define GPIO_MODE_OUT				1
#define GPIO_MODE_ALTFN				2
#define GPIO_MODE_ANALOG			3

/*
 * GPIO pin possible output type
 */

#define GPIO_OP_TYPE_PP				0
#define GPIO_OP_TYPE_OD				1


/*
 * GPIO pin possible output speed
 */

#define GPIO_SPEED_LOW				0
#define GPIO_SPEED_MEDIUM			1
#define GPIO_SPEED_FAST				2
#define GPIO_SPEED_HIGH				3


/*
 * GPIO pin pull up and pull down configuration
 */

#define GPIO_NO_PUPD				0
#define GPIO_PIN_PU					1
#define GPIO_PIN_PD					2


/**********************************************************************************************
 ******************************** GPIO Driver API's *****************************************
 **********************************************************************************************/


/*--------------------------------------------------------------------------*
 *-----------------------Peripheral Clock setup-----------------------------*
 *--------------------------------------------------------------------------*/

	void GPIO_PeriClockControl(GPIO_Registers_t *pGPIOx, uint8_t en_di);


/*--------------------------------------------------------------------------*
 *--------------------------Init and De-Init--------------------------------*
 *--------------------------------------------------------------------------*/

	void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
	void GPIO_DeInit(GPIO_Registers_t *pGPIOx);

/*--------------------------------------------------------------------------*
 *--------------------------Data Read and Write-----------------------------*
 *--------------------------------------------------------------------------*/

	uint8_t GPIO_ReadFromInputPin(GPIO_Registers_t *pGPIOx, uint8_t PinNumber);
	uint16_t GPIO_ReadFromInputPort(GPIO_Registers_t *pGPIOx);

	void GPIO_WriteToOutputPin(GPIO_Registers_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
	void GPIO_WriteToOutputPort(GPIO_Registers_t *pGPIOx, uint16_t Value);

	void GPIO_ToggleOutPin(GPIO_Registers_t *pGPIOx, uint8_t PinNumber);


#endif /* INC_STM32F407_GPIO_DRIVER_H_ */
