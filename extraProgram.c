#include "ex5.h"


int main(int argc,char* argv[]){
	char *producerProgram = argv[1],*consumerProgram = argv[2];
	char *producerFile = argv[3],*consumerFile = argv[4], *pipeFile = argv[5]; 
	
	/*
	char *subProgram[2],*subFiles[2];
	*subProgram[0] = *producerProgram;
	*subProgram[1] = *consumerProgram;
	*subFile[0] = *producerFile;
	*subFile[1] = *consumerFile;
	*/

	int resultFork[2];
	int runState = normal_termination; // normal_termination == 0;

	
	if(mkfifo(pipeFile,0644) != -1) {

		for(int i=0;i<2; i++){							     
		resultFork[i] = fork();	

		//runState = atexit(pipeClose);
		//if(runState != normal_termination){ runState = err_atexit; goto errorChecker; }// here
		switch(resultFork[i]){
		case -1: { runState=err_fork; goto errorChecker; }
		case  0: {	
				if(i == 0){
					sleep(1);
					runState = execlp(consumerProgram,argv[0],consumerFile,pipeFile,NULL);
					if ( runState == -1) { runState = err_execlp; goto errorChecker; }
				}
				else{
					sleep(1);
					runState = execlp(producerProgram,argv[0],producerFile,pipeFile,NULL);
					if ( runState == -1) { runState = err_execlp; goto errorChecker; }
				}
			 }
		};
		}
	}
	else{
		runState = err_mkfifo;
		goto errorChecker;
	}

	for(int i=0;i<2;i++){
		runState = waitpid(resultFork[i],NULL,WUNTRACED);
		if(runState == -1) { runState = err_wait; goto errorChecker; }
	}
	unlink(pipeFile);

	errorChecker:errorHandler(runState);

	return 0;	
}

int Launch(char*argv[],char*programToLaunch,char*programFile,char*pipeFile){ // add this to header
	if( execlp(programToLaunch,argv[0],programFile,pipeFile,NULL) == -1){
		return -1;
	}
	else {	return 0; }
}

void errorHandler(int runState){
	switch(runState){
	case normal_termination: printf("ALL GUCCI");
	     break;
	case err_mkfifo: perror("mkfifo error"); 
	     break;
	case err_fork: perror("fork error"); 
	     break;
	case err_execlp: perror("execlp error"); 
	     _exit(EXIT_FAILURE);
	     break;
	case err_open: perror("open error"); 
	     break;
	case err_close: perror("close error");
	     break;
	case err_write: perror("write error");
	     break;
	case err_read: perror("read error");
	     break;
	case err_unlink: perror("unlink error");
	     break;
	case err_wait: perror("wait error");
	     break;
	};
}



