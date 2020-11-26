/* MT2019114
print USER using environ
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

// we have to explicitely mention this in order to use environ
extern char **environ;

int main()
{
	char *ex="USER";

// using getenv(env variable) function
	char *a=getenv(ex);
	printf("%s\n",a);

// using environ strings
	int i=0;
	while(environ[i])
	{
		if(strncmp(ex,environ[i],4)==0)
		{
			printf("%s\n",environ[i]);
			return 0;
		}
		i++;
	}
	return 0;
}
