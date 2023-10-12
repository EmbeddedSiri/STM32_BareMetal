/*
 *	Author: Shrikant Tipartiwar (Embedded_Siri)
 *
 */

#ifndef INC_STM32F407_H_
#define INC_STM32F407_H_

#include<stdint.h>

#define __IO 	volatile

/*
 * Base addresses of Flash and SRAM
*/

#define FLASH_BASEADDR				0x08000000UL
#define SRAM1_BASEADDR				0x20000000UL
#define SRAM2_BASEADDR				0x20001C00UL
#define ROM_BASEADDR				0x1FFF0000UL
#define SRAM						SRAM1_BASEADDR


/*
 * AHB and APB Peripheral base addresses
 * - Because our all Peripherals are on these Buses
 */

#define APB1_BASEADDR				0x40000000UL
#define APB2_BASEADDR				0x40010000UL
#define AHB1_BASEADDR				0x40020000UL
#define AHB2_BASEADDR				0x50000000UL

/*
 * Addresses of GPIO Peripherals which are on AHB1 Bus
 */

#define GPIOA_BASEADDR				(AHB1_BASEADDR + 0x0000UL)
#define GPIOB_BASEADDR				(AHB1_BASEADDR + 0x0400UL)
#define GPIOC_BASEADDR				(AHB1_BASEADDR + 0x0800UL)
#define GPIOD_BASEADDR				(AHB1_BASEADDR + 0x0C00UL)
#define GPIOE_BASEADDR				(AHB1_BASEADDR + 0x1000UL)
#define GPIOF_BASEADDR				(AHB1_BASEADDR + 0x1400UL)
#define GPIOG_BASEADDR				(AHB1_BASEADDR + 0x1800UL)
#define GPIOH_BASEADDR				(AHB1_BASEADDR + 0x1C00UL)
#define GPIOI_BASEADDR				(AHB1_BASEADDR + 0x2000UL)

#define RCC_BASEADDR                (AHB1_BASEADDR + 0x3800UL)

/*
 * GPIO Peripheral Ragisters Defination Structure
 */

typedef struct {
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSSR;
	__IO uint32_t LCKR;
	__IO uint32_t AFR[2];
}GPIO_Registers_t;

/*
 * RCC Peripheral Ragisters Defination Structure
 * - Using RCC structure we can enable or disable clock for particular peripheral or we can reset the peri.
 */

typedef struct {
	__IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
	  __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
	  __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
	  __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
	  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
	  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
	  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
	  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
	  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
	  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
	  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
	  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
	  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
	  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
	  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
	  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
	  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
	  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
	  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
	  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
	  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
	  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
	  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
	  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
	  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
	  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */

}RCC_Registers_t;

/*
 * GPIO Peripheral Addresses typecasted to GPIO_RegDef_t Structure
 * -We have Type_casted GPIOx_Base_addresses to GPIO_Registers_t
 *  because by doing this we can easly access the gpio registers of particular port
 *  just by structure.
 */

#define GPIOA 						((GPIO_Registers_t*)GPIOA_BASEADDR)
#define GPIOB 						((GPIO_Registers_t*)GPIOB_BASEADDR)
#define GPIOC 						((GPIO_Registers_t*)GPIOC_BASEADDR)
#define GPIOD 						((GPIO_Registers_t*)GPIOD_BASEADDR)
#define GPIOE 						((GPIO_Registers_t*)GPIOE_BASEADDR)
#define GPIOF 						((GPIO_Registers_t*)GPIOF_BASEADDR)
#define GPIOG 						((GPIO_Registers_t*)GPIOG_BASEADDR)
#define GPIOH 						((GPIO_Registers_t*)GPIOH_BASEADDR)
#define GPIOI 						((GPIO_Registers_t*)GPIOI_BASEADDR)

#define RCC							((RCC_Registers_t*)RCC_BASEADDR)

/*
 * Clock Enable Macros for GPIO Peripherals
 */

#define GPIOA_PERI_CLK_EN()			(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PERI_CLK_EN()			(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PERI_CLK_EN()			(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PERI_CLK_EN()			(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PERI_CLK_EN()			(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PERI_CLK_EN()			(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PERI_CLK_EN()			(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PERI_CLK_EN()			(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PERI_CLK_EN()			(RCC->AHB1ENR |= (1 << 8))


/*
 * Clock Disable Macros for GPIO Peripherals
 */

#define GPIOA_PERI_CLK_DI()			(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PERI_CLK_DI()			(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PERI_CLK_DI()			(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PERI_CLK_DI()			(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PERI_CLK_DI()			(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PERI_CLK_DI()			(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PERI_CLK_DI()			(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PERI_CLK_DI()			(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PERI_CLK_DI()			(RCC->AHB1ENR &= ~(1 << 8))


/*
 * Macros to reset GPIO Peripheral
 */

#define	GPIOA_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define	GPIOB_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define	GPIOC_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define	GPIOD_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define	GPIOE_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define	GPIOF_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define	GPIOG_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define	GPIOH_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define	GPIOI_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)

/*----------------------------------------------------------------------------------------------------------------*/

// Generic Macros

#define ENABLE					1
#define DISABLE					0
#define SET						ENABLE
#define RESET					DISABLE
#define GPIO_PIN_SET			SET
#define GPIO_PIN_RESET			RESET
















#endif /* INC_STM32F407_H_ */
