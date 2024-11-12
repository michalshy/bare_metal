/*
 * peripherals.h
 *
 *  Created on: Nov 12, 2024
 *      Author: Michin
 */

#ifndef PERIPHERALS_H_
#define PERIPHERALS_H_

#include "typedef.h"

#define PERIPH_BASE (0x40000000UL)

#define D3_AHB1PERIPH_BASE (PERIPH_BASE + 0x18020000UL)

/*!< D3_AHB1PERIPH peripherals */
#define GPIOA_BASE            (D3_AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (D3_AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (D3_AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (D3_AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (D3_AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (D3_AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (D3_AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (D3_AHB1PERIPH_BASE + 0x1C00UL)
#define GPIOJ_BASE            (D3_AHB1PERIPH_BASE + 0x2400UL)
#define GPIOK_BASE            (D3_AHB1PERIPH_BASE + 0x2800UL)
#define RCC_BASE              (D3_AHB1PERIPH_BASE + 0x4400UL)

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOJ               ((GPIO_TypeDef *) GPIOJ_BASE)
#define GPIOK               ((GPIO_TypeDef *) GPIOK_BASE)
#define RCC ((RCC_TypeDef *) RCC_BASE)

/********************  Bit definition for RCC_AHB4ENR register  ******************/
#define RCC_AHB4ENR_GPIOAEN_Pos                (0U)
#define RCC_AHB4ENR_GPIOAEN_Msk                (0x1UL << RCC_AHB4ENR_GPIOAEN_Pos)         /*!< 0x00000001 */
#define RCC_AHB4ENR_GPIOAEN                    RCC_AHB4ENR_GPIOAEN_Msk
#define RCC_AHB4ENR_GPIOBEN_Pos                (1U)
#define RCC_AHB4ENR_GPIOBEN_Msk                (0x1UL << RCC_AHB4ENR_GPIOBEN_Pos)         /*!< 0x00000002 */
#define RCC_AHB4ENR_GPIOBEN                    RCC_AHB4ENR_GPIOBEN_Msk
#define RCC_AHB4ENR_GPIOCEN_Pos                (2U)
#define RCC_AHB4ENR_GPIOCEN_Msk                (0x1UL << RCC_AHB4ENR_GPIOCEN_Pos)         /*!< 0x00000004 */
#define RCC_AHB4ENR_GPIOCEN                    RCC_AHB4ENR_GPIOCEN_Msk
#define RCC_AHB4ENR_GPIODEN_Pos                (3U)
#define RCC_AHB4ENR_GPIODEN_Msk                (0x1UL << RCC_AHB4ENR_GPIODEN_Pos)         /*!< 0x00000008 */
#define RCC_AHB4ENR_GPIODEN                    RCC_AHB4ENR_GPIODEN_Msk
#define RCC_AHB4ENR_GPIOEEN_Pos                (4U)
#define RCC_AHB4ENR_GPIOEEN_Msk                (0x1UL << RCC_AHB4ENR_GPIOEEN_Pos)         /*!< 0x00000010 */
#define RCC_AHB4ENR_GPIOEEN                    RCC_AHB4ENR_GPIOEEN_Msk
#define RCC_AHB4ENR_GPIOFEN_Pos                (5U)
#define RCC_AHB4ENR_GPIOFEN_Msk                (0x1UL << RCC_AHB4ENR_GPIOFEN_Pos)         /*!< 0x00000020 */
#define RCC_AHB4ENR_GPIOFEN                    RCC_AHB4ENR_GPIOFEN_Msk
#define RCC_AHB4ENR_GPIOGEN_Pos                (6U)
#define RCC_AHB4ENR_GPIOGEN_Msk                (0x1UL << RCC_AHB4ENR_GPIOGEN_Pos)         /*!< 0x00000040 */
#define RCC_AHB4ENR_GPIOGEN                    RCC_AHB4ENR_GPIOGEN_Msk
#define RCC_AHB4ENR_GPIOHEN_Pos                (7U)
#define RCC_AHB4ENR_GPIOHEN_Msk                (0x1UL << RCC_AHB4ENR_GPIOHEN_Pos)         /*!< 0x00000080 */
#define RCC_AHB4ENR_GPIOHEN                    RCC_AHB4ENR_GPIOHEN_Msk
#define RCC_AHB4ENR_GPIOJEN_Pos                (9U)
#define RCC_AHB4ENR_GPIOJEN_Msk                (0x1UL << RCC_AHB4ENR_GPIOJEN_Pos)         /*!< 0x00000200 */
#define RCC_AHB4ENR_GPIOJEN                    RCC_AHB4ENR_GPIOJEN_Msk
#define RCC_AHB4ENR_GPIOKEN_Pos                (10U)
#define RCC_AHB4ENR_GPIOKEN_Msk                (0x1UL << RCC_AHB4ENR_GPIOKEN_Pos)         /*!< 0x00000400 */
#define RCC_AHB4ENR_GPIOKEN                    RCC_AHB4ENR_GPIOKEN_Msk
#define RCC_AHB4ENR_CRCEN_Pos                  (19U)
#define RCC_AHB4ENR_CRCEN_Msk                  (0x1UL << RCC_AHB4ENR_CRCEN_Pos)           /*!< 0x00080000 */
#define RCC_AHB4ENR_CRCEN                      RCC_AHB4ENR_CRCEN_Msk
#define RCC_AHB4ENR_BDMAEN_Pos                 (21U)
#define RCC_AHB4ENR_BDMAEN_Msk                 (0x1UL << RCC_AHB4ENR_BDMAEN_Pos)          /*!< 0x00200000 */
#define RCC_AHB4ENR_BDMAEN                     RCC_AHB4ENR_BDMAEN_Msk
#define RCC_AHB4ENR_ADC3EN_Pos                 (24U)
#define RCC_AHB4ENR_ADC3EN_Msk                 (0x1UL << RCC_AHB4ENR_ADC3EN_Pos)          /*!< 0x01000000 */
#define RCC_AHB4ENR_ADC3EN                     RCC_AHB4ENR_ADC3EN_Msk
#define RCC_AHB4ENR_HSEMEN_Pos                 (25U)
#define RCC_AHB4ENR_HSEMEN_Msk                 (0x1UL << RCC_AHB4ENR_HSEMEN_Pos)          /*!< 0x02000000 */
#define RCC_AHB4ENR_HSEMEN                     RCC_AHB4ENR_HSEMEN_Msk
#define RCC_AHB4ENR_BKPRAMEN_Pos               (28U)
#define RCC_AHB4ENR_BKPRAMEN_Msk               (0x1UL << RCC_AHB4ENR_BKPRAMEN_Pos)        /*!< 0x10000000 */
#define RCC_AHB4ENR_BKPRAMEN                   RCC_AHB4ENR_BKPRAMEN_Msk




#endif /* PERIPHERALS_H_ */
