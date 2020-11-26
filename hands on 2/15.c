/*
MT2019114
parent is writing through command line argument and child is reading 
*/
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char **argv){
	int fd[2];
	pipe(fd);
	char buf;
	if (!fork()){
		close(fd[1]); // close unused write end
		while (read(fd[0],&buf,1)>0)
			write(1,&buf,1);
		write(1,"\n",1);
		close(fd[0]);
	}
	else {
		close(fd[0]); // close unused read end
		write(fd[1],argv[1],strlen(argv[1]));
		close(fd[1]);
	}
	return 0;
}
