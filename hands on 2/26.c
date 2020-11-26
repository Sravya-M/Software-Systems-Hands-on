/*
MT2019114
Sending message to message queue.
msgsnd()
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>

int main(void){

	int msgqid, size;
	key_t msgkey;
	struct msg{
		long int mtype;
		char message[80];
	}ms;

  	msgkey = ftok(".",'a');
  	msgqid = msgget(msgkey,0);
	printf("Enter the message type: ");
	scanf("%ld", &ms.mtype);
	printf("Enter the message text: ");
	scanf(" %[^\n]", ms.message);
	size = strlen(ms.message);
	msgsnd(msgqid,&ms, size+1,0);

 	return 0;
}
