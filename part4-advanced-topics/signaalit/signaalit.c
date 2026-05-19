#include "signaalit.h"

#include <signal.h>

jmp_buf paluuTila;

/*
This fuction is called when the SIGFPE signal is received. It will longjmp back
to the main function, where the program will continue execution from the point
where setjmp was called. The signal handler will also re-register itself as the
handler for the signal, so that it will be called again if the signal is
received again.
*/
void hoidaSIGFPE(int s) {
  (void)s;
  signal(SIGFPE, hoidaSIGFPE);
  longjmp(paluuTila, SIGFPE);
}

/*
This fuction is called when the SIGSEGV signal is received. It will longjmp back
to the main function, where the program will continue execution from the point
where setjmp was called. The signal handler will also re-register itself as the
handler for the signal, so that it will be called again if the signal is
received again.
*/
void hoidaSIGSEGV(int s) {
  (void)s;
  signal(SIGSEGV, hoidaSIGSEGV);
  longjmp(paluuTila, SIGSEGV);
}
