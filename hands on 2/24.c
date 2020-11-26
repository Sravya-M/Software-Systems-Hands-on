/*
MT2019114
Creating message queue using msgget and msgkey and then printing the values of msgkey and msgqid
*/

#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(void){

  int msgqid;
  key_t msgkey;
  msgkey = ftok(".",'a');
  msgqid = msgget(msgkey, IPC_CREAT | IPC_EXCL|0744);
  printf("key value is: %d \n", msgkey);
  printf("key value in hex is: 0x%0x \n",msgkey);
  printf("Mesage queue id is: %d\n",msgqid);

  return 0;
}
