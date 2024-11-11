#include <inttypes.h>
#include <stdbool.h>

struct rcc {
  volatile uint32_t CR, HSICFGR, CRRCR, RESERVED0, CSICFGR, CFGR, RESERVED1, D1CFGR, D2CFGR,
      D3CFGR, RESERVED2, PLLCKSELR, PLLCFGR, PLL1DIVR, PLL1FRACR, PLL2DIVR, PLL2FRACR,
      PLL3DIVR, PLL3FRACR, RESERVED3, D1CCIPR, D2CCIP1R, D2CCIP2R, D3CCIPR, RESERVED4,
      CIER, CIFR, CICR, RESERVED5, BDCR, CSR, RESERVED6, AHB3RSTR, AHB1RSTR, AHB2RSTR,
      AHB4RSTR, APB3RSTR, APB1LRSTR, APB1HRSTR, APB2RSTR, APB4RSTR, GCR, RESERVED7,
      D3AMR, RESERVED8[8], AHB3ENR, AHB1ENR, AHB2ENR, AHB4ENR, APB3ENR, APB1LENR,
      APB1HENR, APB2ENR, APB4ENR, RESERVED9, AHB3LPENR, AHB1LPENR, AHB2LPENR,
      AHB4LPENR, APB3LPENR, APB1LLPENR, APB1HLPENR, APB2LPENR, APB4LPENR, RESERVED10[3],
      C1_RSR, C1_AHB3ENR, C1_AHB1ENR, C1_AHB2ENR, C1_AHB4ENR, C1_APB3ENR, C1_APB1LENR,
      C1_APB1HENR, C1_APB2ENR, C1_APB4ENR, RESERVED11, C1_AHB3LPENR, C1_AHB1LPENR,
      C1_AHB2LPENR, C1_AHB4LPENR, C1_APB3LPENR, C1_APB1LLPENR, C1_APB1HLPENR, C1_APB2LPENR,
      C1_APB4LPENR, RESERVED12[31];
};
#define RCC ((struct rcc *) 0x58024400)

#define BIT(x) (1UL << (x))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define PINNO(pin) (pin & 255)
#define PINBANK(pin) (pin >> 8)

struct gpio {
  volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFR[2];
};
#define GPIO(bank) ((struct gpio *) (0x58020000 + 0x400 * (bank)))

// Enum values are per datasheet: 0, 1, 2, 3
enum { GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG };

static inline void gpio_set_mode(uint16_t pin, uint8_t mode) {
  struct gpio *gpio = GPIO(PINBANK(pin));  // GPIO bank
  int n = PINNO(pin);                      // Pin number
  gpio->MODER &= ~(3U << (n * 2));         // Clear existing setting
  gpio->MODER |= (mode & 3) << (n * 2);    // Set new mode
}

static inline void gpio_write(uint16_t pin, bool val) {
  struct gpio *gpio = GPIO(PINBANK(pin));
  gpio->BSRR = (1U << PINNO(pin)) << (val ? 0 : 16);
}

static inline void spin(volatile uint32_t count) {
  while (count--) (void) 0;
}

int main(void) {
    //   uint16_t led = PIN('E', 1);            // Blue LED
    //   RCC->AHB4ENR |= BIT(PINBANK(led));     // Enable GPIO clock for LED
    //   gpio_set_mode(led, GPIO_MODE_OUTPUT);  // Set blue LED to output mode
    // * (volatile uint32_t *) (0x58024400 + 0x0E0) |= 1;  // EMABLE CLOCK
    // * (volatile uint32_t *) (0x58021000 + 0) |= 1;  // Set B0-B15 to input mode
    // * (volatile uint32_t *) (0x58021000 + 0x18) |= 1;  // Set B0-B15 to input mode
    for (;;) {
        // * (volatile uint32_t *) (0x58024400 + 0x0E0) |= 1;  // EMABLE CLOCK
        // * (volatile uint32_t *) (0x58021000 + 0) |= 1;  // Set B0-B15 to input mode
        // * (volatile uint32_t *) (0x58021000 + 0x18) |= 1;  // Set B0-B15 to input mode
    }                    // Infinite loop
    return 0; // Do nothing so far
}

// Startup code
__attribute__((naked, noreturn)) void Reset_Handler(void) {
  // memset .bss to zero, and copy .data section to RAM region
  extern long _sbss, _ebss, _sdata, _edata, _sidata;
  for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;
  for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;

  main();             // Call main()
  for (;;) (void) 0;  // Infinite loop in the case if main() returns
}