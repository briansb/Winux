#ifndef SUPPORT_H
#define SUPPORT_H

#if defined(_WIN32) || defined(_WIN64)
	// watch for these being defined elsewhere
	#include <windows.h>			/* needed for WINAPI, BOOL, etc */
#elif defined(__linux__)
	// watch for these being defined elsewhere
	#include <unistd.h>
#endif

#include <stdio.h>			/* needed for printf() */
#include <signal.h>			/* keyboard control handler */
#include <time.h>			/* time */

extern bool keep_running;

// OS-dependent routines
void winuxSetKeyboardHandler();
int winuxGetPID();

#endif
