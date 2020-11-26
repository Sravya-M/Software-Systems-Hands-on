/* MT2019114
pass input to an executable file
just printing all the command line arguments
*/

#include<stdio.h>

int main(int argc, char **argv)
{
	for(int fo=0;fo<argc;fo++)
		printf("%s\n",argv[fo]);

	return 0;
}
