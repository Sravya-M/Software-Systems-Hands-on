/* MT2019114 
execute ls -Rl using execlp
execlp = 
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
        execlp("ls","ls","-Rl",(char *)0);

	return 0;
}
