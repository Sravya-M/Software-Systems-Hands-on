// MT2019114

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(void){
	int i;
	if(!fork()) {
		i=getppid();
		printf("Child's parent id before orphan: %d\n",getppid());
		kill(SIGKILL,i);
		printf("Child's parent id after orphan: %d\n",getppid() ); 
	}
	return 0;
}
