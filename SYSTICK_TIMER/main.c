#include "reg_map.h"
void SET_INIT(void){
  RCC->IOPENR|=1;
  GPIOA->MODER&=~(3<<(2*PIN5));
  GPIOA->MODER|=(1<<(2*PIN5));
  GPIOA->OSPEEDR&=~(3<<(2*PIN5));
  GPIOA->OSPEEDR|=(1<<(2*PIN5));
  GPIOA->OTYPER&=~(1<<PIN5);
  STK->RVR = 0x00FFFFFF;
  STK->CVR = 0;
  STK->CSR|=0x00000005;
}
int main(void){
  SET_INIT();
  int CHECKFLAG=0;
  while(1){

    while(CHECKFLAG==0){
    CHECKFLAG=((STK->CSR >> 16) & 0x01);
    }
      GPIOA->ODR^=(1<<PIN5);
      CHECKFLAG=0;
  
  }

}