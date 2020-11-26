#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

// for db purpose, adding a ticket number

struct ticket
{
	int tno;
};

int main()
{
	struct ticket t;
	t.tno=10;

	int fd=open("ticket.txt",O_CREAT|O_RDWR,0744);

	write(fd,&t,sizeof(t));
	read(fd,&t,sizeof(t));

	printf("%d\n",t.tno);
	close(fd);

	return 0;
}
