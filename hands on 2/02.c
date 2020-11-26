/*
MT2019114
getrlimit() to print the system resource limits.
RLIMIT_NOFILE: This  specifies  a  value  one  greater  than  the  maximum file descriptor number that can be opened by this process.
The soft  limit  is  the value that the kernel enforces for the corresponding resource.  
The hard limit acts  as  a  ceiling  for  the  soft limit.
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

struct rlimit rl;

int main(void){

	getrlimit(RLIMIT_NOFILE,&rl); 
	printf("Soft Limit on number of file descriptors is : %lld\n", (long long int)rl.rlim_cur); 
	printf("Hard Limit on number of file descriptors is : %lld\n", (long long int)rl.rlim_max);	
	return 0;
}


