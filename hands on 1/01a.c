/* MT2019114
Soft link can be used across file systems
symlink(filepath,linkname)
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int ret = symlink("test.txt","mysoft");
	printf("%d\n",ret);

	return 0;
}
