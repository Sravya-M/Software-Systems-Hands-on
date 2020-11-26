/* MT2019114 
execute ls -Rl using execl
execl = 
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
        execl("/bin/ls","ls","-Rl",(char *)0);

	return 0;
}
