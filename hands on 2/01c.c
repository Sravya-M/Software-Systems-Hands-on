/*
MT2019114
This  timer  counts  down  against the total (i.e., both user and system) CPU time consumed by the process. 
signal is SIGPROF - 27 
*/

#include<sys/time.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void print(){
	printf("ITIMER_PROF\n");
}

int main(void){
	struct itimerval val;
	val.it_value.tv_sec = 10;
	val.it_value.tv_usec= 10;
	setitimer(ITIMER_PROF,&val,0);
	signal(27,print);
	while(1);		
	return 0;
}
