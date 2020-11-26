/*
MT2019114
Creating message queue and printing infomration about message queues
*/

#include <fcntl.h>
#include <unistd.h>          
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

struct ipc_perm msg_perm;
struct msqid_ds mds;

int main(void){

	key_t msgkey;
	int msgqid;
	
	msgkey=ftok(".",'a');
	msgqid=msgget(msgkey,0);
	msgctl(msgqid,IPC_STAT,&mds); //ipc_stat for statistics
	
	printf("Permission: %03o\n",mds.msg_perm.mode & 0777);
	printf("UID: %d\n",msg_perm.uid);
	printf("GID: %d\n",msg_perm.gid);
	printf("Last time message was sent: %s\n",ctime(&mds.msg_stime));
	printf("Last time message was recieved: %s\n",ctime(&mds.msg_rtime));
	printf("Last time of change in queue: %s\n",ctime(&mds.msg_ctime));
	//printf("Size of queue: \n",  ); //========LEFT=============
	printf("Number of messages in queue: %lu\n",mds.msg_qnum);
	printf("Max number of bytes allowed in queue: %lu\n",mds.msg_qbytes);
	printf("Pid of last message that was sent: %d\n",mds.msg_lspid);
	printf("Pid of last message that was recieved: %d\n",mds.msg_lrpid);
	
	return 0;
}
