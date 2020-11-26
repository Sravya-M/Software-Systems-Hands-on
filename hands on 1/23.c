/* MT2019114
zombie process
If a child process gets finished before the parent process, it will be a zombie i.e., its entry will be there in process table as it has to return to parent process
ps -ef|grep a.out // to check the defunct/zombie process
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int a=fork();
	if(a==0)
		exit(0);
	else if(a>0)
		sleep(50); // we can also use wait()
	return 0;
}
