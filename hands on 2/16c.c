/*
MT2019114
2 way communication using pipe sequence is as follows
child is writing to pipe0
parent is reading from pipe0
parent is writing to pipe1
child is reading from pipe1
*/

#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main (void) {
	int fd0[2],fd1[2];
	pipe(fd0);
	pipe(fd1);
	char read_child[20];
	char write_child[20] = "hello how are you?";
	char read_parent[20];
	char write_parent[20] = "I am fine";
	
	if(!fork()){
		close(fd0[0]); // close read end of pipe0
		close(fd1[1]); // close write end of pipe1
		
		write(1,"Child: Writing to pipe0\n",strlen("Child: Writing to pipe0\n"));
		write(fd0[1],&write_child,sizeof(write_child));// child will write

		read(fd1[0],&read_child,sizeof(read_child)); // child will read
		write(1,"Child: Reading from pipe1, ",strlen("Child: Reading from pipe1, "));
		write(1,&read_child,sizeof(read_child)); 
		write(1,"\n",1);

		close(fd0[1]);
		close(fd1[0]);
	}
	else{
		close(fd0[1]); // close write end of pipe0
		close(fd1[0]); // close read end of pipe1

		read(fd0[0],&read_parent,sizeof(read_parent));// parent will read
		write(1,"Parent: Reading from pipe0, ",strlen("Parent: Reading from pipe0, "));
		write(1,&read_parent,sizeof(read_parent));
		write(1,"\n",1);

		write(1,"Parent: Writing to pipe1\n",strlen("Parent: Writing to pipe1\n"));
		write(fd1[1],&write_parent,sizeof(write_parent));// parent will write
		
		close(fd1[1]);
		close(fd0[0]);
		
	}
	return 0;
}
