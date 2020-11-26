/* MT2019114
Locking a particular record by setting proper values for l_start, l_len
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>

int main (){
	struct record{
		char name[10];
		int marks;
	}r[3];

	int n;
	int fd = open("db.txt",O_RDWR);

	printf("Enter the record to be locked ");
	scanf("%d",&n);

// setting lock parameters
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=(n-1)*sizeof(r);
	lock.l_len=sizeof(r);
	lock.l_pid=getpid();

	int st = fcntl(fd,F_SETLKW,&lock);

// CS of nth record
	read(fd,&r,sizeof(r));
	r[n-1].marks +=1;
	lseek(fd,0,SEEK_SET);
	write(fd,&r,sizeof(r));
// CS
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);

	close(fd);

	fd = open("db.txt",O_RDONLY);
	read(fd,&r,sizeof(r));
	printf("Name : %s Marks : %d\n",r[0].name,r[0].marks);
	printf("Name : %s Marks : %d\n",r[1].name,r[1].marks);
	printf("Name : %s Marks : %d\n",r[2].name,r[2].marks);
	close(fd);

	return 0;
}
