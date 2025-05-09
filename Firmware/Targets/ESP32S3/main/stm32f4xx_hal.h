#pragma once

#include <cstdint>
/*
 * First a brief introduction:
 * Yes this file is very long. I would love to just port the entire
 * stm32 drivers but... that takes time (guess how i know that)
 * so im doing it like this now...
 *
 * Also: this file has most of our defines:
 * https://raw.githubusercontent.com/Ultrawipf/OpenFFBoard/refs/heads/development/Firmware/Targets/F407VG/Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f407xx.h
 * This file is pretty big, it doesnt get indexed by github and as a result you dont find what you need.
 * If you cant find something look here first.
 */


// GENERAL HAL INCLUDES AND DEFINES
#define __IO volatile  //i probably dont even need this i could just leave this empty...

typedef enum
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

typedef enum
{
  HAL_UNLOCKED = 0x00U,
  HAL_LOCKED   = 0x01U
} HAL_LockTypeDef;

uint32_t __get_PRIMASK() {
    //this func. should return the primask register.
    //used for dfu detection.
    return 0U;
}

uint32_t __get_IPSR(){
    return 0U;
}



















//--------------------- stm32f4xx_hal_tim ---------------------//

#define TIM_CHANNEL_1 0x00000000U
#define TIM_CHANNEL_2 0x00000000U
#define TIM_CHANNEL_3 0x00000000U
#define TIM_CHANNEL_4 0x00000000U

typedef struct
{
  __IO uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
  __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
  __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
  __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
  __IO uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
  __IO uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
  __IO uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
} TIM_TypeDef;

typedef struct
{
  uint32_t Prescaler;
  uint32_t CounterMode;
  uint32_t Period;
  uint32_t ClockDivision;
  uint32_t RepetitionCounter;
  uint32_t AutoReloadPreload;
} TIM_Base_InitTypeDef;

typedef enum
{
  HAL_TIM_ACTIVE_CHANNEL_1        = 0x01U,
  HAL_TIM_ACTIVE_CHANNEL_2        = 0x02U,
  HAL_TIM_ACTIVE_CHANNEL_3        = 0x04U,
  HAL_TIM_ACTIVE_CHANNEL_4        = 0x08U,
  HAL_TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U
} HAL_TIM_ActiveChannel;

typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,    /*!< Peripheral not yet initialized or disabled  */
  HAL_TIM_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use    */
  HAL_TIM_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing              */
  HAL_TIM_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state                               */
  HAL_TIM_STATE_ERROR             = 0x04U     /*!< Reception process is ongoing                */
} HAL_TIM_StateTypeDef;

typedef struct
{
  TIM_TypeDef                        *Instance;         /*!< Register base address                             */
  TIM_Base_InitTypeDef               Init;              /*!< TIM Time Base required parameters                 */
  HAL_TIM_ActiveChannel              Channel;           /*!< Active channel                                    */
  //DMA_HandleTypeDef                  *hdma[7];          // this is not even used, so no need to do define
  HAL_LockTypeDef                    Lock;              /*!< Locking object                                    */
  __IO HAL_TIM_StateTypeDef          State;             /*!< TIM operation state                               */
  //__IO HAL_TIM_ChannelStateTypeDef   ChannelState[4];   /*!< TIM channel operation state                       */
  //__IO HAL_TIM_ChannelStateTypeDef   ChannelNState[4];  /*!< TIM complementary channel operation state         */
  //__IO HAL_TIM_DMABurstStateTypeDef  DMABurstState;    this too.. only used in drivers itself
} TIM_HandleTypeDef;




//--------------------- stm32f4xx_hal_i2c ---------------------//
typedef struct
{
  __IO uint32_t CR1;        /*!< I2C Control register 1,     Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< I2C Control register 2,     Address offset: 0x04 */
  __IO uint32_t OAR1;       /*!< I2C Own address register 1, Address offset: 0x08 */
  __IO uint32_t OAR2;       /*!< I2C Own address register 2, Address offset: 0x0C */
  __IO uint32_t DR;         /*!< I2C Data register,          Address offset: 0x10 */
  __IO uint32_t SR1;        /*!< I2C Status register 1,      Address offset: 0x14 */
  __IO uint32_t SR2;        /*!< I2C Status register 2,      Address offset: 0x18 */
  __IO uint32_t CCR;        /*!< I2C Clock control register, Address offset: 0x1C */
  __IO uint32_t TRISE;      /*!< I2C TRISE register,         Address offset: 0x20 */
} I2C_TypeDef;

typedef struct
{
  uint32_t ClockSpeed;
  uint32_t DutyCycle;
  uint32_t OwnAddress1;
  uint32_t AddressingMode;
  uint32_t DualAddressMode;
  uint32_t OwnAddress2;
  uint32_t GeneralCallMode;
  uint32_t NoStretchMode;
} I2C_InitTypeDef;

typedef struct
{
  I2C_TypeDef                *Instance;
  I2C_InitTypeDef            Init;
  uint8_t                    *pBuffPtr;
  uint16_t                   XferSize;
  __IO uint16_t              XferCount;
  __IO uint32_t              XferOptions;
  __IO uint32_t              PreviousState;
  //DMA_HandleTypeDef          *hdmatx;
  //DMA_HandleTypeDef          *hdmarx;
  HAL_LockTypeDef            Lock;           /*!< I2C locking object                       */
  //__IO HAL_I2C_StateTypeDef  State;          /*!< I2C communication state                  */
  //__IO HAL_I2C_ModeTypeDef   Mode;           /*!< I2C communication mode                   */
  __IO uint32_t              ErrorCode;      /*!< I2C Error code                           */
  __IO uint32_t              Devaddress;     /*!< I2C Target device address                */
  __IO uint32_t              Memaddress;     /*!< I2C Target memory address                */
  __IO uint32_t              MemaddSize;     /*!< I2C Target memory address  size          */
  __IO uint32_t              EventCount;     /*!< I2C Event counter                        */

} I2C_HandleTypeDef;


//--------------------- stm32f4xx_hal_gpio ---------------------//
//wow, i guess gpio wil have the most defines and functions we'll ever see
//TODO: replace these with esp idf variants
#define  GPIO_NOPULL        0x00000000U
#define  GPIO_PULLUP        0x00000001U
#define  GPIO_PULLDOWN      0x00000002U

#define  GPIO_MODE_INPUT
#define  GPIO_MODE_OUTPUT_PP
#define  GPIO_MODE_OUTPUT_OD
#define  GPIO_MODE_AF_PP
#define  GPIO_MODE_AF_OD

#define  GPIO_MODE_ANALOG

#define  GPIO_MODE_IT_RISING
#define  GPIO_MODE_IT_FALLING
#define  GPIO_MODE_IT_RISING_FALLING

#define  GPIO_MODE_EVT_RISING
#define  GPIO_MODE_EVT_FALLING
#define  GPIO_MODE_EVT_RISING_FALLING

#define  GPIO_SPEED_FREQ_LOW         0x00000000U
#define  GPIO_SPEED_FREQ_MEDIUM      0x00000001U
#define  GPIO_SPEED_FREQ_HIGH        0x00000002U
#define  GPIO_SPEED_FREQ_VERY_HIGH   0x00000003U

typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
}GPIO_PinState;


typedef struct
{
  __IO uint32_t MODER;
  __IO uint32_t OTYPER;
  __IO uint32_t OSPEEDR;
  __IO uint32_t PUPDR;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t LCKR;
  __IO uint32_t AFR[2];
} GPIO_TypeDef;

typedef struct
{
  uint32_t Pin;
  uint32_t Mode;
  uint32_t Pull;
  uint32_t Speed;
  uint32_t Alternate;
} GPIO_InitTypeDef;







//--------------------- stm32f4xx_hal_spi ---------------------//

typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SR;
  __IO uint32_t DR;
  __IO uint32_t CRCPR;
  __IO uint32_t RXCRCR;
  __IO uint32_t TXCRCR;
  __IO uint32_t I2SCFGR;
  __IO uint32_t I2SPR;
} SPI_TypeDef;

typedef struct
{
  uint32_t Mode;
  uint32_t Direction;
  uint32_t DataSize;
  uint32_t CLKPolarity;
  uint32_t CLKPhase;
  uint32_t NSS;
  uint32_t BaudRatePrescaler;
  uint32_t FirstBit;
  uint32_t TIMode;
  uint32_t CRCCalculation;
  uint32_t CRCPolynomial;
} SPI_InitTypeDef;

typedef enum
{
  HAL_SPI_STATE_RESET      = 0x00U,    /*!< Peripheral not Initialized                         */
  HAL_SPI_STATE_READY      = 0x01U,    /*!< Peripheral Initialized and ready for use           */
  HAL_SPI_STATE_BUSY       = 0x02U,    /*!< an internal process is ongoing                     */
  HAL_SPI_STATE_BUSY_TX    = 0x03U,    /*!< Data Transmission process is ongoing               */
  HAL_SPI_STATE_BUSY_RX    = 0x04U,    /*!< Data Reception process is ongoing                  */
  HAL_SPI_STATE_BUSY_TX_RX = 0x05U,    /*!< Data Transmission and Reception process is ongoing */
  HAL_SPI_STATE_ERROR      = 0x06U,    /*!< SPI error state                                    */
  HAL_SPI_STATE_ABORT      = 0x07U     /*!< SPI abort is ongoing                               */
} HAL_SPI_StateTypeDef;

#define SPI_POLARITY_LOW                (0x00000000U)
#define SPI_POLARITY_HIGH               (0x00000001U)

#define SPI_MODE_SLAVE                  (0x00000000U)
#define SPI_MODE_MASTER                 (0x00000001U)

#define SPI_DIRECTION_2LINES            (0x00000000U)
#define SPI_DIRECTION_2LINES_RXONLY     (0x00000001U)
#define SPI_DIRECTION_1LINE             (0x00000002U)

#define SPI_DATASIZE_8BIT               (0x00000000U)
#define SPI_DATASIZE_16BIT              (0x00000001U)

#define SPI_PHASE_1EDGE                 (0x00000000U)
#define SPI_PHASE_2EDGE                 (0x00000001U)

#define SPI_NSS_SOFT                    (0x00000001U)
#define SPI_NSS_HARD_INPUT              (0x00000000U)
#define SPI_NSS_HARD_OUTPUT             (0x00000002U)

#define SPI_BAUDRATEPRESCALER_2         (0x00000000U)
#define SPI_BAUDRATEPRESCALER_4         (0x00000001U)
#define SPI_BAUDRATEPRESCALER_8         (0x00000002U)
#define SPI_BAUDRATEPRESCALER_16        (0x00000003U)
#define SPI_BAUDRATEPRESCALER_32        (0x00000004U)
#define SPI_BAUDRATEPRESCALER_64        (0x00000005U)
#define SPI_BAUDRATEPRESCALER_128       (0x00000006U)
#define SPI_BAUDRATEPRESCALER_256       (0x00000007U)

#define SPI_FIRSTBIT_MSB                (0x00000000U)
#define SPI_FIRSTBIT_LSB                (0x00000001U)

typedef struct
{
  SPI_TypeDef                *Instance;
  SPI_InitTypeDef            Init;
  const uint8_t              *pTxBuffPtr;
  uint16_t                   TxXferSize;
  __IO uint16_t              TxXferCount;
  uint8_t                    *pRxBuffPtr;
  uint16_t                   RxXferSize;
  __IO uint16_t              RxXferCount;
  //void (*RxISR)(struct __SPI_HandleTypeDef *h
  //void (*TxISR)(struct __SPI_HandleTypeDef *h
  //DMA_HandleTypeDef          *hdmatx;
  //DMA_HandleTypeDef          *hdmarx;
  HAL_LockTypeDef            Lock;
  __IO HAL_SPI_StateTypeDef  State;
  __IO uint32_t              ErrorCode;

} SPI_HandleTypeDef;





//--------------------- stm32f4xx_hal_uart ---------------------//

typedef struct
{
  __IO uint32_t SR;
  __IO uint32_t DR;
  __IO uint32_t BRR;
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t CR3;
  __IO uint32_t GTPR;
} USART_TypeDef;

typedef struct
{
  uint32_t BaudRate;
  uint32_t WordLength;
  uint32_t StopBits;
  uint32_t Parity;
  uint32_t Mode;
  uint32_t HwFlowCtl;
  uint32_t OverSampling;
} UART_InitTypeDef;

typedef struct
{
  USART_TypeDef                 *Instance;
  UART_InitTypeDef              Init;
  const uint8_t                 *pTxBuffPtr;
  uint16_t                      TxXferSize;
  __IO uint16_t                 TxXferCount;
  uint8_t                       *pRxBuffPtr;
  uint16_t                      RxXferSize;
  __IO uint16_t                 RxXferCount;
  //__IO HAL_UART_RxTypeTypeDef ReceptionType;
  //__IO HAL_UART_RxEventTypeTypeDef RxEventType;
  //DMA_HandleTypeDef             *hdmatx;
  //DMA_HandleTypeDef             *hdmarx;
  HAL_LockTypeDef               Lock;
  //__IO HAL_UART_StateTypeDef    gState;
  //__IO HAL_UART_StateTypeDef    RxState;
  __IO uint32_t                 ErrorCode;

} UART_HandleTypeDef;
