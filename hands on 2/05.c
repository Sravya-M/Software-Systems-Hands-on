/*
MT2019114
program to print system limitation
*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Maximum length of the arguments to the exec family of functions %ld\n", sysconf(_SC_ARG_MAX));
    printf("Maximum number of simultaneous process per user id: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Number of clock ticks (jiffy) per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Maximum number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Size of a page: %ldB\n", sysconf(_SC_PAGESIZE));
    printf("Total number of pages in the physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("Number of currently available pages in the physical memory: %ld\n", sysconf(_SC_AVPHYS_PAGES));
    return 0;
}
