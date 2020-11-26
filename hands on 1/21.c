/* MT2019114
	fork - printing parent and child ids
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	if(!fork())
		printf("child id is %d\n",getpid());
	else
		printf("parent id is %d\n",getpid());
	return 0;
}
