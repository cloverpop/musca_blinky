/*
 * Copyright:
 * ----------------------------------------------------------------
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 *   (C) COPYRIGHT 2017 ARM Limited
 *       ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 * ----------------------------------------------------------------
 * File:     main.c
 * Release:  Version 2.0
 * ----------------------------------------------------------------
 *
 */

/*
 * --------Included Headers--------
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "CMSDK_IoT.h"                       // device specific header file
#include "CMSDK_driver.h"
#include "common.h"
#include "uart_stdout.h"

#define LED_R       0x04                     // LED RED (PA2)
#define LED_G       0x08                     // LED GREEN (PA3)
#define LED_B       0x10                     // LED BLUE (PA4)

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
__ASM(" .global __ARM_use_no_argv\n");
#endif

// Global
CMSDK_GPIO_TypeDef* GPIO;                    // GPIO address


/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void)
{
    unsigned int datal, datah, din, loop;

    // UART init
    UartStdOutInit();

    // Clear interrupts
    NVIC_ClearAllPendingIRQ();

    // Set GPIO port address
    GPIO = CMSDK_GPIO0;
    
    // Set GPIO pin directions
    CMSDK_gpio_SetOutEnable(GPIO, LED_R);
    CMSDK_gpio_SetOutEnable(GPIO, LED_G);
    CMSDK_gpio_SetOutEnable(GPIO, LED_B);
    
    // Display the message
    printf ("\nMusca-A1 Cordio QSPI blinky v1.0\n");
    printf ("Running...\n");

    // LEDs OFF
    GPIO->DATAOUT |= LED_R;
    GPIO->DATAOUT |= LED_G;
    GPIO->DATAOUT |= LED_B;

    // Idle loop
    do
    {
        GPIO->DATAOUT &= ~LED_G;
        GPIO->DATAOUT |= LED_B;
        apSleep(5);
        GPIO->DATAOUT |= LED_G;
        GPIO->DATAOUT &= ~LED_B;
        apSleep(5);
    } while (1);

    return TRUE;
}
