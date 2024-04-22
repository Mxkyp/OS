#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/wait.h>

#define BYTES 10
#define BYTES2 20
#define END_OF_FILE 0
#define READ 0
#define WRITE 1

//minor functions
void argumentChecker(int argc);
void randomSleep();

//major functions
void producent_pipe_manager(const char*buffer[],int pipe_write_descryptor,int read_bytes);
int producent(const char*buffer[],int file_descryptor,int pipe_write_descryptor,int bytes_to_read);
int consument_file_manager(const char*buffer[],int file_descryptor,int read_bytes);
int consument(const char*buffer[],int file_descryptor,int pipe_write_descryptor,int bytes_to_read);
