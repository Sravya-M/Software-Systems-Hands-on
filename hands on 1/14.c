/*MT2019114
	S_IFMT is a bitmask to get file type from st_mode
	man pages:
	file type flags: inode(7)
	stat structure: stat(2)

	POSIX functions are also there to check the file type
	ex: S_ISREG(s.st_mode)
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char **argv)
{
	unsigned long int type;
	struct stat s;
	stat(argv[1],&s);

	printf("%d \n",s.st_mode);

// bit wise AND of st_mode , S_IFMT to get only the file type
	type=s.st_mode & S_IFMT;

	switch(type)
	{
		case S_IFREG:
			printf("Regular file\n");
			break;
		case S_IFLNK:
			printf("symbolic link\n");
			break;
		case S_IFBLK:
			printf("block device\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFIFO:
			printf("named pipe or FIFO\n");
			break;
		case S_IFCHR:
			printf("character device\n");
			break;
		case S_IFSOCK:
			printf("socket\n");
			break;
	}

	return 0;
}
