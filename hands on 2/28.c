/*
MT2019114
Changing the message queue permission using msg_perm mode variable.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>         
#include <stdio.h>


struct ipc_perm msg_perm;
struct msqid_ds mds;

int main()
{
	key_t msgkey;
	int msgqid;
	
	msgkey=ftok(".",'a');
	msgqid=msgget(msgkey,0);
	msgctl(msgqid,IPC_STAT,&mds); //ipc_stat for statistics
	printf("Current Permission: %03o\n",mds.msg_perm.mode & 0777);
	mds.msg_perm.mode=0666;
	printf("Updated Permission: %03o\n",mds.msg_perm.mode & 0777);
}
