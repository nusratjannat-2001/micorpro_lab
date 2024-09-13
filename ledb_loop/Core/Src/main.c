#include "main.h"
int main()
{
RCC->APB2ENR |=0x10;
GPIOC->CRH &=0x0FFFFF;
GPIOC->CRH |=0x300000;
while(1)
{
GPIOC->ODR |=0x2000;
for(int i=0;i<1000000;i++){
}
GPIOC->ODR &=0;
for(int i=0;i<1000000;i++){
}
}
}
