#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void delay(void){

	for(int i=0;i<1680000;i++);
}

int count=0;

void clk_config(void){

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

		RCC->AHB1ENR =0x00000009;

		GPIOD->MODER = 0x55550000;
		GPIOD->OTYPER = 0x00000000;
		GPIOD->OSPEEDR = 0xFF000000;
		GPIOD->PUPDR = 0x00000000;
}


int main(void)
{

	clk_config();

	while(1){


		if(GPIOA->IDR & 0x00000001){

			while(GPIOA->IDR & 0x00000001);
			delay();
			count++;
		}

		switch(count){

		case 1:
			GPIOD->ODR |= 1 << 12;
		    break;
		case 2:
			GPIOD->ODR |= 1 << 12;
			GPIOD->ODR |= 1 << 13;
			break;
		case 3:
			GPIOD->ODR |= 1 << 12;
			GPIOD->ODR |= 1 << 13;
			GPIOD->ODR |= 1 << 14;
			break;
		case 4:
			GPIOD->ODR |= 1 << 12;
			GPIOD->ODR |= 1 << 13;
			GPIOD->ODR |= 1 << 14;
			GPIOD->ODR |= 1 << 15;
			break;
		}

		if(count == 5){
			count=0;
			GPIOD->ODR = 0x00000000;

		}




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
