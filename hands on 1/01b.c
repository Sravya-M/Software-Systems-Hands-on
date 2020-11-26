/* MT2019114
Hard link is used within a file system 
link(oldpath,newpath)
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int ret = link("test.txt","hard.txt");
	printf("%d\n",ret);

	return 0;
}
