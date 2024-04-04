#include "cw1.h"
#include "functions.h"

//
// a simple program that displays a process tree (showing respectivley the PID,PPID,GID of each process) with 3 levels.
// written by: Mikołaj Pawłoś
//

int main(int argc, char*argv[]){
	int processID = 0;
	FILE* ptr;

	forkIdWriter(argc,argv); //b)
	return 0;
}


