#include "reg_map.h"

void SPI_INIT(void){
  RCC->APBENR2|=(1<<12);
  RCC->IOPENR|=(1<<0);

  GPIOA->MODER&=~(3<<(PIN4 *2));
  GPIOA->MODER|=(1<<(PIN4 *2));
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

  SPI1->CR1 &= ~(7<<3);
  SPI1->CR1 |=  (7<<3);

  SPI1->CR1 |= (1<<0);   // CPHA = 1
  SPI1->CR1 |= (1<<1);   // CPOL = 1

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
// void SPI_Data(char *str){
//   while(*str!='\0'){
//     SPI_Transmitt_Byte(*str);
//     str++;
//   }
// }
// char SPI_Receive_Byte(void){
//   SPI1->DR=0x00;//duummy byte
//   while(!(((SPI1->SR>>0)&1)));
//   char Received_byte;
//   Received_byte=SPI1->DR;
//   return Received_byte;

// }
int main(void)
{
    SPI_INIT();

    GPIOA->BSRR = (1<<PIN4);   // CS HIGH

    // 80 startup clocks
    for(int i = 0; i < 10; i++)
    {
        SPI_Send(0xFF);
    }

    GPIOA->BSRR = (1<<(PIN4+16)); // CS LOW

    // CMD0
    SPI_Send(0x40);
    SPI_Send(0x00);
    SPI_Send(0x00);
    SPI_Send(0x00);
    SPI_Send(0x00);
    SPI_Send(0x95);

    volatile char resp[50];

    for(int i = 0; i < 50; i++)
    {
        resp[i] = SPI_Send(0xFF);
    }

    GPIOA->BSRR = (1<<PIN4);   // CS HIGH
    SPI_Send(0xFF);

    while(1);
}