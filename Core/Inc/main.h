/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
struct param{
	uint16_t	name[80];
	uint16_t 	value;
};

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

extern TIM_HandleTypeDef htim1;

extern uint8_t setMode;

extern uint8_t needChangeScreen;
extern int8_t enc_value;

extern struct param* status;
extern struct param* set;
extern struct param* rareset;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN2_Pin GPIO_PIN_3
#define BTN2_GPIO_Port GPIOE
#define BTN2_EXTI_IRQn EXTI3_IRQn
#define BTN1_Pin GPIO_PIN_4
#define BTN1_GPIO_Port GPIOE
#define BTN1_EXTI_IRQn EXTI4_IRQn
#define LCD_BL_Pin GPIO_PIN_1
#define LCD_BL_GPIO_Port GPIOB
#define ENC_BTN_Pin GPIO_PIN_13
#define ENC_BTN_GPIO_Port GPIOB
#define ENC_BTN_EXTI_IRQn EXTI15_10_IRQn
/* USER CODE BEGIN Private defines */
#define status_SIZE 6
#define set_SIZE 7
#define rareset_SIZE 17
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
