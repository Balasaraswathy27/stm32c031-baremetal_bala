#include "reg_map.h"

void SPI_INIT(void){
  RCC->APBENR2|=(1<<12);
  RCC->IOPENR|=(1<<0);
  /*SCK */
  GPIOA->MODER&=~(3<<(PIN1 *2));
  GPIOA->MODER|=(2<<(PIN1 *2));

  /* MOSI */
  GPIOA->MODER&=~(3<<(PIN2 *2));
  GPIOA->MODER|=(2<<(PIN2 *2));

  /* NSS for Hardware NSS*/
  // GPIOA->MODER&=~(3<<(PIN4 *2));
  // GPIOA->MODER|=(2<<(PIN4 *2));

  /* MISO */
  GPIOA->MODER&=~(3<<(PIN6 *2));
  GPIOA->MODER|=(2<<(PIN6 *2));

  GPIOA->AFRL&=~((15<< (PIN1 *4)));
  GPIOA->AFRL&=~((15<< (PIN2 *4)));
  //GPIOA->AFRL&=~((15<< (PIN4 *4)));
  GPIOA->AFRL&=~((15<< (PIN6 *4)));

  SPI1->CR1|=(3<<3);
  SPI1->CR1 &=~(3<<0);
  SPI1->CR1|=(1<<6)|(1<<2)|(1<<9)|(1<<8);

  SPI1->CR2|=(7<<8);

}

char SPI_Send(char c){
  while(!((SPI1->SR>>1)&1));// TXE wait
  SPI1->DR=c;//Write tx to DR
  while((SPI1->SR>>7)&1);
  while(!(((SPI1->SR>>0)&1)));// wait RXNE
  char Received_byte;
  Received_byte=SPI1->DR;
  return Received_byte;


}

int main(void){
  SPI_INIT();
  char c=SPI_Send(0xAA);
  char c1=SPI_Send(0x48);


}