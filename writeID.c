#include <stdio.h>
#include <unistd.h>

int main(){
	printf("\t\t\tUID: %d,GID: %d,PID: %d, PPID: %d,PGID:%d\n",getuid(),getgid(),getpid(),getppid(),getpgid(0));

	return 0;
}
