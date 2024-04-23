#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/wait.h>

//enum values used for error checking
enum error_types { normal_termination=0, err_mkfifo, err_fork, err_execlp, err_open, err_close, err_write, err_read, err_unlink, err_wait, err_atexit, err_argc };

#define BYTES 10
#define BYTES2 20
#define END_OF_FILE 0


//minor functions
void pipeClose(); // function for closing the pipe at ATEXIT
int argumentChecker(int argc); // function for validating the argc count
void errorHandler(int errType); // function for error handling
int launch(char*programToLaunch,char*argv[],char*programFile,char*pipeFile); // function for launching the PRODUCER, CONSUMER programs

//producer -program- specific functions
int producentOpenFiles(int *pipefDescrypt,int *fDescrypt,char *producentFile,char*pipeFile); // function for opening the producer files
int producentCloseFiles(int pipefDescrypt,int fDescrypt); // function for closing the producer files
int producentWrite(int pipefDescrypt, int bytesRead, const char *buffer[], const char *nameId); // function used by producer for writing onto the console and pipe

//consumer -program- specific functions
int consumerOpenFiles(int *pipefDescrypt,int *fDescrypt,char *consumerFile,char*pipeFile);  //// function for opening the consumer files 
int consumerCloseFiles(int pipefDescrypt,int fDescrypt); //function for closing the consumer files
int consumerWrite(int fDescrypt, int bytesRead, const char *buffer[], const char *nameId); //function used by consumer for writing onto the console and the CONSUMER FILE

