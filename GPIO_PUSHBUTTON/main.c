#include "reg_map.h"
void delay1(volatile long int a){
  for(volatile long int i=0;i<a;i++){

  }
}
int main(void){
  RCC->IOPENR|=1;
  GPIOA->MODER&=~(3<<(PIN5 *2));
  GPIOA->MODER|=(1<<(PIN5 *2));
  GPIOA->OSPEEDR&=~(3<<(PIN5 *2));
  GPIOA->OSPEEDR|=(1<<(PIN5 *2));
  GPIOA->OTYPER&=~(1<<PIN5);
  GPIOA->PUPDR&=~(3<<(PIN7*2));
  GPIOA->PUPDR|=(2<<(PIN7 *2));
  int previous = 0;
  int led_state = 0;
    while(1)
    {
        int current = (GPIOA->IDR & (1 << PIN7)) ? 1 : 0;
        if((previous == 0) && (current == 1))
        {
            delay1(50000);
            led_state = !led_state;

            if(led_state)
            {
                GPIOA->BSRR = (1 << PIN5);
            }
            else
            {
                GPIOA->BSRR = (1 << (PIN5 + 16));
            }
        }

        previous = current;
    }

}