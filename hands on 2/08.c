/*
MT2019114
TEST CASES:
SIGINT - Ctrl+C
*/

#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void my_handler(int sig);

int main ( void ) {

	char choice;
	
	printf("a.SIGSEGV\n");
	printf("b.SIGINT\n");
	printf("c.SIGFPE\n");
	printf("d.SIGALRM(use alarm system call)\n");
	printf("e.SIGALRM(use setitimer system call)\n");
	printf("f.SIGVTALRM (use setitimer system call)\n");
	printf("g.SIGPROF (use setitimer system call)\n");

	printf("Enter the alphabet\n");
	scanf("%c",&choice);

	if (choice=='a'){
	    signal (SIGSEGV, my_handler);
	    
	}
	else if(choice=='b'){
	    signal (SIGINT, my_handler);
	    sleep(3);
	}
	
	
    return 0;
}

/* User-defined signal handler function */
void my_handler (int sig) {
    switch(sig){
	case 11: printf("Caught SIGSEGV: segfault\n");
       		break;
       case 2: printf("\nCaught SIGINT: interactive attention signal, probably a ctrl+c\n");
		      break;
   }	
}

