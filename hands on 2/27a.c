/*
MT2019114
Receive the msg from message queue will wait till message is received and once message is received it is deleted from message queue.
msgrcv(,,,,0)
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>         
#include <stdio.h>

struct msgbuf {
	long mtype;
	char mtext [1024];
};

int main(void){

	struct msgbuf buf;
	int ret,msgkey,msgqid;
	msgkey=ftok(".",'a');
	msgqid=msgget(msgkey,0);
	printf("Enter message type: ");
	scanf("%ld",&buf.mtype);
	ret=msgrcv(msgqid, &buf,sizeof(buf.mtext),buf.mtype, 0);
	printf("Message from queue: %s\n",buf.mtext);
	
	return 0;
}
