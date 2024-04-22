#include "ex5.h"

int main(int argc,char* argv[]){
	int resultFork,fDescrypt,pipefDescrypt,bytesRead;
	const char *nameId= {"\nProducer: \0"};
	const char *buffer[BYTES2];

	
	if(mkfifo(argv[3],0644) != -1) {
		resultFork = fork();	
		switch(resultFork){
		case -1: perror("\nFORK ERROR\n"); exit(EXIT_FAILURE);
		case  0: {
				sleep(1);
				execlp(argv[4],argv[0],argv[1],argv[2],argv[3],NULL);
				break;
			 }
		default:{
				fDescrypt = open(argv[2],O_RDONLY,0644); // open the file for writing
				pipefDescrypt = open(argv[3],O_WRONLY,0644); // open the file for writing

				while((bytesRead = read(fDescrypt,buffer,BYTES2)) != 0){ // read from the file onto the buffer,save the amount of chars saved
					sleep(1);
					if(bytesRead==-1){ perror("READ ERROR"); exit(EXIT_FAILURE); }
					write(STDOUT_FILENO,nameId,strlen(nameId)); 
					write(STDOUT_FILENO,buffer,bytesRead); 
					write(pipefDescrypt,buffer,bytesRead);
				}
				close(fDescrypt);
				close(pipefDescrypt);
				wait(NULL);
			}
		}
	}
	else{
		perror("MKFIFO ERROR");
	 	return -1;
	}
	unlink(argv[3]);
		return 0;
}

void producentWrite(int pipefDescrypt,const char* buffer,bytesRead){


}


