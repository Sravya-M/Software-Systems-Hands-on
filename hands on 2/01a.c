/*
MT2019114
interval timer in real domain. signal is SIGALARM - 14 
*/

#include<sys/time.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void print(){
	printf("ITIMER_REAL\n");
}

int main(void){
	struct itimerval val;
	val.it_value.tv_sec = 10;
	val.it_value.tv_usec= 10;
	setitimer(ITIMER_REAL,&val,0);
	signal(14,print);
	sleep(10);
	return 0;
}
