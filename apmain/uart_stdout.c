/*
 * Copyright:
 * ----------------------------------------------------------------
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 *   (C) COPYRIGHT 2014 ARM Limited
 *       ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 * ----------------------------------------------------------------
 * File:     uart_stdout.c
 * Release:  Version 2.0
 * ----------------------------------------------------------------
 *
 */

#include <stdint.h>
#include <stdio.h>

#include "CMSDK_IoT.h"

#include "uart_private.h"
#include "uart_stdout.h"

void UartStdOutInit(void)
{
    uintptr_t base = UART_BASE;
    uint32_t ref_clk = SystemCoreClock;
    uint32_t baud_rate = UART_BAUD;
    uint32_t temp;
    uint32_t divider;
    uint32_t remainder;
    uint32_t fraction;

    /*
    ** First, disable everything.
    */
    HW_REG(base, UART_PL011_CR) = 0;

    /*
    ** Set baud rate
    **
    ** IBRD = UART_CLK / (16 * BPS)
    ** FBRD = ROUND((64 * MOD(UART_CLK,(16 * BPS))) / (16 * BPS))
    */
    temp      = 16 * baud_rate;
    ref_clk   = SystemCoreClock;
    divider   = ref_clk / temp;
    remainder = ref_clk % temp;
    temp      = (8 * remainder) / baud_rate;
    fraction  = (temp >> 1) + (temp & 1);

    HW_REG(base, UART_PL011_IBRD) = divider;
    HW_REG(base, UART_PL011_FBRD) = fraction;

    /*
    ** ----------------------------------------------
    ** NOTE: MUST BE WRITTEN LAST (AFTER IBRD & FBRD)
    ** ----------------------------------------------
    **
    ** Set the UART to be 8 bits, 1 stop bit, no parity, fifo enabled.
    */
    HW_REG(base, UART_PL011_LCRH) =
        (UART_PL011_LCRH_WLEN_8 | UART_PL011_LCRH_FEN);

    /*
    ** Finally, enable the UART
    */
    HW_REG(base, UART_PL011_CR) =
        (UART_PL011_CR_UARTEN | UART_PL011_CR_TXE | UART_PL011_CR_RXE);

    return;
}

// Output a character
unsigned char UartPutc(unsigned char c)
{
    unsigned int base = UART_BASE;

    while (HW_REG(base, UART_PL01x_FR) & UART_PL01x_FR_TXFF);

    if (c == '\n')
    {
        HW_REG(base, UART_PL01x_DR) = '\r';
        while (HW_REG(base, UART_PL01x_FR) & UART_PL01x_FR_TXFF);
    }

    HW_REG(base, UART_PL01x_DR) = c;

    return c;
}

// Get a character
unsigned char UartGetc(void)
{
    unsigned int base = UART_BASE;
	unsigned char my_ch;

	while (HW_REG(base, UART_PL01x_FR) & UART_PL01x_FR_RXFE);

	my_ch = (HW_REG(base, UART_PL01x_DR) & 0xFF);

	//Convert CR to LF
	if(my_ch == '\r')
	    my_ch = '\n';

	return (my_ch);
}

// Get line from terminal
unsigned int GetLine (char *lp, unsigned int len)
{
   unsigned int cnt = 0;
   char c;

    do {
        c = UartGetc ();
        switch (c) {
            case CNTLQ:                       /* ignore Control S/Q             */
            case CNTLS:
                break;
            case BACKSPACE:
            case DEL:
                if (cnt == 0) {
                    break;
                }
                cnt--;                         /* decrement count                */
                lp--;                          /* and line pointer               */
                UartPutc (0x08);                /* echo backspace                 */
                UartPutc (' ');
                UartPutc (0x08);
                fflush (stdout);
                break;
            case ESC:
            case 0:
            	*lp = 0;                       /* ESC - stop editing line        */
            	return (0);
            case CR:                           /* CR - done, stop editing line   */
            	*lp = c;
            	lp++;                          /* increment line pointer         */
            	cnt++;                         /* and count                      */
            	c = LF;
            default:
            	UartPutc (*lp = c);             /* echo and store character       */
            	fflush (stdout);
            	lp++;                          /* increment line pointer         */
                cnt++;                         /* and count                      */
            	break;
        }
    } while (cnt < len - 2  &&  c != LF);        /* check limit and CR             */
    *lp = 0;                                   /* mark end of string             */
    return (1);
}

// Routine to check x typed on console
unsigned int ConsoleTerminate(void)
{
    char temp;
    
    if (!(HW_REG(UART_BASE, UART_PL01x_FR) & UART_PL01x_FR_RXFE)) // If Receive Holding register not empty
    {
        temp = (HW_REG(UART_BASE, UART_PL01x_DR) & 0xFF);
        if((temp == 'x') || (temp == 'X'))
            return 1;
    }
    return 0;
}
