#include "ex5.h"


int main(int argc,char* argv[]){
	const char *nameId= {"\nProducer: \0"};
	const char *buffer[BYTES2];
	char *consumerFile = argv[1], *producerFile = argv[2], *pipeFile = argv[3], *consumerProgram = argv[4];
	int resultFork, fDescrypt, pipefDescrypt, bytesRead;
	int runState = normal_termination; // normal_termination == 0;

	
	if(mkfifo(pipeFile,0644) != -1) {
		resultFork = fork();	

		//runState = atexit(pipeClose);
		//if(runState != normal_termination){ runState = err_atexit; goto errorChecker; }// here
											     
		switch(resultFork){
		case -1: { runState=err_fork; goto errorChecker; }
		case  0: {
				sleep(1);
				runState = execlp(consumerProgram,argv[0],consumerFile,producerFile,pipeFile,NULL);
				if ( runState == -1) { runState = err_execlp; goto errorChecker; }
			 }
		default:{
				runState = producentOpenFiles(&pipefDescrypt,&fDescrypt,producerFile,pipeFile);
				if ( runState == -1) { runState = err_open; goto errorChecker; }

				while((bytesRead = read(fDescrypt,buffer,BYTES2)) != 0){ // read from the file onto the buffer,save the amount of chars saved
					sleep(1);
					if(bytesRead == -1){ runState = err_read; goto errorChecker; }
					else{
						runState = producentWrite(pipefDescrypt,bytesRead,buffer,nameId);
						if ( runState == -1) { runState = err_write; goto errorChecker; }
					}
				}
				producentCloseFiles(pipefDescrypt,fDescrypt);
				if( wait(NULL) == -1) { runState = err_wait; goto errorChecker; }
			}
		};
	}
	else{
		runState = err_mkfifo;
		goto errorChecker;
	}

	unlink(pipeFile);
	if(runState != normal_termination){
		errorChecker: errorHandler(runState);
	}

	return 0;
}

int producentWrite(int pipefDescrypt, int bytesRead, const char *buffer[], const char *nameId){
      if(write(STDOUT_FILENO,nameId,strlen(nameId)) == -1) { return -1; }
      else if(write(STDOUT_FILENO,buffer,bytesRead) == -1) { return -1; }
      else if(write(pipefDescrypt,buffer,bytesRead) == -1) { return -1; }
      else { return 0; }

}

int producentOpenFiles(int *pipefDescrypt,int *fDescrypt,char *producentFile,char*pipeFile){
	*fDescrypt = open(producentFile,O_RDONLY,0644); 
	*pipefDescrypt = open(pipeFile,O_WRONLY,0644); 

	if(*fDescrypt == -1 || *pipefDescrypt == -1) { return -1; }
	else { return 0; }
}

int producentCloseFiles(int pipefDescrypt,int fDescrypt){
	if     (close(pipefDescrypt) == -1) { return -1; }
	else if(close(fDescrypt) == -1) { return -1; }
	else { return 0; }
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



