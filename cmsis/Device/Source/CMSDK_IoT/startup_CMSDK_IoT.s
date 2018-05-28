;/**************************************************************************//**
; * @file     startup_CMSDK_IoT.s
; * @brief    CMSIS Core Device Startup File for
; *           CMSDK_IoT Device
; * @version  V3.02
; * @date     15. November 2013
; *
; * @note
; *
; ******************************************************************************/
;/* Copyright (c) 2011 - 2013 ARM LIMITED
;
;   All rights reserved.
;   Redistribution and use in source and binary forms, with or without
;   modification, are permitted provided that the following conditions are met:
;   - Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;   - Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the distribution.
;   - Neither the name of ARM nor the names of its contributors may be used
;     to endorse or promote products derived from this software without
;     specific prior written permission.
; *
;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
;   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;   POSSIBILITY OF SUCH DAMAGE.
;   ---------------------------------------------------------------------------*/
;/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00001000

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00004000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     SecureFault_Handler       ; Secure Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; Core IoT Interrupts
                DCD      NONSEC_WATCHDOG_RESET_Handler  ; - 0 Non-Secure Watchdog Reset Handler
                DCD      NONSEC_WATCHDOG_Handler        ; - 1 Non-Secure Watchdog Handler
                DCD      S32K_TIMER_Handler             ; - 2 S32K Timer Handler
                DCD      TIMER0_Handler                 ; - 3 TIMER 0 Handler
                DCD      TIMER1_Handler                 ; - 4 TIMER 1 Handler
                DCD      DUALTIMER_Handler              ; - 5 Dual Timer Handler
                DCD      MHU0_Handler                   ; - 6 Message Handling Unit 0
                DCD      MHU1_Handler                   ; - 7 Message Handling Unit 1
                DCD      0                              ; Reserved - 8
                DCD      MPC_Handler                    ; - 9 MPC Combined (Secure) Handler
                DCD      PPC_Handler                    ; - 10 PPC Combined (Secure) Handler
                DCD      MSC_Handler                    ; - 11 MSC Combined (Secure) Handler
                DCD      BRIDGE_ERROR_Handler           ; - 12 Bridge Error Combined (Secure) Handler
                DCD      CPU0_CACHE_Handler             ; - 13 CPU 0 Instruction Cache Invalidation Handler
                DCD      0                              ; Reserved - 14
                DCD      SYS_PPU_Handler                ; - 15 SYS_PPU Handler
                DCD      0                              ; Reserved - 16
                DCD      0                              ; Reserved - 17
                DCD      0                              ; Reserved - 18
                DCD      0                              ; Reserved - 19
                DCD      0                              ; Reserved - 20
                DCD      0                              ; Reserved - 21
                DCD      0                              ; Reserved - 22
                DCD      0                              ; Reserved - 23
                DCD      0                              ; Reserved - 24
                DCD      0                              ; Reserved - 25
                DCD      0                              ; Reserved - 26
                DCD      0                              ; Reserved - 27
                DCD      0                              ; Reserved - 28
                DCD      0                              ; Reserved - 29
                DCD      0                              ; Reserved - 30
                DCD      0                              ; Reserved - 31
                ; External Interrupts
                DCD       EXT_Handler             ; 32 Musca Handler
                DCD       GPTIMER_Handler         ; 33 General Purpose Timer Handler
                DCD       I2C0_Handler            ; 34 I2C 0 Handler
                DCD       I2C1_Handler            ; 35 I2C 1 Handler
                DCD       I2S_Handler             ; 36 I2S Handler
                DCD       SPI_Handler             ; 37 SPI Handler
                DCD       QSPI_Handler            ; 38 QSPI Handler
                DCD       UARTRX0_Handler         ; 39 UART 0 RX FIFO Handler
                DCD       UARTTX0_Handler         ; 40 UART 0 TX FIFO Handler
                DCD       UARTRT0_Handler         ; 41 UART 0 RX Timeout Handler
                DCD       UARTMS0_Handler         ; 42 UART 0 Modem Status Handler
                DCD       UARTER0_Handler         ; 43 UART 0 Error Handler
                DCD       UART0_Handler           ; 44 UART 0 Combined Handler
                DCD       UARTRX1_Handler         ; 45 UART 1 RX FIFO Handler
                DCD       UARTTX1_Handler         ; 46 UART 1 TX FIFO Handler
                DCD       UARTRT1_Handler         ; 47 UART 1 RX Timeout Handler
                DCD       UARTMS1_Handler         ; 48 UART 1 Modem Status Handler
                DCD       UARTER1_Handler         ; 49 UART 1 Error Handler
                DCD       UART1_Handler           ; 50 UART 1 Combined Handler
                DCD       GPIO0_0_Handler         ; 51 GPIO0_0 Handler
                DCD       GPIO0_1_Handler         ; 52 GPIO0_1 Handler
                DCD       GPIO0_2_Handler         ; 53 GPIO0_2 Handler
                DCD       GPIO0_3_Handler         ; 54 GPIO0_3 Handler
                DCD       GPIO0_4_Handler         ; 55 GPIO0_4 Handler
                DCD       GPIO0_5_Handler         ; 56 GPIO0_5 Handler
                DCD       GPIO0_6_Handler         ; 57 GPIO0_6 Handler
                DCD       GPIO0_7_Handler         ; 58 GPIO0_7 Handler
                DCD       GPIO0_8_Handler         ; 59 GPIO0_8 Handler
                DCD       GPIO0_9_Handler         ; 60 GPIO0_9 Handler
                DCD       GPIO0_10_Handler        ; 61 GPIO0_10 Handler
                DCD       GPIO0_11_Handler        ; 62 GPIO0_11 Handler
                DCD       GPIO0_12_Handler        ; 63 GPIO0_12 Handler
                DCD       GPIO0_13_Handler        ; 64 GPIO0_13 Handler
                DCD       GPIO0_14_Handler        ; 65 GPIO0_14 Handler
                DCD       GPIO0_15_Handler        ; 66 GPIO0_15 Handler
                DCD       GPIO0_Handler           ; 67 GPIO 0 Handler
                DCD       PVT_Handler             ; 68 PVT Sensor Handler
                DCD       WAHOO_Handler           ; 69 Wahoo Handler
                DCD       PWM0_Handler            ; 70 PWM 0 Handler
                DCD       RTC_Handler             ; 71 RTC Handler
                DCD       GPTIMER0_Handler        ; 72 General Purpose Timer 0 Handler
                DCD       GPTIMER1_Handler        ; 73 General Purpose Timer 1 Handler
                DCD       PWM1_Handler            ; 74 PWM 1 Handler
                DCD       PWM2_Handler            ; 75 PWM 2 Handler
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

;                B       .

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP

SecureFault_Handler\
                PROC
                EXPORT  SecureFault_Handler       [WEAK]
                B       .
                ENDP

SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC
; Core IoT Interrupts
                EXPORT NONSEC_WATCHDOG_RESET_Handler   [WEAK] ; - 0 Non-Secure Watchdog Reset Handler
                EXPORT NONSEC_WATCHDOG_Handler         [WEAK] ; - 1 Non-Secure Watchdog Handler
                EXPORT S32K_TIMER_Handler              [WEAK] ; - 2 S32K Timer Handler
                EXPORT TIMER0_Handler                  [WEAK] ; - 3 TIMER 0 Handler
                EXPORT TIMER1_Handler                  [WEAK] ; - 4 TIMER 1 Handler
                EXPORT DUALTIMER_Handler               [WEAK] ; - 5 Dual Timer Handler
                EXPORT MHU0_Handler                    [WEAK] ; - 6 Message Handling Unit 0
                EXPORT MHU1_Handler                    [WEAK] ; - 7 Message Handling Unit 1
                EXPORT MPC_Handler                     [WEAK] ; - 9 MPC Combined (Secure) Handler
                EXPORT PPC_Handler                     [WEAK] ; - 10 PPC Combined (Secure) Handler
                EXPORT MSC_Handler                     [WEAK] ; - 11 MSC Combined (Secure) Handler
                EXPORT BRIDGE_ERROR_Handler            [WEAK] ; - 12 Bridge Error Combined (Secure) Handler
                EXPORT CPU0_CACHE_Handler              [WEAK] ; - 13 CPU 0 Instruction Cache Invalidation Handler
                EXPORT SYS_PPU_Handler                 [WEAK] ; - 15 SYS_PPU Handler
; External Interrupts
                EXPORT EXT_Handler                 [WEAK] ; 32 Musca Handler
                EXPORT GPTIMER_Handler             [WEAK] ; 33 General Purpose Timer Handler
                EXPORT I2C0_Handler                [WEAK] ; 34 I2C 0 Handler
                EXPORT I2C1_Handler                [WEAK] ; 35 I2C 1 Handler
                EXPORT I2S_Handler                 [WEAK] ; 36 I2S Handler
                EXPORT SPI_Handler                 [WEAK] ; 37 SPI Handler
                EXPORT QSPI_Handler                [WEAK] ; 38 QSPI Handler
                EXPORT UARTRX0_Handler             [WEAK] ; 39 UART 0 RX FIFO Handler
                EXPORT UARTTX0_Handler             [WEAK] ; 40 UART 0 TX FIFO Handler
                EXPORT UARTRT0_Handler             [WEAK] ; 41 UART 0 RX Timeout Handler
                EXPORT UARTMS0_Handler             [WEAK] ; 42 UART 0 Modem Status Handler
                EXPORT UARTER0_Handler             [WEAK] ; 43 UART 0 Error Handler
                EXPORT UART0_Handler               [WEAK] ; 44 UART 0 Combined Handler
                EXPORT UARTRX1_Handler             [WEAK] ; 45 UART 1 RX FIFO Handler
                EXPORT UARTTX1_Handler             [WEAK] ; 46 UART 1 TX FIFO Handler
                EXPORT UARTRT1_Handler             [WEAK] ; 47 UART 1 RX Timeout Handler
                EXPORT UARTMS1_Handler             [WEAK] ; 48 UART 1 Modem Status Handler
                EXPORT UARTER1_Handler             [WEAK] ; 49 UART 1 Error Handler
                EXPORT UART1_Handler               [WEAK] ; 50 UART 1 Combined Handler
                EXPORT GPIO0_0_Handler             [WEAK] ; 51 GPIO0_0 Handler
                EXPORT GPIO0_1_Handler             [WEAK] ; 52 GPIO0_1 Handler
                EXPORT GPIO0_2_Handler             [WEAK] ; 53 GPIO0_2 Handler
                EXPORT GPIO0_3_Handler             [WEAK] ; 54 GPIO0_3 Handler
                EXPORT GPIO0_4_Handler             [WEAK] ; 55 GPIO0_4 Handler
                EXPORT GPIO0_5_Handler             [WEAK] ; 56 GPIO0_5 Handler
                EXPORT GPIO0_6_Handler             [WEAK] ; 57 GPIO0_6 Handler
                EXPORT GPIO0_7_Handler             [WEAK] ; 58 GPIO0_7 Handler
                EXPORT GPIO0_8_Handler             [WEAK] ; 59 GPIO0_8 Handler
                EXPORT GPIO0_9_Handler             [WEAK] ; 60 GPIO0_9 Handler
                EXPORT GPIO0_10_Handler            [WEAK] ; 61 GPIO0_10 Handler
                EXPORT GPIO0_11_Handler            [WEAK] ; 62 GPIO0_11 Handler
                EXPORT GPIO0_12_Handler            [WEAK] ; 63 GPIO0_12 Handler
                EXPORT GPIO0_13_Handler            [WEAK] ; 64 GPIO0_13 Handler
                EXPORT GPIO0_14_Handler            [WEAK] ; 65 GPIO0_14 Handler
                EXPORT GPIO0_15_Handler            [WEAK] ; 66 GPIO0_15 Handler
                EXPORT GPIO0_Handler               [WEAK] ; 67 GPIO 0 Combined Handler
                EXPORT PVT_Handler                 [WEAK] ; 68 PVT Sensor Handler
                EXPORT WAHOO_Handler               [WEAK] ; 69 Wahoo Handler
                EXPORT PWM0_Handler                [WEAK] ; 70 PWM 0 Handler
                EXPORT RTC_Handler                 [WEAK] ; 71 RTC Handler
                EXPORT GPTIMER0_Handler            [WEAK] ; 72 General Purpose Timer 0 Handler
                EXPORT GPTIMER1_Handler            [WEAK] ; 73 General Purpose Timer 1 Handler
                EXPORT PWM1_Handler                [WEAK] ; 74 PWM 1 Interrupt Handler
                EXPORT PWM2_Handler                [WEAK] ; 75 PWM 2 Interrupt Handler

; Core IoT Interrupts
NONSEC_WATCHDOG_RESET_Handler  ; 0 Non-Secure Watchdog Reset Handler
NONSEC_WATCHDOG_Handler        ; 1 Non-Secure Watchdog Handler
S32K_TIMER_Handler             ; 2 S32K Timer Handler
TIMER0_Handler                 ; 3 TIMER 0 Handler
TIMER1_Handler                 ; 4 TIMER 1 Handler
DUALTIMER_Handler              ; 5 Dual Timer Handler
MHU0_Handler                   ; 6 Message Handling Unit 0
MHU1_Handler                   ; 7 Message Handling Unit 1
MPC_Handler                    ; 9 MPC Combined (Secure) Handler
PPC_Handler                    ; 10 PPC Combined (Secure) Handler
MSC_Handler                    ; 11 MSC Combined (Secure) Handler
BRIDGE_ERROR_Handler           ; 12 Bridge Error Combined (Secure) Handler
CPU0_CACHE_Handler             ; 13 CPU 0 Instruction Cache Invalidation Handler
SYS_PPU_Handler                ; 15 SYS_PPU Handler
; External Interrupts
EXT_Handler             ; 32 Musca Handler
GPTIMER_Handler         ; 33 General Purpose Timer Handler
I2C0_Handler            ; 34 I2C 0 Handler
I2C1_Handler            ; 35 I2C 1 Handler
I2S_Handler             ; 36 I2S Handler
SPI_Handler             ; 37 SPI Handler
QSPI_Handler            ; 38 QSPI Handler
UARTRX0_Handler         ; 39 UART 0 RX FIFO Handler
UARTTX0_Handler         ; 40 UART 0 TX FIFO Handler
UARTRT0_Handler         ; 41 UART 0 RX Timeout Handler
UARTMS0_Handler         ; 42 UART 0 Modem Status Handler
UARTER0_Handler         ; 43 UART 0 Error Handler
UART0_Handler           ; 44 UART 0 Combined Handler
UARTRX1_Handler         ; 45 UART 1 RX FIFO Handler
UARTTX1_Handler         ; 46 UART 1 TX FIFO Handler
UARTRT1_Handler         ; 47 UART 1 RX Timeout Handler
UARTMS1_Handler         ; 48 UART 1 Modem Status Handler
UARTER1_Handler         ; 49 UART 1 Error Handler
UART1_Handler           ; 50 UART 1 Combined Handler
GPIO0_0_Handler         ; 51 GPIO0_0 Handler
GPIO0_1_Handler         ; 52 GPIO0_1 Handler
GPIO0_2_Handler         ; 53 GPIO0_2 Handler
GPIO0_3_Handler         ; 54 GPIO0_3 Handler
GPIO0_4_Handler         ; 55 GPIO0_4 Handler
GPIO0_5_Handler         ; 56 GPIO0_5 Handler
GPIO0_6_Handler         ; 57 GPIO0_6 Handler
GPIO0_7_Handler         ; 58 GPIO0_7 Handler
GPIO0_8_Handler         ; 59 GPIO0_8 Handler
GPIO0_9_Handler         ; 60 GPIO0_9 Handler
GPIO0_10_Handler        ; 61 GPIO0_10 Handler
GPIO0_11_Handler        ; 62 GPIO0_11 Handler
GPIO0_12_Handler        ; 63 GPIO0_12 Handler
GPIO0_13_Handler        ; 64 GPIO0_13 Handler
GPIO0_14_Handler        ; 65 GPIO0_14 Handler
GPIO0_15_Handler        ; 66 GPIO0_15 Handler
GPIO0_Handler           ; 67 GPIO 0 Handler
PVT_Handler             ; 68 PVT Sensor Handler
WAHOO_Handler           ; 69 Wahoo Handler
PWM0_Handler            ; 70 PWM 0 Handler
RTC_Handler             ; 71 RTC Handler
GPTIMER0_Handler        ; 72 General Purpose Timer 0 Handler
GPTIMER1_Handler        ; 73 General Purpose Timer 1 Handler
PWM1_Handler            ; 74 PWM 1 Handler
PWM2_Handler            ; 75 PWM 2 Handler
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
