#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define DEFAULT 0	//3 definitions used to 
#define IGNORE 1
#define INTERCEPT 2


//function prototypes
void my_signal_handler(int sig);
void alarmSignal(int sig);


