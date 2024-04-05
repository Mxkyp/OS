#include "ex3a.h"
/*
Podpunkt (a): jeden program - ustawia obsługę sygnału na 3 sposoby zgodnie z opcją podaną jako argument wywołania programu, a następnie czeka na sygnał (funkcja pause()); numer sygnału przekazywać jako argument wywołania programu; niech proces wypisze na ekranie swój PID, a funkcja do własnej obsługi sygnału jego numer i nazwę (można wstawić krótki sleep).

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
void alarmSignal(int sig){
	printf("\nALARAM HALLALAL OOOBPA\n");
}

void alarmSignal(int sig);

int main(int argc,char *argv[2]){ 

	signal(*argv[0],*argv[1]);
	kill(0,*argv[0]);
	printf("\n%s",strsignal(SIGKILL));
	printf("\n22 club\n");

	return 0;
}

