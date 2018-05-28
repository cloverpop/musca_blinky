/*
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited.
 *
 *            (C) COPYRIGHT 2010-2012 ARM Limited.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited.
 *
 *-----------------------------------------------------------------------------
 */


/******************************************************************************/
/* Retarget functions for ARM DS-5 Professional / Keil MDK                                 */
/******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <rt_misc.h>
#include <rt_sys.h>
#include <time.h>

#include "uart_stdout.h"

//asm (" .global __use_no_semihosting_swi\n");

/* Standard IO device handles. */
#define STDIN   0x8001
#define STDOUT  0x8002
#define STDERR  0x8003

/* Standard IO device name defines. */
const char __stdin_name[]  = "STDIN";
const char __stdout_name[] = "STDOUT";
const char __stderr_name[] = "STDERR";

//struct __FILE { int handle; /* Add whatever you need here */ };
//FILE __stdout;
//FILE __stdin;


int fputc(int ch, FILE *f) {
  return (UartPutc(ch));
}

int fgetc(FILE *f) {
  return (UartPutc(UartGetc()));
}

int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}

void _ttywrch(int ch) {
  UartPutc (ch);
}

/*--------------------------- _sys_open --------------------------------------*/

FILEHANDLE _sys_open (const char *name, int openmode) {
   /* Register standard Input Output devices. */
   if (strcmp(name, "STDIN") == 0) {
      return (STDIN);
   }
   if (strcmp(name, "STDOUT") == 0) {
      return (STDOUT);
   }
   if (strcmp(name, "STDERR") == 0) {
      return (STDERR);
   }
   return (-1);
   //return (__sys_open (name, openmode));
}

/*--------------------------- _sys_close -------------------------------------*/

int _sys_close (FILEHANDLE fh) {
   if (fh > 0x8000) {
      return (0);
   }
   return (-1);
   //return (__sys_close (fh));
}

/*--------------------------- _sys_write -------------------------------------*/

int _sys_write (FILEHANDLE fh, const unsigned char  *buf, unsigned int len, int mode) {
   if (fh == STDOUT) {
      /* Standard Output device. */
      for (  ; len; len--) {
    	  UartPutc (*buf++);
      }
      return (0);
   }

   if (fh > 0x8000) {
      return (-1);
   }
   return (-1);
   //return (__sys_write (fh, buf, len));
}

/*--------------------------- _sys_read --------------------------------------*/

int _sys_read (FILEHANDLE fh, unsigned char *buf, unsigned int len, int mode) {
   if (fh == STDIN) {
      /* Standard Input device. */
      for (  ; len; len--) {
        *buf++ = UartGetc ();
      }
      return (0);
   }

   if (fh > 0x8000) {
      return (-1);
   }
   return (-1);
   //   return (__sys_read (fh, buf, len));
}

/*--------------------------- _sys_istty -------------------------------------*/

int _sys_istty (FILEHANDLE fh) {
   if (fh > 0x8000) {
      return (1);
   }
   return (0);
}

/*--------------------------- _sys_seek --------------------------------------*/

int _sys_seek (FILEHANDLE fh, long pos) {
   if (fh > 0x8000) {
      return (-1);
   }
   return (-1);
   //return (__sys_seek (fh, pos));
}

/*--------------------------- _sys_ensure ------------------------------------*/

int _sys_ensure (FILEHANDLE fh) {
   if (fh > 0x8000) {
      return (-1);
   }
   return (-1);
   //return (__sys_ensure (fh));
}

/*--------------------------- _sys_flen --------------------------------------*/

long _sys_flen (FILEHANDLE fh) {
   if (fh > 0x8000) {
      return (0);
   }
   return (-1);
   //return (__sys_flen (fh));
}

int _sys_tmpnam (char *name, int sig, unsigned maxlen) {
   return (1);
}

char *_sys_command_string (char *cmd, int len) {
   return (cmd);
}

void _sys_exit(int return_code) {
label:  goto label;  /* endless loop */
}

int  system(const char * cmd)
{
	return (0);
}

/*--------------------------- clock --------------------------------------*/

clock_t clock (void)
{
//	clock_t * count =(clock_t *)0x1C000018;
//	return *count/10;
    return 0;
}

