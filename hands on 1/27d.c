/* MT2019114 
execute ls -Rl using execv
execv = 
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	char *args[] = {"ls","-Rl",(char *)0};
        execv("/bin/ls",args);

	return 0;
}
