#include "ex5.h"

int main(int argc,char* argv[]){
	const char *nameId= {"\nConsumer: \0"};
	const char *buffer[BYTES];
	int pipefDescrypt,fDescrypt,bytesRead;
	int runState = normal_termination; // normal_termination == 0;
	char *consumerFile = argv[1], *pipeFile = argv[2];

	runState = argumentChecker(argc);
	if( runState == -1) { runState = err_argc; goto errorChecker; }

	runState = consumerOpenFiles(&pipefDescrypt,&fDescrypt,consumerFile,pipeFile);
	if( runState == -1) { runState = err_open; goto errorChecker; }
	
	while((bytesRead = read(pipefDescrypt,buffer,BYTES)) != 0){
		if(bytesRead==-1){ runState = err_read; goto errorChecker; }

		runState = consumerWrite(fDescrypt,bytesRead,buffer,nameId);
		if( runState == -1) { runState = err_write; goto errorChecker; }
	}
	
	runState = consumerCloseFiles(pipefDescrypt,fDescrypt);
	if(runState == -1) { runState = err_close; goto errorChecker; }
	
	if(runState != normal_termination){
		errorChecker: errorHandler(runState);
		return -1;
	}
		
	
		return 0;
}

int argumentChecker(int argc){
	if(argc != 3) { return -1;}
	else { return 0; }

}

int consumerWrite(int fDescrypt, int bytesRead, const char *buffer[], const char *nameId){
      if(write(STDOUT_FILENO,nameId,strlen(nameId)) == -1) { return -1; }
      else if(write(STDOUT_FILENO,buffer,bytesRead) == -1) { return -1; }
      else if(write(fDescrypt,buffer,bytesRead) == -1)     { return -1; }
      else { return 0; }

}

int consumerOpenFiles(int *pipefDescrypt,int *fDescrypt,char *consumerFile,char*pipeFile){
	*fDescrypt = open(consumerFile,O_WRONLY | O_CREAT | O_TRUNC,0644); 
	*pipefDescrypt = open(pipeFile,O_RDONLY,0644); 

	if(*fDescrypt == -1 || *pipefDescrypt == -1) { return -1; }
	else { return 0; }
}

int consumerCloseFiles(int pipefDescrypt,int fDescrypt){
	if     (close(pipefDescrypt) == -1) { return -1; }
	else if(close(fDescrypt) == -1)     { return -1; }
	else { return 0; }
}

void errorHandler(int runState){
	switch(runState){
	case err_argc: perror("argc error");
	     break;
	case err_open: perror("open error"); 
	     break;
	case err_close: perror("close error");
	     break;
	case err_write: perror("write error");
	     break;
	case err_read: perror("read error");
	     break;
	};
}
