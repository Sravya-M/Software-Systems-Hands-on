/*
MT2019114
Remove the message queue using msgctl().
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>         
#include <stdio.h>

int main(void){

	int msgkey,msgqid;
	msgkey=ftok(".",'a');
	msgqid=msgget(msgkey,0);
	msgctl(msgqid, IPC_RMID, NULL);
}


