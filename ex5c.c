#include "ex5.h"

int main(int argc,char* argv[]){
	int pipefDescrypt,fDescrypt,bytesRead;
	const char *nameId= {"\nConsumer: \0"};
	const char *buffer[BYTES];

	pipefDescrypt = open(argv[3],O_RDONLY,0644);
	fDescrypt = open(argv[1],O_WRONLY | O_TRUNC | O_CREAT,0644);
	
	while((bytesRead = read(pipefDescrypt,buffer,BYTES)) != 0){
		if(bytesRead==-1){ perror("READ_FAILURE!"); exit(EXIT_FAILURE); }
		else{
			write(fDescrypt,buffer,bytesRead);
			write(STDOUT_FILENO,nameId,strlen(nameId));
			write(STDOUT_FILENO,buffer,bytesRead);
		}
	}

	close(fDescrypt);
	close(pipefDescrypt);
		
	
		return 0;
}
