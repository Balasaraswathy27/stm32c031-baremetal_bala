#include "reg_map.h"
void delay1(volatile long int a){
  for(volatile long int i=0;i<a;i++){

  }
}
int main(void){
  RCC->IOPENR|=1;
  GPIOA->MODER&=~(3<<(2*PIN5));
  GPIOA->MODER|=(1<<(2*PIN5));
  GPIOA->OSPEEDR&=~(3<<(2*PIN5));
  GPIOA->OSPEEDR|=(1<<(2*PIN2));
  GPIOA->OTYPER&=~(1<<PIN5);
  while(1){
  GPIOA->BSRR=(1<<PIN5);
  delay1(1000000);
  GPIOA->BSRR=(1<<(PIN5+16));
  delay1(1000000);
  }

}