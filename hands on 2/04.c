/*
MT2019114
using time stamp counter calculating total time to execute getppid() 100 times.
rdtsc will return clock cycles, divide by frequency to get time
*/

#include <stdio.h>
#include <unistd.h>

static __inline__ unsigned long long rdtsc(void)
{
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

int main(){
  unsigned long long start, end, total;
  start = rdtsc();
  for(int i=0;i<100;i++){
  	getppid();
  }
  end = rdtsc();
  total = (end-start)/2.5;
  printf("Time in nano seconds %llu\n",total);
}
