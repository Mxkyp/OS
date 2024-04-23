#include "ex5.h"

char* pipeFile;

int main(int argc,char* argv[]){ 
	pipeFile = argv[5];
	char *producerProgram = argv[1],*consumerProgram = argv[2];
	char *producerFile = argv[3],*consumerFile = argv[4]; 
	char *subProgram[2],*subFile[2];
	subProgram[0] = producerProgram;
	subProgram[1] = consumerProgram;
	subFile[0] = producerFile;
	subFile[1] = consumerFile;
	

	int resultFork[2];
	int runState = normal_termination; // normal_termination == 0;

	
	runState = argumentChecker(argc);	
	if(runState == -1){ runState = err_argc; goto errorChecker; }

	if(mkfifo(pipeFile,0644) == -1) { runState = err_mkfifo; goto errorChecker; }
	if(atexit(pipeClose) != 0)	{ runState = err_atexit; goto errorChecker; }

	for(int i=0;i<2; i++){							     
		resultFork[i] = fork();	

		switch(resultFork[i]){
		case -1: { runState=err_fork; goto errorChecker; }
		case  0: {	

				runState = launch(subProgram[i],argv,subFile[i],pipeFile);
				if(runState == -1) { runState = err_execlp; goto errorChecker; }

			 }
		};
	}

	for(int i=0;i<2;i++){
		if(waitpid(resultFork[i],NULL,WUNTRACED) == -1){ runState = err_wait; goto errorChecker; }
	}

	if(runState != normal_termination){
		errorChecker:errorHandler(runState);
		return -1;
	}

	return 0;	
}

int launch(char*programToLaunch,char*argv[],char*programFile,char*pipeFile){ // add this to header
	if( execlp(programToLaunch,argv[0],programFile,pipeFile,NULL) == -1){
		return -1;
	}
	else {	return 0; }
}

void pipeClose(){
	unlink(pipeFile);
}

void errorHandler(int runState){
	switch(runState){
	case err_argc:   perror("argc error");
	     break;
	case err_mkfifo: perror("mkfifo error"); 
	     break;
	case err_fork:   perror("fork error"); 
	     break;
	case err_execlp: perror("execlp error"); 
	     _exit(EXIT_FAILURE);
	     break;
	case err_open:   perror("open error"); 
	     break;
	case err_close:  perror("close error");
	     break;
	case err_write:  perror("write error");
	     break;
	case err_read:   perror("read error");
	     break;
	case err_unlink: perror("unlink error");
	     break;
	case err_wait:   perror("wait error");
	     break;
	};
}

int argumentChecker(int argc){
	if(argc != 6) { return -1;}
	else { return 0; }

}


