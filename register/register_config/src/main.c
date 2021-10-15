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


	}


int main(void)
{
	 Rcc_config_bits();


	 while (1)
	 {


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
