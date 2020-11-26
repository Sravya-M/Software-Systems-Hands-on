/* MT2019114
	finding the time taken by getpid()
*/
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/time.h>
#include<time.h>

static __inline__ unsigned long long rdtsc()
{
    unsigned long long int x;
    __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
    return x;
}

int main () {
    int nsec;
    unsigned long long int stime, etime;
    stime = rdtsc();
      getpid();
    etime = rdtsc();
    nsec = (etime-stime)/1.8;

    printf("Difference using time stamp counter is : %d nsec \n", nsec);
    return 0;
}
