/*
man sched
man sched_get_priority_max(sched policy)
get max and min real time priority
As real time system uses FIFO and RR, I am displaying them
*/

#include<stdio.h>
#include<sched.h>

int main()
{
	int pmin=sched_get_priority_min(SCHED_FIFO);
	int pmax=sched_get_priority_max(SCHED_FIFO);

	printf("pmin: %d, pmax: %d\n",pmin,pmax);
	return 0;
}
