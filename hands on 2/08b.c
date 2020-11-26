/* MT2019114
 * 8. Write a separate program using signal system call to catch the following signals.
 * b. SIGINT
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void signalhandler(int signum)
{
    printf("Process %d received signal %d\n", getpid(), signum);
    signal(signum, SIG_DFL);
    kill(getpid(), signum);
}

int main()
{
    signal(SIGINT, signalhandler);
    printf("Type ctrl+c\n");
    sleep(1000);

    return 0;
}
