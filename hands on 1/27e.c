/* MT2019114 
execute ls -Rl using execvp
execvp = 
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	char *args[] = {"ls","-Rl",(char *)0};
        execvp("ls",args);

	return 0;
}
