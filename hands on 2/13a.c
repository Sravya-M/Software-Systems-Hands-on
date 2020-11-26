/*
MT2019114
to catch sigstop
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void my_handler () {
	 printf ("I got SIGSTOP\n");
}

int main ( void ) {
	//Catch SIGSTOP
	printf("pid: %d\n", getpid());
	signal(SIGSTOP,my_handler);
    	printf ("Catching SIGSTOP\n");
    	getchar();
	return 0;

}
