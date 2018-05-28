/**************************************************************************//**
 * @file     CMSDK_IoT.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
 *           IoT Device
 * @version  V3.02
 * @date     15. November 2013
  ******************************************************************************/
/* Copyright (c) 2013 - 2016 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


#ifndef CMSDK_IoT_H
#define CMSDK_IoT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn
{
/* -------------------  Cortex-IoT Processor Exceptions Numbers  ------------------ */
  NonMaskableInt_IRQn           = -14,        /*    Non Maskable Interrupt          */
  HardFault_IRQn                = -13,        /*    HardFault Interrupt             */
  MemoryManagement_IRQn         = -12,        /*    Memory Management Interrupt     */
  BusFault_IRQn                 = -11,        /*    Bus Fault Interrupt             */
  UsageFault_IRQn               = -10,        /*    Usage Fault Interrupt           */
  SecureFault_IRQn              = -9,         /*    Secure Fault Interrupt          */
  SVCall_IRQn                   =  -5,        /*    SV Call Interrupt               */
  DebugMonitor_IRQn             =  -4,        /*    Debug Monitor Interrupt         */
  PendSV_IRQn                   =  -2,        /*    Pend SV Interrupt               */
  SysTick_IRQn                  =  -1,        /*    System Tick Interrupt           */

/* ----------------------  Core_IoT Specific Interrupt Numbers  ------------------- */
  NONSEC_WATCHDOG_RESET_IRQn    = 0,       /* Non-Secure Watchdog Reset Interrupt   */
  NONSEC_WATCHDOG_IRQn          = 1,       /* Non-Secure Watchdog Interrupt         */
  S32K_TIMER_IRQn               = 2,       /* S32K Timer Interrupt                  */
  TIMER0_IRQn                   = 3,       /* TIMER 0 Interrupt                     */
  TIMER1_IRQn                   = 4,       /* TIMER 1 Interrupt                     */
  DUALTIMER_IRQn                = 5,       /* Dual Timer Interrupt                  */
  MHU_0_IRQn                    = 6,       /* Message Handling Unit 0               */
  MHU_1_IRQn                    = 7,       /* Message Handling Unit 1               */
  MPC_IRQn                      = 9,       /* MPC Combined (Secure) Interrupt       */
  PPC_IRQn                      = 10,      /* PPC Combined (Secure) Interrupt       */
  MSC_IRQn                      = 11,      /* MSC Combined (Secure) Interrput       */
  BRIDGE_ERROR_IRQn             = 12,      /* Bridge Error Combined (Secure) Interrupt */
  CPU_0_Cache_Invalid_IRQn      = 13,      /* CPU 0 Instruction Cache Invaidation Interrupt */
  
  SYS_PPU_IRQn                  = 15,      /* SYS_PPU Interrupt                     */

/* ----------------------  Expansion Specific Interrupt Numbers  ------------------ */
  EXT_IRQn                      = 32,      /* Musca Interrupt                       */
  GPTIMER_IRQn                  = 33,      /* General Purpose Timer Interrupt       */
  I2C0_IRQn                     = 34,      /* I2C 0 Interrupt                       */
  I2C1_IRQn                     = 35,      /* I2C 1 Interrupt                       */
  I2S_IRQn                      = 36,      /* I2S Interrupt                         */
  SPI_IRQn                      = 37,      /* SPI Interrupt                         */
  QSPI_IRQn                     = 38,      /* QSPI Interrupt                        */
  UARTRX0_IRQ                   = 39,      /* UART 0 RX FIFO Interrupt  active HIGH */
  UARTTX0_IRQ                   = 40,      /* UART 0 TX FIFO Interrupt  active HIGH */
  UARTRT0_IRQ                   = 41,      /* UART 0 RX Timeout Interrupt           */
  UARTMS0_IRQ                   = 42,      /* UART 0 Modem Status Interrupt         */
  UARTER0_IRQ                   = 43,      /* UART 0 Error Interrupt                */
  UART0_IRQ                     = 44,      /* UART 0 Interrupt active HIGH          */
  UARTRX1_IRQ                   = 45,      /* UART 1 RX FIFO Interrupt  active HIGH */
  UARTTX1_IRQ                   = 46,      /* UART 1 TX FIFO Interrupt  active HIGH */
  UARTRT1_IRQ                   = 47,      /* UART 1 RX Timeout Interrupt           */
  UARTMS1_IRQ                   = 48,      /* UART 1 Modem Status Interrupt         */
  UARTER1_IRQ                   = 49,      /* UART 1 Error Interrupt                */
  UART1_IRQ                     = 50,      /* UART 1 Interrupt active HIGH          */
  GPIO0_0_IRQn                  = 51,      /* All P0 I/O pins used as irq source    */
  GPIO0_1_IRQn                  = 52,      /* There are 16 pins in total            */
  GPIO0_2_IRQn                  = 53,
  GPIO0_3_IRQn                  = 54,
  GPIO0_4_IRQn                  = 55,
  GPIO0_5_IRQn                  = 56,
  GPIO0_6_IRQn                  = 57,
  GPIO0_7_IRQn                  = 58,
  GPIO0_8_IRQn                  = 59,
  GPIO0_9_IRQn                  = 60,
  GPIO0_10_IRQn                 = 61,
  GPIO0_11_IRQn                 = 62,
  GPIO0_12_IRQn                 = 63,
  GPIO0_13_IRQn                 = 64,
  GPIO0_14_IRQn                 = 65,
  GPIO0_15_IRQn                 = 66,
  GPIO0_IRQn                    = 67,       /* GPIO 0 Combined Interrupt             */
  PVT_IRQn                      = 68,       /* PVT Sensor Interrupt                  */
  WAHOO_IRQn                    = 69,       /* Wahoo Interrupt                       */
  PWM0_IRQn                     = 70,       /* PWM 0 Interrupt                       */
  RTC_IRQn                      = 71,       /* RTC Interrupt                         */
  GPTIMER0_IRQn                 = 72,       /* General Purpose Timer 0 Interrupt     */
  GPTIMER1_IRQn                 = 73,       /* General Purpose Timer 1 Interrupt     */
  PWM1_IRQn                     = 74,       /* PWM 1 Interrupt                       */
  PWM2_IRQn                     = 75        /* PWM 2 Interrupt                       */
} IRQn_Type;


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if defined ( __CC_ARM   )
  #pragma push
  #pragma anon_unions
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* --------  Configuration of the Cortex-ARMv8MBL Processor and Core Peripherals  ------- */
#define __ARMv8MBL_REV            0x0000U   /* Core revision r0p0 */
#define __SAU_PRESENT             1        /* SAU present */
#define __MPU_PRESENT             1        /* MPU present */
#define __VTOR_PRESENT            1        /* VTOR present */
#define __NVIC_PRIO_BITS          2        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0        /* Set to 1 if different SysTick Config is used */

#include "core_armv8mbl.h"                    /* Processor and core peripherals                  */
#include "system_CMSDK_IoT.h"                 /* System Header                                   */

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/*----------------------------- Timer (TIMER) -------------------------------*/
typedef struct
{
  __IO   uint32_t  CTRL;                     /* Offset: 0x000 (R/W) Control Register */
  __IO   uint32_t  VALUE;                    /* Offset: 0x004 (R/W) Current Value Register */
  __IO   uint32_t  RELOAD;                   /* Offset: 0x008 (R/W) Reload Value Register */
  union {
    __I    uint32_t  INTSTATUS;              /* Offset: 0x00C (R/ ) Interrupt Status Register */
    __O    uint32_t  INTCLEAR;               /* Offset: 0x00C ( /W) Interrupt Clear Register */
    };

} CMSDK_TIMER_TypeDef;

/* CMSDK_TIMER CTRL Register Definitions */
#define CMSDK_TIMER_CTRL_IRQEN_Pos          3                                              /* CMSDK_TIMER CTRL: IRQEN Position */
#define CMSDK_TIMER_CTRL_IRQEN_Msk          (0x01ul << CMSDK_TIMER_CTRL_IRQEN_Pos)         /* CMSDK_TIMER CTRL: IRQEN Mask */

#define CMSDK_TIMER_CTRL_SELEXTCLK_Pos      2                                              /* CMSDK_TIMER CTRL: SELEXTCLK Position */
#define CMSDK_TIMER_CTRL_SELEXTCLK_Msk      (0x01ul << CMSDK_TIMER_CTRL_SELEXTCLK_Pos)     /* CMSDK_TIMER CTRL: SELEXTCLK Mask */

#define CMSDK_TIMER_CTRL_SELEXTEN_Pos       1                                              /* CMSDK_TIMER CTRL: SELEXTEN Position */
#define CMSDK_TIMER_CTRL_SELEXTEN_Msk       (0x01ul << CMSDK_TIMER_CTRL_SELEXTEN_Pos)      /* CMSDK_TIMER CTRL: SELEXTEN Mask */

#define CMSDK_TIMER_CTRL_EN_Pos             0                                              /* CMSDK_TIMER CTRL: EN Position */
#define CMSDK_TIMER_CTRL_EN_Msk             (0x01ul << CMSDK_TIMER_CTRL_EN_Pos)            /* CMSDK_TIMER CTRL: EN Mask */

/* CMSDK_TIMER VAL Register Definitions */
#define CMSDK_TIMER_VAL_CURRENT_Pos         0                                              /* CMSDK_TIMER VALUE: CURRENT Position */
#define CMSDK_TIMER_VAL_CURRENT_Msk         (0xFFFFFFFFul << CMSDK_TIMER_VAL_CURRENT_Pos)  /* CMSDK_TIMER VALUE: CURRENT Mask */

/* CMSDK_TIMER RELOAD Register Definitions */
#define CMSDK_TIMER_RELOAD_VAL_Pos          0                                              /* CMSDK_TIMER RELOAD: RELOAD Position */
#define CMSDK_TIMER_RELOAD_VAL_Msk          (0xFFFFFFFFul << CMSDK_TIMER_RELOAD_VAL_Pos)   /* CMSDK_TIMER RELOAD: RELOAD Mask */

/* CMSDK_TIMER INTSTATUS Register Definitions */
#define CMSDK_TIMER_INTSTATUS_Pos           0                                              /* CMSDK_TIMER INTSTATUS: INTSTATUSPosition */
#define CMSDK_TIMER_INTSTATUS_Msk           (0x01ul << CMSDK_TIMER_INTSTATUS_Pos)          /* CMSDK_TIMER INTSTATUS: INTSTATUSMask */

/* CMSDK_TIMER INTCLEAR Register Definitions */
#define CMSDK_TIMER_INTCLEAR_Pos            0                                              /* CMSDK_TIMER INTCLEAR: INTCLEAR Position */
#define CMSDK_TIMER_INTCLEAR_Msk            (0x01ul << CMSDK_TIMER_INTCLEAR_Pos)           /* CMSDK_TIMER INTCLEAR: INTCLEAR Mask */


/*------------- Timer (TIM) --------------------------------------------------*/
typedef struct
{
  __IO uint32_t Timer1Load;                  /* Offset: 0x000 (R/W) Timer 1 Load */
  __I  uint32_t Timer1Value;                 /* Offset: 0x004 (R/ ) Timer 1 Counter Current Value */
  __IO uint32_t Timer1Control;               /* Offset: 0x008 (R/W) Timer 1 Control */
  __O  uint32_t Timer1IntClr;                /* Offset: 0x00C ( /W) Timer 1 Interrupt Clear */
  __I  uint32_t Timer1RIS;                   /* Offset: 0x010 (R/ ) Timer 1 Raw Interrupt Status */
  __I  uint32_t Timer1MIS;                   /* Offset: 0x014 (R/ ) Timer 1 Masked Interrupt Status */
  __IO uint32_t Timer1BGLoad;                /* Offset: 0x018 (R/W) Background Load Register */
       uint32_t RESERVED0;
  __IO uint32_t Timer2Load;                  /* Offset: 0x020 (R/W) Timer 2 Load */
  __I  uint32_t Timer2Value;                 /* Offset: 0x024 (R/ ) Timer 2 Counter Current Value */
  __IO uint32_t Timer2Control;               /* Offset: 0x028 (R/W) Timer 2 Control */
  __O  uint32_t Timer2IntClr;                /* Offset: 0x02C ( /W) Timer 2 Interrupt Clear */
  __I  uint32_t Timer2RIS;                   /* Offset: 0x030 (R/ ) Timer 2 Raw Interrupt Status */
  __I  uint32_t Timer2MIS;                   /* Offset: 0x034 (R/ ) Timer 2 Masked Interrupt Status */
  __IO uint32_t Timer2BGLoad;                /* Offset: 0x038 (R/W) Background Load Register */
       uint32_t RESERVED1[945];
  __IO uint32_t ITCR;                        /* Offset: 0xF00 (R/W) Integration Test Control Register */
  __O  uint32_t ITOP;                        /* Offset: 0xF04 ( /W) Integration Test Output Set Register */
} CMSDK_DUALTIMER_BOTH_TypeDef;

#define CMSDK_DUALTIMER1_LOAD_Pos            0                                                /* CMSDK_DUALTIMER1 LOAD: LOAD Position */
#define CMSDK_DUALTIMER1_LOAD_Msk            (0xFFFFFFFFul << CMSDK_DUALTIMER1_LOAD_Pos)      /* CMSDK_DUALTIMER1 LOAD: LOAD Mask */

#define CMSDK_DUALTIMER1_VALUE_Pos           0                                                /* CMSDK_DUALTIMER1 VALUE: VALUE Position */
#define CMSDK_DUALTIMER1_VALUE_Msk           (0xFFFFFFFFul << CMSDK_DUALTIMER1_VALUE_Pos)     /* CMSDK_DUALTIMER1 VALUE: VALUE Mask */

#define CMSDK_DUALTIMER1_CTRL_EN_Pos         7                                                /* CMSDK_DUALTIMER1 CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER1_CTRL_EN_Msk         (0x1ul << CMSDK_DUALTIMER1_CTRL_EN_Pos)          /* CMSDK_DUALTIMER1 CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER1_CTRL_MODE_Pos       6                                                /* CMSDK_DUALTIMER1 CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER1_CTRL_MODE_Msk       (0x1ul << CMSDK_DUALTIMER1_CTRL_MODE_Pos)        /* CMSDK_DUALTIMER1 CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER1_CTRL_INTEN_Pos      5                                                /* CMSDK_DUALTIMER1 CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER1_CTRL_INTEN_Msk      (0x1ul << CMSDK_DUALTIMER1_CTRL_INTEN_Pos)       /* CMSDK_DUALTIMER1 CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER1_CTRL_PRESCALE_Pos   2                                                /* CMSDK_DUALTIMER1 CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER1_CTRL_PRESCALE_Msk   (0x3ul << CMSDK_DUALTIMER1_CTRL_PRESCALE_Pos)    /* CMSDK_DUALTIMER1 CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER1_CTRL_SIZE_Pos       1                                                /* CMSDK_DUALTIMER1 CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER1_CTRL_SIZE_Msk       (0x1ul << CMSDK_DUALTIMER1_CTRL_SIZE_Pos)        /* CMSDK_DUALTIMER1 CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER1_CTRL_ONESHOOT_Pos   0                                                /* CMSDK_DUALTIMER1 CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER1_CTRL_ONESHOOT_Msk   (0x1ul << CMSDK_DUALTIMER1_CTRL_ONESHOOT_Pos)    /* CMSDK_DUALTIMER1 CTRL_ONESHOOT: CTRL ONESHOOT Mask */

#define CMSDK_DUALTIMER1_INTCLR_Pos          0                                                /* CMSDK_DUALTIMER1 INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER1_INTCLR_Msk          (0x1ul << CMSDK_DUALTIMER1_INTCLR_Pos)           /* CMSDK_DUALTIMER1 INTCLR: INT Clear  Mask */

#define CMSDK_DUALTIMER1_RAWINTSTAT_Pos      0                                                /* CMSDK_DUALTIMER1 RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER1_RAWINTSTAT_Msk      (0x1ul << CMSDK_DUALTIMER1_RAWINTSTAT_Pos)       /* CMSDK_DUALTIMER1 RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_DUALTIMER1_MASKINTSTAT_Pos     0                                                /* CMSDK_DUALTIMER1 MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER1_MASKINTSTAT_Msk     (0x1ul << CMSDK_DUALTIMER1_MASKINTSTAT_Pos)      /* CMSDK_DUALTIMER1 MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_DUALTIMER1_BGLOAD_Pos          0                                                /* CMSDK_DUALTIMER1 BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER1_BGLOAD_Msk          (0xFFFFFFFFul << CMSDK_DUALTIMER1_BGLOAD_Pos)    /* CMSDK_DUALTIMER1 BGLOAD: Background Load Mask */

#define CMSDK_DUALTIMER2_LOAD_Pos            0                                                /* CMSDK_DUALTIMER2 LOAD: LOAD Position */
#define CMSDK_DUALTIMER2_LOAD_Msk            (0xFFFFFFFFul << CMSDK_DUALTIMER2_LOAD_Pos)      /* CMSDK_DUALTIMER2 LOAD: LOAD Mask */

#define CMSDK_DUALTIMER2_VALUE_Pos           0                                                /* CMSDK_DUALTIMER2 VALUE: VALUE Position */
#define CMSDK_DUALTIMER2_VALUE_Msk           (0xFFFFFFFFul << CMSDK_DUALTIMER2_VALUE_Pos)     /* CMSDK_DUALTIMER2 VALUE: VALUE Mask */

#define CMSDK_DUALTIMER2_CTRL_EN_Pos         7                                                /* CMSDK_DUALTIMER2 CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER2_CTRL_EN_Msk         (0x1ul << CMSDK_DUALTIMER2_CTRL_EN_Pos)          /* CMSDK_DUALTIMER2 CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER2_CTRL_MODE_Pos       6                                                /* CMSDK_DUALTIMER2 CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER2_CTRL_MODE_Msk       (0x1ul << CMSDK_DUALTIMER2_CTRL_MODE_Pos)        /* CMSDK_DUALTIMER2 CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER2_CTRL_INTEN_Pos      5                                                /* CMSDK_DUALTIMER2 CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER2_CTRL_INTEN_Msk      (0x1ul << CMSDK_DUALTIMER2_CTRL_INTEN_Pos)       /* CMSDK_DUALTIMER2 CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER2_CTRL_PRESCALE_Pos   2                                                /* CMSDK_DUALTIMER2 CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER2_CTRL_PRESCALE_Msk   (0x3ul << CMSDK_DUALTIMER2_CTRL_PRESCALE_Pos)    /* CMSDK_DUALTIMER2 CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER2_CTRL_SIZE_Pos       1                                                /* CMSDK_DUALTIMER2 CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER2_CTRL_SIZE_Msk       (0x1ul << CMSDK_DUALTIMER2_CTRL_SIZE_Pos)        /* CMSDK_DUALTIMER2 CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER2_CTRL_ONESHOOT_Pos   0                                                /* CMSDK_DUALTIMER2 CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER2_CTRL_ONESHOOT_Msk   (0x1ul << CMSDK_DUALTIMER2_CTRL_ONESHOOT_Pos)    /* CMSDK_DUALTIMER2 CTRL_ONESHOOT: CTRL ONESHOOT Mask */

#define CMSDK_DUALTIMER2_INTCLR_Pos          0                                                /* CMSDK_DUALTIMER2 INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER2_INTCLR_Msk          (0x1ul << CMSDK_DUALTIMER2_INTCLR_Pos)           /* CMSDK_DUALTIMER2 INTCLR: INT Clear  Mask */

#define CMSDK_DUALTIMER2_RAWINTSTAT_Pos      0                                                /* CMSDK_DUALTIMER2 RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER2_RAWINTSTAT_Msk      (0x1ul << CMSDK_DUALTIMER2_RAWINTSTAT_Pos)       /* CMSDK_DUALTIMER2 RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_DUALTIMER2_MASKINTSTAT_Pos     0                                                /* CMSDK_DUALTIMER2 MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER2_MASKINTSTAT_Msk     (0x1ul << CMSDK_DUALTIMER2_MASKINTSTAT_Pos)      /* CMSDK_DUALTIMER2 MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_DUALTIMER2_BGLOAD_Pos          0                                                /* CMSDK_DUALTIMER2 BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER2_BGLOAD_Msk          (0xFFFFFFFFul << CMSDK_DUALTIMER2_BGLOAD_Pos)    /* CMSDK_DUALTIMER2 BGLOAD: Background Load Mask */


typedef struct
{
  __IO uint32_t TimerLoad;                   /* Offset: 0x000 (R/W) Timer Load */
  __I  uint32_t TimerValue;                  /* Offset: 0x000 (R/W) Timer Counter Current Value */
  __IO uint32_t TimerControl;                /* Offset: 0x000 (R/W) Timer Control */
  __O  uint32_t TimerIntClr;                 /* Offset: 0x000 (R/W) Timer Interrupt Clear */
  __I  uint32_t TimerRIS;                    /* Offset: 0x000 (R/W) Timer Raw Interrupt Status */
  __I  uint32_t TimerMIS;                    /* Offset: 0x000 (R/W) Timer Masked Interrupt Status */
  __IO uint32_t TimerBGLoad;                 /* Offset: 0x000 (R/W) Background Load Register */
} CMSDK_DUALTIMER_SINGLE_TypeDef;

/* CMSDK_DUALTIMER_SINGLE LOAD Register Definitions */
#define CMSDK_DUALTIMER_LOAD_Pos             0                                               /* CMSDK_DUALTIMER LOAD: LOAD Position */
#define CMSDK_DUALTIMER_LOAD_Msk             (0xFFFFFFFFul << CMSDK_DUALTIMER_LOAD_Pos)      /* CMSDK_DUALTIMER LOAD: LOAD Mask */

/* CMSDK_DUALTIMER_SINGLE VALUE Register Definitions */
#define CMSDK_DUALTIMER_VALUE_Pos            0                                               /* CMSDK_DUALTIMER VALUE: VALUE Position */
#define CMSDK_DUALTIMER_VALUE_Msk            (0xFFFFFFFFul << CMSDK_DUALTIMER_VALUE_Pos)     /* CMSDK_DUALTIMER VALUE: VALUE Mask */

/* CMSDK_DUALTIMER_SINGLE CTRL Register Definitions */
#define CMSDK_DUALTIMER_CTRL_EN_Pos          7                                               /* CMSDK_DUALTIMER CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER_CTRL_EN_Msk          (0x1ul << CMSDK_DUALTIMER_CTRL_EN_Pos)          /* CMSDK_DUALTIMER CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER_CTRL_MODE_Pos        6                                               /* CMSDK_DUALTIMER CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER_CTRL_MODE_Msk        (0x1ul << CMSDK_DUALTIMER_CTRL_MODE_Pos)        /* CMSDK_DUALTIMER CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER_CTRL_INTEN_Pos       5                                               /* CMSDK_DUALTIMER CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER_CTRL_INTEN_Msk       (0x1ul << CMSDK_DUALTIMER_CTRL_INTEN_Pos)       /* CMSDK_DUALTIMER CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER_CTRL_PRESCALE_Pos    2                                               /* CMSDK_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER_CTRL_PRESCALE_Msk    (0x3ul << CMSDK_DUALTIMER_CTRL_PRESCALE_Pos)    /* CMSDK_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER_CTRL_SIZE_Pos        1                                               /* CMSDK_DUALTIMER CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER_CTRL_SIZE_Msk        (0x1ul << CMSDK_DUALTIMER_CTRL_SIZE_Pos)        /* CMSDK_DUALTIMER CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER_CTRL_ONESHOOT_Pos    0                                               /* CMSDK_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER_CTRL_ONESHOOT_Msk    (0x1ul << CMSDK_DUALTIMER_CTRL_ONESHOOT_Pos)    /* CMSDK_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Mask */

/* CMSDK_DUALTIMER_SINGLE INTCLR Register Definitions */
#define CMSDK_DUALTIMER_INTCLR_Pos           0                                               /* CMSDK_DUALTIMER INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER_INTCLR_Msk           (0x1ul << CMSDK_DUALTIMER_INTCLR_Pos)           /* CMSDK_DUALTIMER INTCLR: INT Clear  Mask */

/* CMSDK_DUALTIMER_SINGLE RIS Register Definitions */
#define CMSDK_DUALTIMER_RAWINTSTAT_Pos       0                                               /* CMSDK_DUALTIMER RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER_RAWINTSTAT_Msk       (0x1ul << CMSDK_DUALTIMER_RAWINTSTAT_Pos)       /* CMSDK_DUALTIMER RAWINTSTAT: Raw Int Status Mask */

/* CMSDK_DUALTIMER_SINGLE MIS Register Definitions */
#define CMSDK_DUALTIMER_MASKINTSTAT_Pos      0                                               /* CMSDK_DUALTIMER MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER_MASKINTSTAT_Msk      (0x1ul << CMSDK_DUALTIMER_MASKINTSTAT_Pos)      /* CMSDK_DUALTIMER MASKINTSTAT: Mask Int Status Mask */

/* CMSDK_DUALTIMER_SINGLE BGLOAD Register Definitions */
#define CMSDK_DUALTIMER_BGLOAD_Pos           0                                               /* CMSDK_DUALTIMER BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER_BGLOAD_Msk           (0xFFFFFFFFul << CMSDK_DUALTIMER_BGLOAD_Pos)    /* CMSDK_DUALTIMER BGLOAD: Background Load Mask */


/*-------------------- General Purpose Input Output (GPIO) -------------------*/
typedef struct
{
  __IO   uint32_t  DATA;                     /* Offset: 0x000 (R/W) DATA Register */
  __IO   uint32_t  DATAOUT;                  /* Offset: 0x004 (R/W) Data Output Latch Register */
         uint32_t  RESERVED0[2];
  __IO   uint32_t  OUTENABLESET;             /* Offset: 0x010 (R/W) Output Enable Set Register */
  __IO   uint32_t  OUTENABLECLR;             /* Offset: 0x014 (R/W) Output Enable Clear Register */
  __IO   uint32_t  ALTFUNCSET;               /* Offset: 0x018 (R/W) Alternate Function Set Register */
  __IO   uint32_t  ALTFUNCCLR;               /* Offset: 0x01C (R/W) Alternate Function Clear Register */
  __IO   uint32_t  INTENSET;                 /* Offset: 0x020 (R/W) Interrupt Enable Set Register */
  __IO   uint32_t  INTENCLR;                 /* Offset: 0x024 (R/W) Interrupt Enable Clear Register */
  __IO   uint32_t  INTTYPESET;               /* Offset: 0x028 (R/W) Interrupt Type Set Register */
  __IO   uint32_t  INTTYPECLR;               /* Offset: 0x02C (R/W) Interrupt Type Clear Register */
  __IO   uint32_t  INTPOLSET;                /* Offset: 0x030 (R/W) Interrupt Polarity Set Register */
  __IO   uint32_t  INTPOLCLR;                /* Offset: 0x034 (R/W) Interrupt Polarity Clear Register */
  union {
    __I    uint32_t  INTSTATUS;              /* Offset: 0x038 (R/ ) Interrupt Status Register */
    __O    uint32_t  INTCLEAR;               /* Offset: 0x038 ( /W) Interrupt Clear Register */
    };
         uint32_t RESERVED1[241];
  __IO   uint32_t LB_MASKED[256];            /* Offset: 0x400 - 0x7FC Lower byte Masked Access Register (R/W) */
  __IO   uint32_t UB_MASKED[256];            /* Offset: 0x800 - 0xBFC Upper byte Masked Access Register (R/W) */
} CMSDK_GPIO_TypeDef;

/* CMSDK_GPIO DATA Register Definitions */
#define CMSDK_GPIO_DATA_Pos            0                                          /* CMSDK_GPIO DATA: DATA Position */
#define CMSDK_GPIO_DATA_Msk            (0xFFFFul << CMSDK_GPIO_DATA_Pos)          /* CMSDK_GPIO DATA: DATA Mask */

/* CMSDK_GPIO DATAOUT Register Definitions */
#define CMSDK_GPIO_DATAOUT_Pos         0                                          /* CMSDK_GPIO DATAOUT: DATAOUT Position */
#define CMSDK_GPIO_DATAOUT_Msk         (0xFFFFul << CMSDK_GPIO_DATAOUT_Pos)       /* CMSDK_GPIO DATAOUT: DATAOUT Mask */

/* CMSDK_GPIO OUTENSET Register Definitions */
#define CMSDK_GPIO_OUTENSET_Pos        0                                          /* CMSDK_GPIO OUTEN: OUTEN Position */
#define CMSDK_GPIO_OUTENSET_Msk        (0xFFFFul << CMSDK_GPIO_OUTEN_Pos)         /* CMSDK_GPIO OUTEN: OUTEN Mask */

/* CMSDK_GPIO OUTENCLR Register Definitions */
#define CMSDK_GPIO_OUTENCLR_Pos        0                                          /* CMSDK_GPIO OUTEN: OUTEN Position */
#define CMSDK_GPIO_OUTENCLR_Msk        (0xFFFFul << CMSDK_GPIO_OUTEN_Pos)         /* CMSDK_GPIO OUTEN: OUTEN Mask */

/* CMSDK_GPIO ALTFUNCSET Register Definitions */
#define CMSDK_GPIO_ALTFUNCSET_Pos      0                                          /* CMSDK_GPIO ALTFUNC: ALTFUNC Position */
#define CMSDK_GPIO_ALTFUNCSET_Msk      (0xFFFFul << CMSDK_GPIO_ALTFUNC_Pos)       /* CMSDK_GPIO ALTFUNC: ALTFUNC Mask */

/* CMSDK_GPIO ALTFUNCCLR Register Definitions */
#define CMSDK_GPIO_ALTFUNCCLR_Pos      0                                          /* CMSDK_GPIO ALTFUNC: ALTFUNC Position */
#define CMSDK_GPIO_ALTFUNCCLR_Msk      (0xFFFFul << CMSDK_GPIO_ALTFUNC_Pos)       /* CMSDK_GPIO ALTFUNC: ALTFUNC Mask */

/* CMSDK_GPIO INTENSET Register Definitions */
#define CMSDK_GPIO_INTENSET_Pos        0                                          /* CMSDK_GPIO INTEN: INTEN Position */
#define CMSDK_GPIO_INTENSET_Msk        (0xFFFFul << CMSDK_GPIO_INTEN_Pos)         /* CMSDK_GPIO INTEN: INTEN Mask */

/* CMSDK_GPIO INTENCLR Register Definitions */
#define CMSDK_GPIO_INTENCLR_Pos        0                                          /* CMSDK_GPIO INTEN: INTEN Position */
#define CMSDK_GPIO_INTENCLR_Msk        (0xFFFFul << CMSDK_GPIO_INTEN_Pos)         /* CMSDK_GPIO INTEN: INTEN Mask */

/* CMSDK_GPIO INTTYPESET Register Definitions */
#define CMSDK_GPIO_INTTYPESET_Pos      0                                          /* CMSDK_GPIO INTTYPE: INTTYPE Position */
#define CMSDK_GPIO_INTTYPESET_Msk      (0xFFFFul << CMSDK_GPIO_INTTYPE_Pos)       /* CMSDK_GPIO INTTYPE: INTTYPE Mask */

/* CMSDK_GPIO INTTYPECLR Register Definitions */
#define CMSDK_GPIO_INTTYPECLR_Pos      0                                          /* CMSDK_GPIO INTTYPE: INTTYPE Position */
#define CMSDK_GPIO_INTTYPECLR_Msk      (0xFFFFul << CMSDK_GPIO_INTTYPE_Pos)       /* CMSDK_GPIO INTTYPE: INTTYPE Mask */

/* CMSDK_GPIO INTPOLSET Register Definitions */
#define CMSDK_GPIO_INTPOLSET_Pos       0                                          /* CMSDK_GPIO INTPOL: INTPOL Position */
#define CMSDK_GPIO_INTPOLSET_Msk       (0xFFFFul << CMSDK_GPIO_INTPOL_Pos)        /* CMSDK_GPIO INTPOL: INTPOL Mask */

/* CMSDK_GPIO INTPOLCLR Register Definitions */
#define CMSDK_GPIO_INTPOLCLR_Pos       0                                          /* CMSDK_GPIO INTPOL: INTPOL Position */
#define CMSDK_GPIO_INTPOLCLR_Msk       (0xFFFFul << CMSDK_GPIO_INTPOL_Pos)        /* CMSDK_GPIO INTPOL: INTPOL Mask */

/* CMSDK_GPIO INTSTATUS Register Definitions */
#define CMSDK_GPIO_INTSTATUS_Pos       0                                          /* CMSDK_GPIO INTSTATUS: INTSTATUS Position */
#define CMSDK_GPIO_INTSTATUS_Msk       (0xFFul << CMSDK_GPIO_INTSTATUS_Pos)       /* CMSDK_GPIO INTSTATUS: INTSTATUS Mask */

/* CMSDK_GPIO INTCLEAR Register Definitions */
#define CMSDK_GPIO_INTCLEAR_Pos        0                                          /* CMSDK_GPIO INTCLEAR: INTCLEAR Position */
#define CMSDK_GPIO_INTCLEAR_Msk        (0xFFul << CMSDK_GPIO_INTCLEAR_Pos)        /* CMSDK_GPIO INTCLEAR: INTCLEAR Mask */

/* CMSDK_GPIO MASKLOWBYTE Register Definitions */
#define CMSDK_GPIO_MASKLOWBYTE_Pos     0                                          /* CMSDK_GPIO MASKLOWBYTE: MASKLOWBYTE Position */
#define CMSDK_GPIO_MASKLOWBYTE_Msk     (0x00FFul << CMSDK_GPIO_MASKLOWBYTE_Pos)   /* CMSDK_GPIO MASKLOWBYTE: MASKLOWBYTE Mask */

/* CMSDK_GPIO MASKHIGHBYTE Register Definitions */
#define CMSDK_GPIO_MASKHIGHBYTE_Pos    0                                          /* CMSDK_GPIO MASKHIGHBYTE: MASKHIGHBYTE Position */
#define CMSDK_GPIO_MASKHIGHBYTE_Msk    (0xFF00ul << CMSDK_GPIO_MASKHIGHBYTE_Pos)  /* CMSDK_GPIO MASKHIGHBYTE: MASKHIGHBYTE Mask */


/*------------- System Control (SYSCON) --------------------------------------*/
typedef struct
{
  __IO   uint32_t  REMAP;                    /* Offset: 0x000 (R/W) Remap Control Register */
  __IO   uint32_t  PMUCTRL;                  /* Offset: 0x004 (R/W) PMU Control Register */
  __IO   uint32_t  RESETOP;                  /* Offset: 0x008 (R/W) Reset Option Register */
  __IO   uint32_t  EMICTRL;                  /* Offset: 0x00C (R/W) EMI Control Register */
  __IO   uint32_t  RSTINFO;                  /* Offset: 0x010 (R/W) Reset Information Register */
} CMSDK_SYSCON_TypeDef;

/* CMSDK_SYSCON REMAP Register Definitions */
#define CMSDK_SYSCON_REMAP_Pos                 0
#define CMSDK_SYSCON_REMAP_Msk                 (0x01ul << CMSDK_SYSCON_REMAP_Pos)               /* CMSDK_SYSCON MEME_CTRL: REMAP Mask */

/* CMSDK_SYSCON PMUCTRL Register Definitions */
#define CMSDK_SYSCON_PMUCTRL_EN_Pos            0
#define CMSDK_SYSCON_PMUCTRL_EN_Msk            (0x01ul << CMSDK_SYSCON_PMUCTRL_EN_Pos)          /* CMSDK_SYSCON PMUCTRL: PMUCTRL ENABLE Mask */

/* CMSDK_SYSCON LOCKUPRST Register Definitions */
#define CMSDK_SYSCON_LOCKUPRST_RESETOP_Pos     0
#define CMSDK_SYSCON_LOCKUPRST_RESETOP_Msk     (0x01ul << CMSDK_SYSCON_LOCKUPRST_RESETOP_Pos)   /* CMSDK_SYSCON SYS_CTRL: LOCKUP RESET ENABLE Mask */

/* CMSDK_SYSCON EMICTRL Register Definitions */
#define CMSDK_SYSCON_EMICTRL_SIZE_Pos          24
#define CMSDK_SYSCON_EMICTRL_SIZE_Msk          (0x00001ul << CMSDK_SYSCON_EMICTRL_SIZE_Pos)     /* CMSDK_SYSCON EMICTRL: SIZE Mask */

#define CMSDK_SYSCON_EMICTRL_TACYC_Pos         16
#define CMSDK_SYSCON_EMICTRL_TACYC_Msk         (0x00007ul << CMSDK_SYSCON_EMICTRL_TACYC_Pos)    /* CMSDK_SYSCON EMICTRL: TURNAROUNDCYCLE Mask */

#define CMSDK_SYSCON_EMICTRL_WCYC_Pos          8
#define CMSDK_SYSCON_EMICTRL_WCYC_Msk          (0x00003ul << CMSDK_SYSCON_EMICTRL_WCYC_Pos)     /* CMSDK_SYSCON EMICTRL: WRITECYCLE Mask */

#define CMSDK_SYSCON_EMICTRL_RCYC_Pos          0
#define CMSDK_SYSCON_EMICTRL_RCYC_Msk          (0x00007ul << CMSDK_SYSCON_EMICTRL_RCYC_Pos)     /* CMSDK_SYSCON EMICTRL: READCYCLE Mask */

/* CMSDK_SYSCON RSTINFO Register Definitions */
#define CMSDK_SYSCON_RSTINFO_SYSRESETREQ_Pos   0
#define CMSDK_SYSCON_RSTINFO_SYSRESETREQ_Msk   (0x00001ul << CMSDK_SYSCON_RSTINFO_SYSRESETREQ_Pos) /* CMSDK_SYSCON RSTINFO: SYSRESETREQ Mask */

#define CMSDK_SYSCON_RSTINFO_WDOGRESETREQ_Pos  1
#define CMSDK_SYSCON_RSTINFO_WDOGRESETREQ_Msk  (0x00001ul << CMSDK_SYSCON_RSTINFO_WDOGRESETREQ_Pos) /* CMSDK_SYSCON RSTINFO: WDOGRESETREQ Mask */

#define CMSDK_SYSCON_RSTINFO_LOCKUPRESET_Pos   2
#define CMSDK_SYSCON_RSTINFO_LOCKUPRESET_Msk   (0x00001ul << CMSDK_SYSCON_RSTINFO_LOCKUPRESET_Pos) /* CMSDK_SYSCON RSTINFO: LOCKUPRESET Mask */




/*------------------- Watchdog ----------------------------------------------*/
typedef struct
{

  __IO    uint32_t  LOAD;                   /* Offset: 0x000 (R/W) Watchdog Load Register */
  __I     uint32_t  VALUE;                  /* Offset: 0x004 (R/ ) Watchdog Value Register */
  __IO    uint32_t  CTRL;                   /* Offset: 0x008 (R/W) Watchdog Control Register */
  __O     uint32_t  INTCLR;                 /* Offset: 0x00C ( /W) Watchdog Clear Interrupt Register */
  __I     uint32_t  RAWINTSTAT;             /* Offset: 0x010 (R/ ) Watchdog Raw Interrupt Status Register */
  __I     uint32_t  MASKINTSTAT;            /* Offset: 0x014 (R/ ) Watchdog Interrupt Status Register */
        uint32_t  RESERVED0[762];
  __IO    uint32_t  LOCK;                   /* Offset: 0xC00 (R/W) Watchdog Lock Register */
        uint32_t  RESERVED1[191];
  __IO    uint32_t  ITCR;                   /* Offset: 0xF00 (R/W) Watchdog Integration Test Control Register */
  __O     uint32_t  ITOP;                   /* Offset: 0xF04 ( /W) Watchdog Integration Test Output Set Register */
}CMSDK_WATCHDOG_TypeDef;

/* CMSDK_WATCHDOG LOAD Register Definitions */
#define CMSDK_Watchdog_LOAD_Pos               0                                              /* CMSDK_Watchdog LOAD: LOAD Position */
#define CMSDK_Watchdog_LOAD_Msk              (0xFFFFFFFFul << CMSDK_Watchdog_LOAD_Pos)       /* CMSDK_Watchdog LOAD: LOAD Mask */

/* CMSDK_WATCHDOG VALUE Register Definitions */
#define CMSDK_Watchdog_VALUE_Pos              0                                              /* CMSDK_Watchdog VALUE: VALUE Position */
#define CMSDK_Watchdog_VALUE_Msk             (0xFFFFFFFFul << CMSDK_Watchdog_VALUE_Pos)      /* CMSDK_Watchdog VALUE: VALUE Mask */

/* CMSDK_WATCHDOG CTRL Register Definitions */
#define CMSDK_Watchdog_CTRL_RESEN_Pos         1                                              /* CMSDK_Watchdog CTRL_RESEN: Enable Reset Output Position */
#define CMSDK_Watchdog_CTRL_RESEN_Msk        (0x1ul << CMSDK_Watchdog_CTRL_RESEN_Pos)        /* CMSDK_Watchdog CTRL_RESEN: Enable Reset Output Mask */

#define CMSDK_Watchdog_CTRL_INTEN_Pos         0                                              /* CMSDK_Watchdog CTRL_INTEN: Int Enable Position */
#define CMSDK_Watchdog_CTRL_INTEN_Msk        (0x1ul << CMSDK_Watchdog_CTRL_INTEN_Pos)        /* CMSDK_Watchdog CTRL_INTEN: Int Enable Mask */

/* CMSDK_WATCHDOG INTCLR Register Definitions */
#define CMSDK_Watchdog_INTCLR_Pos             0                                              /* CMSDK_Watchdog INTCLR: Int Clear Position */
#define CMSDK_Watchdog_INTCLR_Msk            (0x1ul << CMSDK_Watchdog_INTCLR_Pos)            /* CMSDK_Watchdog INTCLR: Int Clear Mask */

/* CMSDK_WATCHDOG RAWINTSTAT Register Definitions */
#define CMSDK_Watchdog_RAWINTSTAT_Pos         0                                              /* CMSDK_Watchdog RAWINTSTAT: Raw Int Status Position */
#define CMSDK_Watchdog_RAWINTSTAT_Msk        (0x1ul << CMSDK_Watchdog_RAWINTSTAT_Pos)        /* CMSDK_Watchdog RAWINTSTAT: Raw Int Status Mask */

/* CMSDK_WATCHDOG MASKINTSTAT Register Definitions */
#define CMSDK_Watchdog_MASKINTSTAT_Pos        0                                              /* CMSDK_Watchdog MASKINTSTAT: Mask Int Status Position */
#define CMSDK_Watchdog_MASKINTSTAT_Msk       (0x1ul << CMSDK_Watchdog_MASKINTSTAT_Pos)       /* CMSDK_Watchdog MASKINTSTAT: Mask Int Status Mask */

/* CMSDK_WATCHDOG LOCK Register Definitions */
#define CMSDK_Watchdog_LOCK_Pos               0                                              /* CMSDK_Watchdog LOCK: LOCK Position */
#define CMSDK_Watchdog_LOCK_Msk              (0x1ul << CMSDK_Watchdog_LOCK_Pos)              /* CMSDK_Watchdog LOCK: LOCK Mask */

/* CMSDK_WATCHDOG INTEGTESTEN Register Definitions */
#define CMSDK_Watchdog_INTEGTESTEN_Pos        0                                              /* CMSDK_Watchdog INTEGTESTEN: Integration Test Enable Position */
#define CMSDK_Watchdog_INTEGTESTEN_Msk       (0x1ul << CMSDK_Watchdog_INTEGTESTEN_Pos)       /* CMSDK_Watchdog INTEGTESTEN: Integration Test Enable Mask */

/* CMSDK_WATCHDOG INTEGTESTOUTSET Register Definitions */
#define CMSDK_Watchdog_INTEGTESTOUTSET_Pos    1                                              /* CMSDK_Watchdog INTEGTESTOUTSET: Integration Test Output Set Position */
#define CMSDK_Watchdog_INTEGTESTOUTSET_Msk   (0x1ul << CMSDK_Watchdog_INTEGTESTOUTSET_Pos)   /* CMSDK_Watchdog INTEGTESTOUTSET: Integration Test Output Set Mask */



/* --------------------  End of section using anonymous unions  ------------------- */
#if defined ( __CC_ARM   )
  #pragma pop
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) // armclang
  /* anonymous unions are enabled by default */
  #pragma clang diagnostic pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif




/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

/* Non Secure IoT Kit peripherals                                                                  */
#define CMSDK_COUNTER_BASE      (0x4002F000UL)
#define CMSDK_TIMER0_BASE       (0x40000000UL)
#define CMSDK_TIMER1_BASE       (0x40001000UL)
#define CMSDK_DUALTIMER_BASE    (0x40002000UL)
#define CMSDK_DUALTIMER_1_BASE  (CMSDK_DUALTIMER_BASE)
#define CMSDK_DUALTIMER_2_BASE  (CMSDK_DUALTIMER_BASE + 0x20UL)
#define CMSDK_WATCHDOG_BASE     (0x40081000UL)

#define UART0_BASE              (0x40101000ul)       /* UART 0 Base Address */
#define UART1_BASE              (0x40102000ul)       /* UART 1 Base Address */
#define SPI_BASE                (0x40103000ul)       /* SPI Base Address    */
#define I2C0_BASE               (0x40104000ul)       /* I2C 0 Base Address  */
#define I2C1_BASE               (0x40105000ul)       /* I2C 1 Base Address  */
#define I2S_BASE                (0x40106000ul)       /* I2S Base Address    */
#define PWM0_BASE               (0x40107000ul)       /* PWM 0 Base Address  */
#define RTC_BASE                (0x40108000ul)       /* RTC Base Address    */
#define PVT_BASE                (0x40109000ul)       /* PVT Base Address    */
#define QSPI_BASE               (0x4010A000ul)       /* QSPI Base Address   */
#define TIMER_BASE              (0x4010B000ul)       /* TIMER Base Address  */
#define SCC_BASE                (0x4010C000ul)       /* SCC Base Address    */
#define PWM1_BASE               (0x4010E000ul)       /* PWM 1 Base Address  */
#define PWM2_BASE               (0x4010F000ul)       /* PWM 2 Base Address  */

#define CMSDK_GPIO0_BASE        (0x40110000ul)       /* GPIO 0 Base Address */
#define CMSDK_SYSCTRL_BASE      (0x40116000UL)

/* ================================================================================ */
/* ================          Secure Peripheral memory map          ================ */
/* ================================================================================ */

/* Secure IoT Kit peripherals */
#define SEC_TIMER0_BASE         (0x50000000UL)
#define SEC_TIMER1_BASE         (0x50001000UL)
#define SEC_DUALTIMER_BASE      (0x50002000UL)
#define SEC_DUALTIMER_1_BASE    (SEC_DUALTIMER_BASE)
#define SEC_DUALTIMER_2_BASE    (SEC_DUALTIMER_BASE + 0x20UL)
#define SEC_WATCHDOG_BASE       (0x50081000UL)

#define SEC_UART0_BASE          (0x50101000ul)       /* UART 0 Base Address */
#define SEC_UART1_BASE          (0x50102000ul)       /* UART 1 Base Address */
#define SEC_SPI_BASE            (0x50103000ul)       /* SPI Base Address    */
#define SEC_I2C0_BASE           (0x50104000ul)       /* I2C 0 Base Address  */
#define SEC_I2C1_BASE           (0x50105000ul)       /* I2C 1 Base Address  */
#define SEC_I2S_BASE            (0x50106000ul)       /* I2S Base Address    */
#define SEC_PWM0_BASE           (0x50107000ul)       /* PWM 0 Base Address  */
#define SEC_RTC_BASE            (0x50108000ul)       /* RTC Base Address    */
#define SEC_PVT_BASE            (0x50109000ul)       /* PVT Base Address    */
#define SEC_QSPI_BASE           (0x5010A000ul)       /* QSPI Base Address   */
#define SEC_TIMER_BASE          (0x5010B000ul)       /* TIMER Base Address  */
#define SEC_SCC_BASE            (0x5010C000ul)       /* SCC Base Address    */
#define SEC_PWM1_BASE           (0x5010E000ul)       /* PWM 1 Base Address  */
#define SEC_PWM2_BASE           (0x5010F000ul)       /* PWM 2 Base Address  */
                                    
#define SEC_GPIO0_BASE          (0x50110000ul)       /* GPIO 0 Base Address */
#define SEC_SYSCTRL_BASE        (0x50116000UL)


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define COUNTER                 ((CMSDK_TIMER_TypeDef  *) CMSDK_COUNTER_BASE  )
#define CMSDK_TIMER0            ((CMSDK_TIMER_TypeDef  *) CMSDK_TIMER0_BASE  )
#define CMSDK_TIMER1            ((CMSDK_TIMER_TypeDef  *) CMSDK_TIMER1_BASE  )
#define CMSDK_DUALTIMER         ((CMSDK_DUALTIMER_BOTH_TypeDef  *) CMSDK_DUALTIMER_BASE )
#define CMSDK_DUALTIMER1        ((CMSDK_DUALTIMER_SINGLE_TypeDef  *) CMSDK_DUALTIMER_1_BASE )
#define CMSDK_DUALTIMER2        ((CMSDK_DUALTIMER_SINGLE_TypeDef  *) CMSDK_DUALTIMER_2_BASE )
#define CMSDK_WATCHDOG          ((CMSDK_WATCHDOG_TypeDef  *) CMSDK_WATCHDOG_BASE   )
#define CMSDK_GPIO0             ((CMSDK_GPIO_TypeDef   *) CMSDK_GPIO0_BASE   )
#define CMSDK_SYSCON            ((CMSDK_SYSCON_TypeDef *) CMSDK_SYSCTRL_BASE )

#define SEC_TIMER0              ((CMSDK_TIMER_TypeDef  *) SEC_TIMER0_BASE  )
#define SEC_TIMER1              ((CMSDK_TIMER_TypeDef  *) SEC_TIMER1_BASE  )
#define SEC_DUALTIMER           ((CMSDK_DUALTIMER_BOTH_TypeDef  *) SEC_DUALTIMER_BASE )
#define SEC_DUALTIMER1          ((CMSDK_DUALTIMER_SINGLE_TypeDef  *) SEC_DUALTIMER_1_BASE )
#define SEC_DUALTIMER2          ((CMSDK_DUALTIMER_SINGLE_TypeDef  *) SEC_DUALTIMER_2_BASE )
#define SEC_WATCHDOG            ((CMSDK_WATCHDOG_TypeDef  *) SEC_WATCHDOG_BASE   )
#define SEC_GPIO0               ((CMSDK_GPIO_TypeDef   *) SEC_GPIO0_BASE   )
#define SEC_SYSCON              ((CMSDK_SYSCON_TypeDef *) SEC_SYSCTRL_BASE )

#ifdef __cplusplus
}
#endif

#endif  /* CMSDK_IoT_H */
