/*
 *	Author: Shrikant Tipartiwar (Embedded_Siri)
 *
 */

#include "stm32f407_gpio_driver.h"


/* Peripheral Clock setup */

void GPIO_PeriClockControl(GPIO_Registers_t *pGPIOx, uint8_t en_di)
{
	if (en_di == ENABLE){

		if (pGPIOx == GPIOA) {
			GPIOA_PERI_CLK_EN();
		}else if (pGPIOx == GPIOB) {
			GPIOB_PERI_CLK_EN();
		}else if (pGPIOx == GPIOC) {
			GPIOC_PERI_CLK_EN();
		}else if (pGPIOx == GPIOD) {
			GPIOD_PERI_CLK_EN();
		}else if (pGPIOx == GPIOE) {
			GPIOE_PERI_CLK_EN();
		}else if (pGPIOx == GPIOF) {
			GPIOF_PERI_CLK_EN();
		}else if (pGPIOx == GPIOG) {
			GPIOG_PERI_CLK_EN();
		}else if (pGPIOx == GPIOH) {
			GPIOH_PERI_CLK_EN();
		}else if (pGPIOx == GPIOI) {
			GPIOI_PERI_CLK_EN();
		}

	}else {

		if (pGPIOx == GPIOA) {
			GPIOA_PERI_CLK_DI();
		}else if (pGPIOx == GPIOB) {
			GPIOB_PERI_CLK_DI();
		}else if (pGPIOx == GPIOC) {
			GPIOC_PERI_CLK_DI();
		}else if (pGPIOx == GPIOD) {
			GPIOD_PERI_CLK_DI();
		}else if (pGPIOx == GPIOE) {
			GPIOE_PERI_CLK_DI();
		}else if (pGPIOx == GPIOF) {
			GPIOF_PERI_CLK_DI();
		}else if (pGPIOx == GPIOG) {
			GPIOG_PERI_CLK_DI();
		}else if (pGPIOx == GPIOH) {
			GPIOH_PERI_CLK_DI();
		}else if (pGPIOx == GPIOI) {
			GPIOI_PERI_CLK_DI();
		}
	}
}


/* Init and De-Init */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;

	/* 1. Configure the mode of gpio pin */

	if (pGPIOHandle->GPIO_Config.GPIO_PinMode <= GPIO_MODE_ANALOG){

		temp = (pGPIOHandle->GPIO_Config.GPIO_PinMode << (2 * pGPIOHandle->GPIO_Config.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_Config.GPIO_PinNumber); // Clearing the bits
		pGPIOHandle->pGPIOx->MODER |= temp; // Setting the bits

	}

	temp = 0;

	/* 2. Configure the speed */

	temp = (pGPIOHandle->GPIO_Config.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_Config.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_Config.GPIO_PinNumber); // Clearing the bits
	pGPIOHandle->pGPIOx->OSPEEDR |= temp; // Setting the bits

	temp = 0;

	/* 3. Configure the PuPd settings */

	temp = (pGPIOHandle->GPIO_Config.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_Config.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_Config.GPIO_PinNumber); // Clearing the bits
	pGPIOHandle->pGPIOx->PUPDR |= temp; // Setting the bits

	temp = 0;

	/* 4. Configure the optype */

	temp = (pGPIOHandle->GPIO_Config.GPIO_PinOPType << (pGPIOHandle->GPIO_Config.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_Config.GPIO_PinNumber); // Clearing the bits
	pGPIOHandle->pGPIOx->OTYPER |= temp; // Setting the bits

	temp = 0;

	/* 5. Configure the alternate function */

	if (pGPIOHandle->GPIO_Config.GPIO_PinMode == GPIO_MODE_ALTFN) {

		uint32_t temp1, temp2;

		temp1 = pGPIOHandle->GPIO_Config.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_Config.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2)); // Clearing the bits
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_Config.GPIO_PinAltFunMode << (4 * temp2));  // Settings the bits
	}
}

void GPIO_DeInit(GPIO_Registers_t *pGPIOx) {

	if (pGPIOx == GPIOA) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOB) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOC) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOD) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOE) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOF) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOG) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOH) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOI) {
		GPIOA_REG_RESET();
	}

}

/* Data Read and Write */

uint8_t GPIO_ReadFromInputPin(GPIO_Registers_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}

uint16_t GPIO_ReadFromInputPort(GPIO_Registers_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}

void GPIO_WriteToOutputPin(GPIO_Registers_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if (Value == GPIO_PIN_SET) {

		/* Write 1 to output data register at the bit field corresponding to pin number */
		pGPIOx->ODR |= (1 << PinNumber);

	} else {
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

void GPIO_WriteToOutputPort(GPIO_Registers_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

void GPIO_ToggleOutPin(GPIO_Registers_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR = pGPIOx->ODR ^ (1 << PinNumber);
}