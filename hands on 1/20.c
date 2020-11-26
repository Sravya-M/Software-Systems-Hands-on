/* MT2019114
get the priority of your process and change it using nice
1. getpriority(which, who) returns nice value of the current calling thread when who=0
2. nice(incr)  = adds incr value to nice value of calling thread

1. ps -o ni,pri 6742 2. we can check in stat file too
For making nice to a -ve value, use sudo (i.e., for incrementing the priority)
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/time.h>

int main()
{
	int a=getpriority(PRIO_PROCESS,0);
	printf("%d\n",a);

	a=nice(-3);
	printf("%d\n",a);

	return 0;
}
