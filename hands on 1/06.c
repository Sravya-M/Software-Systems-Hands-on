/* MT2019114
	program to read from STDIN and write to STDOUT	
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	int a;
	read(0,&a,sizeof(a));
	write(1,&a,sizeof(a));

	return 0;
}
