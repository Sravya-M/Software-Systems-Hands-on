/*
MT2019114
Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal use sigaction system call.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main ( void ) {
	struct sigaction my_action;
	
//Ignore SIGINT 

   my_action.sa_handler = SIG_IGN;
   sigaction (SIGINT, &my_action, NULL);
   printf ("Ignoring SIGINT\n");
   printf("Pressing Ctrl-C has no effect\n");
   sleep(3); 

//Default action 

   my_action.sa_handler = SIG_DFL;
   sigaction (SIGINT, &my_action, NULL);
   printf("Default resetted.. Pressing Ctrl-C has effect now.\n");
   sleep(3);
   printf ("No SIGINT within 3 seconds\n"); 
   return 0;
}
