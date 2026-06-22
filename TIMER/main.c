#include "reg_map.h"
/* The difference in this is the prescaler value is loaded first without waiting for a update event after the counter starts becasue of ECG the  update event is generated first after that the timer is  started */
int main(void){
  RCC->APBENR2|=(1<<11);
  TIM1->PSC=10000;
  TIM1->ARR=10000;
  TIM1->EGR|=(1<<0);
  TIM1->CR1|=(1<<0);

  RCC->IOPENR|=1;
  GPIOA->MODER&=~(3<<(2*PIN5));
  GPIOA->MODER|=(1<<(2*PIN5));
  GPIOA->OSPEEDR&=~(3<<(2*PIN5));
  GPIOA->OSPEEDR|=(1<<(2*PIN5));
  GPIOA->OTYPER&=~(1<<PIN5);

  while(1){
    int status=(TIM1->SR)&1;
    if(status){
    GPIOA->ODR^=(1<<PIN5);
    TIM1->SR&=~(1<<0);
    }


  }
}