/* MT2019114
to print the details about files from stat
*/
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>

int main()
{
	char c;
	struct stat s;
	stat("06.c",&s);

	printf("Pick one among a to j\n");

	while(1)
	{
		printf("Please enter a character: ");
		scanf(" %c",&c);
	
		if(c=='a')
			printf("inode number %ld",(long)s.st_ino);
		else if(c=='b')
			printf("No of hard links %ld",(long)s.st_nlink);
		else if(c=='c')
			printf("UID %ld",(long)s.st_uid);
		else if(c=='d')
			printf("GID %ld",(long)s.st_gid);
		else if(c=='e')
			printf("Size %ld",(long)s.st_size);
		else if(c=='f')
			printf("Block size %ld",(long)s.st_blksize);
		else if(c=='g')
			printf("Number of blocks %lld",(long long)s.st_blocks);
		else if(c=='h')
			printf("Time of last access %s", ctime(&s.st_atime));
		else if(c=='i')
			printf("Time of last modification %s",ctime(&s.st_mtime));
		else if(c=='j')
			printf("Time of status change %s",ctime(&s.st_ctime));
		else
			break;
		printf("\n");

	}
	return 0;
}
