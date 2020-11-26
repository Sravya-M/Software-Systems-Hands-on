/* MT2019114 
execute ls -Rl using execle
execle = 
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
        execle("/bin/ls","ls","-Rl",(char *)0,env);

	return 0;
}
