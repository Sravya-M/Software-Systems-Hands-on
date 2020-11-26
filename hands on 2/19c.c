/*
MT2019114
fifo using mknod system call
*/

#include <sys/types.h>       
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	mknod("fifo1",O_EXCL| 0744,0);
	return 0;
}
