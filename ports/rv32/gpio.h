#ifndef GPIO_H
#define GPIO_H

#define GPIOA_BASE     ((volatile unsigned char *)0x80070000)
#define GPIOA_OUT      (*(GPIOA_BASE+0x00))
#define GPIOA_DIR      (*(GPIOA_BASE+0x04))
#define GPIOA_PIN      (*(GPIOA_BASE+0x08))
#define GPIOA_SPIDAT   (*(GPIOA_BASE+0x0C))
#define GPIOA_SPICNT   (*(GPIOA_BASE+0x10))
#define GPIOA_SPISTA   (*(GPIOA_BASE+0x14))
#define GPIOA_COUNT    (*((volatile unsigned int *)(GPIOA_BASE+0x18)))

#endif /* of GPIO_H */
