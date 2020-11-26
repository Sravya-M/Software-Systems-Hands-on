/*
MT2019114
ls -Rl| grep ^d| wc (use dup2)
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main (void) {
	int fd0[2],fd1[2];	
	pipe(fd0);
	pipe(fd1);
	
	if(!fork()){

		close(fd0[0]); // close read end of pipe0
		close(fd1[1]); // close write end of pipe1
		close(fd1[0]);
		dup2(fd0[1],1);
		execlp ("ls","ls","-Rl", (char *)NULL);

	}
	else{
		if (!fork()){

		close(fd0[1]); // close write end of pipe0
		close(fd1[0]); // close read end of pipe1
		dup2(fd0[0],0);
		dup2(fd1[1],1);
		execlp("grep","grep","^d",(char *)NULL);
		close(fd0[0]);
		close(fd1[1]);

		}
		else {	
			close(fd0[0]); // close read end of pipe0
			close(fd1[1]); // close write end of pipe1
			close(fd0[1]);
			dup2(fd1[0],0);
			execlp("wc","wc",(char *)NULL);
			write(1,"\n",1);
			close(fd1[0]);		
		}	
	}
	return 0;
}
