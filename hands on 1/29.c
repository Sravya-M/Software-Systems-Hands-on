/*
man sched
sched_getscheduler()
SCHED_OTHER  // standard round robin time sharing policy 0
SCHED_FIFO   // first in first out 1
SCHED_RR     // round robin policy 2
sched_setscheduler()
*/

#include<stdio.h>
#include<sched.h>
#include<unistd.h>

int main()
{
	struct sched_param param;
	param.sched_priority=99;

	pid_t id=getpid();
	int sc = sched_getscheduler(id);

	printf("%d\n",sc);
	
	sched_setscheduler(id,SCHED_RR,&param);
	sc=sched_getscheduler(id);
	printf("RR %d\n",sc);

	sched_setscheduler(id,SCHED_FIFO,&param);
	sc=sched_getscheduler(id);
	printf("FIFO %d\n",sc);
		
	return 0;
}
