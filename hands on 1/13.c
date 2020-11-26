/* MT2019114
making STDIN wait for 10 sec using "select"
int select(int nfds, fd_set *rfds, fd_set *wfds, fd_set *exceptfds, struct timeval *timeout)
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/select.h>

int main()
{
	fd_set rfds;
	struct timeval t;
	int retval;

// watching stdin for inputs
	FD_ZERO(&rfds);
	FD_SET(0,&rfds);

// asking to wait for 5sec
	t.tv_sec=10;

	retval=select(1,&rfds, NULL,NULL, &t);
	if(retval)
		printf("Data available\n");
	else
		printf("No data");

	return 0;
}
