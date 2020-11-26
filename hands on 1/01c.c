/* MT2019114
mkfifo(pathname,mode)
returns 0 on success, -1 if it already exists
we can check from terminal by echo and cat
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int ret = mkfifo("myfifo",0744);
	printf("%d\n",ret);

	return 0;
}
