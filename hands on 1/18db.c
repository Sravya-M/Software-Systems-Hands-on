/* MT2019114
creating few records in database
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include <string.h>

struct record{
	char name[10];
	int marks;
	}r[3];

int main (){

	int fd = open("db.txt",O_CREAT|O_RDWR,0744);

// initialization of records
	strcpy(r[0].name,"student1");
	strcpy(r[1].name,"student2");
	strcpy(r[2].name,"student3");	
	r[0].marks = 50;
	r[1].marks = 47;
	r[2].marks = 49;

// writing into the db.txt file
	write(fd,&r,sizeof(r));
	close(fd);

	fd = open("db.txt",O_RDONLY);
	read(fd,&r,sizeof(r));
	printf("Name : %s Marks : %d\n",r[0].name,r[0].marks);
	printf("Name : %s Marks : %d\n",r[1].name,r[1].marks);
	printf("Name : %s Marks : %d\n",r[2].name,r[2].marks);

	close(fd);
	return 0;
}
