#include "stm32f1xx.h"
#include "stm32f1xx_hal_cortex.h"
#include "stm32f1xx_hal_gpio.h"
#include "delayfunc.h"

#define LED0_GPIO  GPIOB
#define LED1_GPIO  GPIOE

#define LED0_PIN   GPIO_PIN_5
#define LED1_PIN   GPIO_PIN_5

int main(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure; 
	delay_init();
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
	
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();

	GPIO_InitStructure.Pin = LED1_PIN;		             //LED0¶Ë¿ÚÅäÖÃ
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP; 		 //ÍÆÍìÊä³ö
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;	 //IO¿ÚËÙ¶ÈÎª50MHz
	HAL_GPIO_Init(LED1_GPIO, &GPIO_InitStructure);	     //¸ù¾ÝÉè¶¨²ÎÊý³õÊ¼»¯LED0
	HAL_GPIO_WritePin(LED1_GPIO,LED1_PIN,GPIO_PIN_SET);	 //LED0Êä³ö¸ß

	GPIO_InitStructure.Pin = LED0_PIN;	    		     //LED1¶Ë¿ÚÅäÖÃ, ÍÆÍìÊä³ö
	HAL_GPIO_Init(LED0_GPIO, &GPIO_InitStructure);	  	 //ÍÆÍìÊä³ö £¬IO¿ÚËÙ¶ÈÎª50MHz
	HAL_GPIO_WritePin(LED0_GPIO,LED0_PIN,GPIO_PIN_SET);  //LED1Êä³ö¸ß 
	
	while(1)
	{
		HAL_GPIO_WritePin(LED1_GPIO,LED1_PIN,GPIO_PIN_RESET); 
		delay_ms(2000);
		HAL_GPIO_WritePin(LED1_GPIO,LED1_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED0_GPIO,LED0_PIN,GPIO_PIN_RESET);
		delay_ms(2000);
		HAL_GPIO_WritePin(LED0_GPIO,LED0_PIN,GPIO_PIN_SET);
	}
}