/* Author: Sravya M, MT2019114
// cp file1 file2
// this command will overwrite the contents of file2 with file1 if file2 already exists
// if not, it will create new file2 and copy the contents of file1 to it
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd1=open(argv[1],O_RDONLY);
	int fd2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0744);

	char c;

// taking a temporary variable to store read return value
// returns number of characters read, 0 when it reaches the end of file
	int count;
	count=read(fd1,&c,sizeof(char));

	while(count)
	{
		write(fd2,&c,sizeof(char));
		count=read(fd1,&c,sizeof(char));			
	}

	close(fd1);
	close(fd2);
	return 0;
}
