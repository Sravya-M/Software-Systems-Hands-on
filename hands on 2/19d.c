/*
MT2019114
mkfifo using system call
*/
#include <string.h> 
#include <fcntl.h>           
#include <sys/stat.h>
  
int main() 
{ 
    char * myfifo = "myfifo";  
    mkfifo(myfifo, 0666);  
} 
