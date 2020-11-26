/*
MT2019114
program to print the maximum number of files (sysconf) can be opened within a process and size of a pipe (pathconf).
*/

#include <unistd.h>
#include <stdio.h>

int main(void){

	long size_pipe, max_files;
	size_pipe=pathconf(".",_PC_PIPE_BUF);
	max_files=sysconf(_SC_OPEN_MAX);
	printf("Maximum number of files that can be opened within a process: %ld\nSize of Pipe: %ldB\n",max_files,size_pipe);
	return 0;

}
