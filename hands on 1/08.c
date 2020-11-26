/* MT2019114
program to read a file line by line and print on STDOUT
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd1=open(argv[1],O_RDONLY);
	char c;

	int count;
	count=read(fd1,&c,sizeof(char));

	while(count)
	{
		if(c=='\n')
		{
			read(0,&c,sizeof(char));
			count=read(fd1,&c,sizeof(char));			
		}
		else
		{
		write(1,&c,sizeof(char));
		count=read(fd1,&c,sizeof(char));			
		}
		
	}

	close(fd1);
	return 0;
}
