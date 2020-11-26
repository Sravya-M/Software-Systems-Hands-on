/* MT2019114
Orphan process
If parent process is terminated before child process's execution, then the child process will become an orphan process
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int a=fork();
	if(a==0)
		sleep(30);
	else if(a>0)
	{}	
	return 0;
}
