/* MT2019114
	go /proc/pid/fd
	check file descriptors
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int a;
	creat("file1.txt",0744);
	creat("file2.txt",0744);
	creat("file3.txt",0744);
	creat("file4.txt",0744);
	creat("file5.txt",0744);
	for( ;; )
	{
		a=0;
	}

	return 0;
}
