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
 * File:     uart_stdout.h
 * Release:  Version 2.0
 * ----------------------------------------------------------------
 */

#ifndef _UART_STDOUT_H_
#define _UART_STDOUT_H_

#define HW_REG(base,offset) *((volatile unsigned int *)((base) + (offset)))

#define UART_CLOCK          32000000
#define UART_BASE           0x40102000  // UART 1
#define UART_BAUD			115200

/* The functions are implemented in uart_stdout.c */

extern void UartStdOutInit(void);
extern unsigned char UartPutc(unsigned char my_ch);
extern unsigned char UartGetc(void);
extern unsigned int GetLine (char *lp, unsigned int len);
extern unsigned int ConsoleTerminate(void);

#endif
