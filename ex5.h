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

enum error_types { normal_termination=0, err_mkfifo, err_fork, err_execlp, err_open, err_close, err_write, err_read, err_unlink, err_wait,err_atexit };

#define BYTES 10
#define BYTES2 20
#define END_OF_FILE 0
#define READ 0
#define WRITE 1

//minor functions
void pipeClose();
void argumentChecker(int argc);
void errorHandler(int errType);
void randomSleep();
int launch(char*programToLaunch,char*argv[],char*programFile,char*pipeFile);
int producentOpenFiles(int *pipefDescrypt,int *fDescrypt,char *producentFile,char*pipeFile);
int producentCloseFiles(int pipefDescrypt,int fDescrypt);
int consumerOpenFiles(int *pipefDescrypt,int *fDescrypt,char *consumerFile,char*pipeFile);
int consumerCloseFiles(int pipefDescrypt,int fDescrypt);

//major functions
int consumerWrite(int fDescrypt, int bytesRead, const char *buffer[], const char *nameId);
int producentWrite(int pipefDescrypt, int bytesRead, const char *buffer[], const char *nameId);
void producent_pipe_manager(const char*buffer[],int pipe_write_descryptor,int read_bytes);
int producent(const char*buffer[],int file_descryptor,int pipe_write_descryptor,int bytes_to_read);
int consument_file_manager(const char*buffer[],int file_descryptor,int read_bytes);
int consument(const char*buffer[],int file_descryptor,int pipe_write_descryptor,int bytes_to_read);
