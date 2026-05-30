#include "reg_map.h"
void delay1(volatile long int a){
  for(volatile long int i=0;i<a;i++){

  }
}
void SET_INIT(){
  RCC->IOPENR|=1;
  GPIOA->MODER&=~(3<<(PIN5 *2));
  GPIOA->MODER|=(1<<(PIN5 *2));
  GPIOA->OSPEEDR&=~(3<<(PIN5 *2));
  GPIOA->OSPEEDR|=(1<<(PIN5 *2));
  GPIOA->OTYPER&=~(1<<PIN5);
  GPIOA->PUPDR&=~(3<<(PIN7*2));
  GPIOA->PUPDR|=(2<<(PIN7 *2));
  
  /* FOR EXTI INTERRUPT  */

  EXTI->EXTICR2&=0x00FFFFFF;
  EXTI->RTSR1|=(1<<PIN7);
  EXTI->IMR1|=(1<<PIN7);
  NVIC->ISER[0]|=(1<<PIN7);

}
volatile int led_state = 0;

void EXTI4_15_IRQHandler(void)
{
    if (EXTI->RPR1 & (1 << PIN7))
    {
        // toggle state
        led_state = !led_state;

        if (led_state)
        {
            GPIOA->BSRR = (1 << PIN5);        // LED ON
        }
        else
        {
            GPIOA->BSRR = (1 << (PIN5 + 16)); // LED OFF
        }

        // clear pending flag (W1C)
        EXTI->RPR1 = (1 << PIN7);
    }
}
int main(void){

  SET_INIT();
}