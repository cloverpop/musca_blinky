/*!
 * \file    uart_private.h
 * \brief   UART function prototypes and defintions
 * \date    Copyright (c) 2009 ARM Limited. All rights reserved.
 *
 *  Provides definitions for the Primecell UARTS (PL010 and PL011)
 */

/*
 * Revision $Revision: 39162 $
 * Checkin $Date: 2010-07-16 10:58:51 +0100 (Fri, 16 Jul 2010) $
 */

#ifndef __UART_H
#define __UART_H

#define CNTLQ       0x11
#define CNTLS       0x13
#define DEL         0x7F
#define BACKSPACE   0x08
#define CR          0x0D
#define LF          0x0A
#define ESC         0x1B

/* 
** --------------------------------
** PrimeCell UART's (PL010 & PL011) 
** --------------------------------
**
** Definitions common to both PL010 & PL011
*/
#define UART_PL01x_DR                   0x00	 /*  Data read or written from the interface. */
#define UART_PL01x_RSR                  0x04	 /*  Receive status register (Read). */
#define UART_PL01x_ECR                  0x04	 /*  Error clear register (Write). */
#define UART_PL01x_FR                   0x18	 /*  Flag register (Read only). */

#define UART_PL01x_RSR_OE               0x08
#define UART_PL01x_RSR_BE               0x04
#define UART_PL01x_RSR_PE               0x02
#define UART_PL01x_RSR_FE               0x01

#define UART_PL01x_FR_TXFE              0x80
#define UART_PL01x_FR_RXFF              0x40
#define UART_PL01x_FR_TXFF              0x20
#define UART_PL01x_FR_RXFE              0x10
#define UART_PL01x_FR_BUSY              0x08
#define UART_PL01x_FR_TMSK              (UART_PL01x_FR_TXFF + UART_PL01x_FR_BUSY)

/* 
** PL010 definitions
*/
#define UART_PL010_LCRH                 0x08	 /*  Line control register, high byte. */
#define UART_PL010_LCRM                 0x0C	 /*  Line control register, middle byte. */
#define UART_PL010_LCRL                 0x10	 /*  Line control register, low byte. */
#define UART_PL010_CR                   0x14	 /*  Control register. */
#define UART_PL010_IIR                  0x1C	 /*  Interrupt identification register (Read). */
#define UART_PL010_ICR                  0x1C	 /*  Interrupt clear register (Write). */
#define UART_PL010_ILPR                 0x20	 /*  IrDA low power counter register. */
 
#define UART_PL010_CR_LPE               (1 << 7)
#define UART_PL010_CR_RTIE              (1 << 6)
#define UART_PL010_CR_TIE               (1 << 5)
#define UART_PL010_CR_RIE               (1 << 4)
#define UART_PL010_CR_MSIE              (1 << 3)
#define UART_PL010_CR_IIRLP             (1 << 2)
#define UART_PL010_CR_SIREN             (1 << 1)
#define UART_PL010_CR_UARTEN            (1 << 0)
 
#define UART_PL010_LCRH_WLEN_8          (3 << 5)
#define UART_PL010_LCRH_WLEN_7          (2 << 5)
#define UART_PL010_LCRH_WLEN_6          (1 << 5)
#define UART_PL010_LCRH_WLEN_5          (0 << 5)
#define UART_PL010_LCRH_FEN             (1 << 4)
#define UART_PL010_LCRH_STP2            (1 << 3)
#define UART_PL010_LCRH_EPS             (1 << 2)
#define UART_PL010_LCRH_PEN             (1 << 1)
#define UART_PL010_LCRH_BRK             (1 << 0)

/* 
** PL011 definitions
*/
#define UART_PL011_IBRD                 0x24
#define UART_PL011_FBRD                 0x28
#define UART_PL011_LCRH                 0x2C
#define UART_PL011_CR                   0x30
#define UART_PL011_IMSC                 0x38
#define UART_PL011_PERIPH_ID0           0xFE0
 
#define UART_PL011_LCRH_SPS             (1 << 7)
#define UART_PL011_LCRH_WLEN_8          (3 << 5)
#define UART_PL011_LCRH_WLEN_7          (2 << 5)
#define UART_PL011_LCRH_WLEN_6          (1 << 5)
#define UART_PL011_LCRH_WLEN_5          (0 << 5)
#define UART_PL011_LCRH_FEN             (1 << 4)
#define UART_PL011_LCRH_STP2            (1 << 3)
#define UART_PL011_LCRH_EPS             (1 << 2)
#define UART_PL011_LCRH_PEN             (1 << 1)
#define UART_PL011_LCRH_BRK             (1 << 0)

#define UART_PL011_CR_CTSEN             (1 << 15)
#define UART_PL011_CR_RTSEN             (1 << 14)
#define UART_PL011_CR_OUT2              (1 << 13)
#define UART_PL011_CR_OUT1              (1 << 12)
#define UART_PL011_CR_RTS               (1 << 11)
#define UART_PL011_CR_DTR               (1 << 10)
#define UART_PL011_CR_RXE               (1 << 9)
#define UART_PL011_CR_TXE               (1 << 8)
#define UART_PL011_CR_LPE               (1 << 7)
#define UART_PL011_CR_IIRLP             (1 << 2)
#define UART_PL011_CR_SIREN             (1 << 1)
#define UART_PL011_CR_UARTEN            (1 << 0)

#define UART_PL011_IMSC_OEIM            (1 << 10)
#define UART_PL011_IMSC_BEIM            (1 << 9)
#define UART_PL011_IMSC_PEIM            (1 << 8)
#define UART_PL011_IMSC_FEIM            (1 << 7)
#define UART_PL011_IMSC_RTIM            (1 << 6)
#define UART_PL011_IMSC_TXIM            (1 << 5)
#define UART_PL011_IMSC_RXIM            (1 << 4)
#define UART_PL011_IMSC_DSRMIM          (1 << 3)
#define UART_PL011_IMSC_DCDMIM          (1 << 2)
#define UART_PL011_IMSC_CTSMIM          (1 << 1)
#define UART_PL011_IMSC_RIMIM           (1 << 0)


#endif

// end of file uart_private.h
