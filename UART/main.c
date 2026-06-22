#include "reg_map.h"

void SET_INIT(void){
  RCC->IOPENR|=(1<<0);
  RCC->APBENR1|=(1<<17);
  GPIOA->MODER&=~(3<<(PIN3*2));
  GPIOA->MODER|=(2<<(PIN3*2));

  GPIOA->MODER&=~(3<<(PIN2*2));
  GPIOA->MODER|=(2<<(PIN2*2));

  GPIOA->AFRL|=(1 << (PIN3 * 4));

  GPIOA->AFRL|=(1 << (PIN2 * 4));

  USART2->BRR=0x8B;
  USART2->CR1|=(1<<0)|(1<<2)|(1<<3);
}
int main(void){
  SET_INIT();
  char c;
  while(1){
    while((((USART2->ISR)>>5)& 1)==0);
    c=USART2->RDR;
    while (((USART2->ISR >> 7) & 1) == 0);
    USART2->TDR=c;     

  }
  

}