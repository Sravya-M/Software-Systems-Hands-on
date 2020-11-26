// MT2019114

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/time.h>
#include<stdlib.h>
#include<sys/resource.h>
#include <string.h>

void handler(){
    printf("catched SIGFPE\n");
    exit(1);
}
int main(){
    
    if(signal(SIGFPE, handler) == SIG_ERR)
		printf("error while catching SIGFPE\n");

    int x = 0;
    int y = 1/x;
    return 0;
}
