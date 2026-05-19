/*
EXERCISE: Signals
Signals are a way for the operating system to notify a process that an event has
occurred. For example, if a process tries to divide by zero, the operating
system will send a SIGFPE signal to the process. If a process tries to access
memory that it is not allowed to access, the operating system will send a
SIGSEGV signal to the process.
In this exercise, you will write a program that handles the SIGFPE and SIGSEGV
signals.
The program will read commands from the standard input. The commands will be in
the following format:
  lisää a b
  tulosta i
  tulosta
*/

#ifndef SIGNAALIT_H
#define SIGNAALIT_H

#include <setjmp.h>

extern jmp_buf paluuTila;

void hoidaSIGFPE(int s);
void hoidaSIGSEGV(int s);

#endif
