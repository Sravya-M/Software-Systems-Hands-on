/*
MT2019114
to kill particular pid
*/

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

int main ( void ) {
	int p;
	printf("Enter pid: ");
 	scanf("%d", &p);
	kill(p,SIGKILL);
	return 0;
}
