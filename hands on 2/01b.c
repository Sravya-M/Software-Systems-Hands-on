/*
MT2019114
This timer counts down against the  user-mode  CPU  time consumed  by the process. 
signal is SIGVTALRM - 26 
*/

#include<sys/time.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void print(){
	printf("ITIMER_VIRTUAL\n");s
}

int main(void){
	struct itimerval val;
	val.it_value.tv_sec = 10;
	val.it_value.tv_usec= 10;
	setitimer(ITIMER_VIRTUAL,&val,0);
	signal(26,print);
	while(1);
	return 0;
}
