#ifndef REG_MAP_H
#define REG_MAP_H
#include <stdint.h>

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define PIN8   8
#define PIN9   9
#define PIN10  10
#define PIN11  11
#define PIN12  12
#define PIN13  13
#define PIN14  14
#define PIN15  15

typedef struct {

  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFRL;
  volatile uint32_t AFRH;

}GPIO_TypeDef;

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t ICSCR;
    volatile uint32_t CFGR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t RESERVED0;
    volatile uint32_t CIER;
    volatile uint32_t CIFR;
    volatile uint32_t CICR;
    volatile uint32_t IOPRSTR;
    volatile uint32_t AHBRSTR;
    volatile uint32_t APBRSTR1;
    volatile uint32_t APBRSTR2;
    volatile uint32_t IOPENR;
} RCC_TypeDef;

typedef struct {

  volatile uint32_t RTSR1;
  volatile uint32_t FTSR1;
  volatile uint32_t SWIER1;
  volatile uint32_t RPR1;
  volatile uint32_t FPR1;

  volatile uint32_t RESERVED1;
  volatile uint32_t RESERVED2;
  volatile uint32_t RESERVED3;

  volatile uint32_t RTSR2;
  volatile uint32_t FTSR2;
  volatile uint32_t SWIER2;
  volatile uint32_t RPR2;
  volatile uint32_t FPR2;

  volatile uint32_t RESERVED4;
  volatile uint32_t RESERVED5;
  volatile uint32_t RESERVED6;

  volatile uint32_t EXTICR1;
  volatile uint32_t EXTICR2;
  volatile uint32_t EXTICR3;
  volatile uint32_t EXTICR4;

  volatile uint32_t RESERVED7;
  volatile uint32_t RESERVED8;
  volatile uint32_t RESERVED9;

  volatile uint32_t IMR1;
  volatile uint32_t EMR1;

  volatile uint32_t RESERVED10;
  volatile uint32_t RESERVED11;

  volatile uint32_t IMR2;
  volatile uint32_t EMR2;

}EXTI_TypeDef;

typedef struct
{
    volatile uint32_t ISER[1];
    volatile uint32_t ICER[1];
    volatile uint32_t ISPR[1];
    volatile uint32_t ICPR[1];
    volatile uint32_t IABR[1];
    volatile uint8_t  IP[32];
} NVIC_TypeDef;

#define GPIOA ((GPIO_TypeDef *)0x50000000)
#define GPIOB ((GPIO_TypeDef *)0x50000400)
#define GPIOC ((GPIO_TypeDef *)0x50000800)
#define GPIOD ((GPIO_TypeDef *)0x50000C00)
#define GPIOF ((GPIO_TypeDef *)0x50001400)
#define RCC   ((RCC_TypeDef *)0x40021000)
#define EXTI  ((EXTI_TypeDef *)0x40021800)
#define NVIC  ((NVIC_TypeDef *)0xE000E100)
#endif