#include "ex3a.h"
/*
Podpunkt (a): jeden program - ustawia obsługę sygnału na 3 sposoby zgodnie z opcją podaną jako argument wywołania programu, a następnie czeka na sygnał (funkcja pause()); numer sygnału przekazywać jako argument wywołania programu; niech proces wypisze na ekranie swój PID, a funkcja do własnej obsługi sygnału jego numer i nazwę (można wstawić krótki sleep).

//zrobiłem
- funkcje do własnej obsługi sygnału która wypisuje numer sygnału i jego nazwe
- 

Napisac program do obslugi sygnalow z mozliwosciami: 
(1) wykonania operacji domyslnej, 
(2) ignorowania oraz (3) przechwycenia i wlasnej obslugi sygnalu.
Do oczekiwania na sygnal uzyc funkcji pause. Uruchomic program i wysylac do niego sygnaly
przy pomocy sekwencji klawiszy oraz przy pomocy polecenia kill z poziomu powloki

Programy kompilować/linkować z opcjami: -Wall -std=c99 -pedantic

UWAGA: W nowych wersjach Linuksa użycie powyższych opcji kompilatora skutkuje ostrzeżeniem, że funkcja kill() jest niezadeklarowana - aby tego uniknąć, należy na początku pliku użyć makra preprocesora: #define _POSIX_C_SOURCE 200112L
Aby uniknąć podobnych ostrzeżeń dla funkcji getpgid() trzeba dodać makro: #define _XOPEN_SOURCE 500
Z kolei dla funkcji strsignal() należy dodać makro: #define _GNU_SOURCE
*/

void au(int sig);
void signalManager(char *argv[]);

void signalManager(char *argv[]){

	char *controlNames[] = {"SIG_DFL","SIG_IGN","SIG_INTERCEPT"};

	if(strcmp(argv[2],controlNames[INTERCEPT])==0){
		if(signal(SIGINT,my_signal_handler) == SIG_ERR){
			perror("signal-f error!\n");
			exit(EXIT_FAILURE);
		}
	}

	if(strcmp(argv[2],controlNames[DEFAULT])==0){
		if(signal(SIGINT,SIG_DFL) == SIG_ERR){
			perror("signal-f error!\n");
			exit(EXIT_FAILURE);
		}
	}
	if(strcmp(argv[2],controlNames[IGNORE])==0){
		if(signal(SIGINT,SIG_IGN) == SIG_ERR){
			perror("signal-f error!\n");
			exit(EXIT_FAILURE);
		}
	}
}

void my_signal_handler(int sig){
	printf("\n%d - process number, %s - process name\n",sig,strsignal(sig));
}

void au(int sig){
	printf("\nAU, got stopped!\n");
}

int main(int argc,char* argv[]){ 
	signalManager(argv);
	while(1){
		;
	}
	return 0;
}



