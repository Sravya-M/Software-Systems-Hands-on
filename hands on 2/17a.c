/*
MT2019114
ls -l | wc (use dup)
parent is writing ls -l to pipe by closing the stdout and child is reading using pipe by closing the stdin and display the output on monitor
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
		close(0);//close stdin
		dup(fd[0]);
		execlp ("wc","wc", (char *)NULL);		
		write(1,"\n",1);
		close(fd[0]);
	}
	else {
		close(fd[0]); // close unused read end
		close(1); // close stdout
		dup(fd[1]);
		execlp ("ls","ls","-l", (char *)NULL);
		close(fd[1]);
	}
	return 0;
}
