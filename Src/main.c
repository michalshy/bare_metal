
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

#include "peripherals.h"

#define BIT(x) (1UL << (x))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define PINNO(pin) (pin & 255)
#define PINBANK(pin) (pin >> 8)

#define GPIO(bank) ((GPIO_TypeDef *) (D3_AHB1PERIPH_BASE + 0x400 * (bank)))

// Enum values are per datasheet: 0, 1, 2, 3
enum { GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG };

static inline void gpio_set_mode(uint16_t pin, uint8_t mode) {
	GPIO_TypeDef * gpio = GPIO(PINBANK(pin));  // GPIO bank
	int n = PINNO(pin);                      // Pin number
	gpio->MODER &= ~(3U << (n * 2));         // Clear existing setting
	gpio->MODER |= (mode & 3) << (n * 2);    // Set new mode
}

static inline void gpio_write(uint16_t pin, bool val) {
	GPIO_TypeDef * gpio = GPIO(PINBANK(pin));
	gpio->BSRR = (1U << PINNO(pin)) << (val ? 0 : 16);
}

static inline bool gpio_read(uint16_t pin) {
	GPIO_TypeDef * gpio = GPIO(PINBANK(pin));
	return gpio->IDR;
}

enum BUTTON_STATE {
	LOW = 0,
	HIGH
};



/* Main program. */
int main(void) {
	uint16_t led_red = PIN('B', 14);
	uint16_t led_yellow = PIN('E', 1);
	uint16_t button = PIN('C', 13);

	RCC->AHB4ENR |= BIT(PINBANK(led_red));
	RCC->AHB4ENR |= BIT(PINBANK(led_yellow));
	RCC->AHB4ENR |= BIT(PINBANK(button));

	gpio_set_mode(button, GPIO_MODE_INPUT);
	gpio_set_mode(led_yellow, GPIO_MODE_OUTPUT);
	gpio_set_mode(led_red, GPIO_MODE_OUTPUT);

	bool state = LOW;
	bool toSwitch = HIGH;
	bool block = 0;

	while (1) {
		//Change LED based on state change rather than just LED pressing
		state = gpio_read(button);
		if(state == LOW)
		{
			block = false;
		}
		if(state == HIGH && !block)
		{
			gpio_write(led_yellow, toSwitch);
			toSwitch = !toSwitch;
			block = true;
		}
	}
}
