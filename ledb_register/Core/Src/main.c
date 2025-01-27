#include "main.h"

#define RCC_APB2ENR  (*((volatile unsigned long *)0x40021018))
#define GPIOC_CRH  (*((volatile unsigned long *)0x40021018))
#define GPIOC_ODR  (*((volatile unsigned long *)0x40021018))
#define SysTick_CTRL  (*((volatile unsigned long *)0x40021018))
#define SysTick_LOAD  (*((volatile unsigned long *)0x40021018))
#define SysTick_VAL  (*((volatile unsigned long *)0x40021018))

void systik_init();
void DelayMillis();
void delays(int time);

int main(){

	RCC_APB2ENR |=0x10;
	GPIOC_CRH &=0xFFFFF;
	GPIOC_CRH |=0x300000;

	systik_init();

	while(1){

		GPIOC_ODR ^=0x2000;
		delays(10);


	}
}

void systik_init(){


	SysTick_CTRL = 0;
	SysTick_LOAD = 0x00ffffff;
	SysTick_VAL = 0;
	SysTick_CTRL |= 5;

}
void DelayMillis(){
	SysTick_LOAD = 72000 - 1;
	SysTick_VAL = 0;
	while((SysTick_CTRL & 0x10000) == 0);

}

void delays(int time){

int i;
	for(i=0;i<time;i++){
		DelayMillis();

	}

}
