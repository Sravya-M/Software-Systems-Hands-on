/*
MT2019114
creating a pipe, writing to pipe using fd[1], reading from pipe using fd[0], printing to monitor.
*/

#include <unistd.h>
#include <fcntl.h>

int main (void){
	int fd[2];
	pipe(fd);
	char buf[11] = "Sravya";
	char out[11]; 
	write(fd[1],&buf,sizeof(buf));
	read(fd[0],&out,sizeof(out));
	write(1,&out,sizeof(out));
	write(1,"\n",1);
	return 0;
}
