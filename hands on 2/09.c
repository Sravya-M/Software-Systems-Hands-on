/*
MT2019114
first i am ignoring SIGINT and then i am setting it to defualt settings.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int flag = 0;

int main(void) {
	signal(SIGINT, SIG_IGN);
	printf("Pressing Ctrl-C has no effect\n");
	sleep(10);
	printf("Default resetted.. Pressing Ctrl-C has effect now.\n");
	signal(SIGINT, SIG_DFL);
	sleep(10);
    	return 0;
}
