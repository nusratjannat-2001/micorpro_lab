#include "main.h"

void systik_init();
void DelayMillis();
void delays(int time);

int main(){

	RCC->APB2ENR |=0x10;
	GPIOC->CRH &=0xFFFFF;
	GPIOC->CRH |=0x300000;

	systik_init();

	while(1){

		GPIOC->ODR ^=0x2000;
		delays(10);


	}
}

void systik_init(){


	SysTick->CTRL = 0;
	SysTick->LOAD = 0x00ffffff;
	SysTick->VAL = 0;
	SysTick->CTRL |= 5;

}
void DelayMillis(){
	SysTick->LOAD = 72000 - 1;
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x10000) == 0);

}

void delays(int time){

int i;
	for(i=0;i<time;i++){
		DelayMillis();

	}

}
