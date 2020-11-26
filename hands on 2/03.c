/*
MT2019114
getrlimit() to print the system resource limits.
setrlimit() to set the system resource limit.
RLIMIT_NOFILE: This  specifies  a  value  one  greater  than  the  maximum file descriptor number that can be opened by this process.
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>   

struct rlimit rl;

int main(void){

	getrlimit(RLIMIT_NOFILE,&rl); 
	printf("Soft Limit on number of file descriptors is : %lld\n", (long long int)rl.rlim_cur);
	printf("Hard Limit on number of file descriptors is : %lld\n", (long long int)rl.rlim_max);

	rl.rlim_cur = 2048;
	setrlimit(RLIMIT_NOFILE,&rl); 
	getrlimit(RLIMIT_NOFILE,&rl); 

	printf("Soft Limit on number of file descriptors is : %lld\n", (long long int)rl.rlim_cur);
	printf("Hard Limit on number of file descriptors is : %lld\n", (long long int)rl.rlim_max);

	return 0;
}


