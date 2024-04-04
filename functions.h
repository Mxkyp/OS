#include "cw1.h"


// function for exercise nr 2 
void forkIdWriter(int argc,char *argv[]){ 
	int controler = 2,processID = 0; // control variables	


	for(int i=0;i<3;i++){ // a for loop used to invoke fork 3 times
		controler = fork(); // fork
		if(processID==0 && controler != 0){ // if in the elder process write the header
			printf("\n\t\t\t/////////////////////EXCERCISE B/////////////////////////////\n\t\tProgram that call fork 3 times and prints the id's for all the created processes (each in a new line using exec)\n");
		}

		if(controler == -1){ // if forking was unsuccesful return an error statement
			perror("FORK FAILIURE - B)");
			exit(EXIT_FAILURE);
		}
		else if(controler != 0){ // if in the parent process print its ID
			if(processID == 0){
				printf("\t\t\tUID: %d,GID: %d,PID: %d, PPID: %d,PGID:%d\n",getuid(),getgid(),getpid(),getppid(),getpgid(0));
				processID++; // signal
			}
			else{
				wait(NULL); // wait for childern 
				wait(NULL);
			}
		}
		else if (controler == 0){
			sleep(0.5); 
			execlp(argv[1],argv[1],(char*)NULL); // execlp used to print childern childern ID statements,by running a new program that's inputed through the arguments of elder program
			perror("execlp error"); //error checking
			_exit(2);
			processID+=2;
		}
	}
}

