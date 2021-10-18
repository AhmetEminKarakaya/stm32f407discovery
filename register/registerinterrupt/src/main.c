#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void Rcc_config_bits(void){


	RCC->CR &= ~(1 << 0);
	RCC->CR |= 1 << 16;
	while(!(RCC->CR & 1 << 17));
	RCC->CR |= 1 << 19;


	RCC->PLLCFGR = 0x00000000;
	RCC->PLLCFGR |= 1 << 22;
	RCC->PLLCFGR |= (4 << 0); // 0 bit sola ötele 4 yaz
	RCC->PLLCFGR |= (168 << 6); // 6 bit sola ötele 168 yaz


	RCC->CR |= 1 << 24;
	while(!(RCC->CR & 1 << 25));


	RCC->CFGR &= ~(1 << 0);
	RCC->CFGR |= 1 << 1;


	while(!(RCC->CFGR & 1 << 1));

	RCC->CIR |= 1 << 3;
	RCC->CIR |= 1 << 7;


	}

void gpio_config(){

	RCC->AHB1ENR=0x00000009;

	GPIOD->MODER = 0x55000000;
	GPIOD->OTYPER = 0x00000000;
	GPIOD->OSPEEDR =0xFF000000;
	GPIOD->PUPDR = 0x00000000;

}

void extl_config(){

	SYSCFG->EXTICR[0] = 0x00000000;

	RCC->APB2ENR = 0x00004000;
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);

	NVIC_SetPriority(EXTI0_IRQn,0);
	NVIC_SetPriority(EXTI1_IRQn,1);
	NVIC_SetPriority(EXTI2_IRQn,2);

	EXTI->IMR = 0x00000007;
	EXTI->RTSR = 0x00000007;

}

void delay(int time){

	while(time--);
}


void EXTI0_IRQHandler(){

	if(EXTI->PR & 0x00000001){

		GPIOD->ODR = 0x00001000;

		delay(3360000);
	}

	EXTI->PR = 0x00000001;
}

void EXTI1_IRQHandler(){

	if(EXTI->PR & 0x00000002){

		GPIOD->ODR = 0x00002000;

		delay(3360000);
	}

	EXTI->PR = 0x00000002;
}

void EXTI2_IRQHandler(){

	if(EXTI->PR & 0x00000004){

		GPIOD->ODR = 0x00004000;

		delay(3360000);
	}

	EXTI->PR = 0x00000004;
}


int main(void)
{
	Rcc_config_bits();
	gpio_config();
	extl_config();

  while (1)
  {

	  GPIOD->ODR = 0x0000F000;

  }
}




void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
