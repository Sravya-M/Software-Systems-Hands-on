/* MT2019114
program for the parent to wait for a particular child
waitpid(pid,int *status,int options)
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	int c1,c2,c3;
	int status;

	if(!(c1=fork()))
		sleep(2);
	else if(!(c2=fork()))
		sleep(6);
	else if(!(c3=fork()))
		sleep(10);
	else
	{
		waitpid(c2,&status,0);
		printf("%d ",status);
	}

	return 0;
}
