/* MT2019114
make it an orphan process
create a new sesson for it
give full permissions
executed as background
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
        
// Our process ID and Session ID
        pid_t pid, sid;
        
        pid = fork();
        if (pid < 0)
                exit(0);

// If we got a good PID, then we can exit the parent process.
        if (pid > 0) {
		printf("child id is %d\n",pid);
                exit(0);
        }

// changing the file mode mask
        umask(0);    
                
// Create a new SID for the child process
        sid = setsid();
        if (sid < 0)
                exit(0);
        
	//chdir("/")
      
// closing standard fds
        close(0);
        close(1);
        close(2);
        
// Daemon-specific initialization goes here 
        
	int fd=open("30test.txt",O_CREAT|O_RDWR|O_TRUNC,0777);
        while (1) {
	           sleep(4);
		write(fd,"process run by daemon\n",strlen("process run by daemon\n"));
        }
	close(fd);

   	exit(0);
}
