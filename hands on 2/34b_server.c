/*
MT2019114
Server side: concurrent server using pthread
socket->bind->listen->accept->recv/send->close
*/
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h> 
   
void *socketThread(void *);

int main(void) {
 
    int socket_desc, client_sock, c, *new_sock; 
    struct sockaddr_in server, client; 
    char buf[100]; 
  
    socket_desc = socket(AF_INET, SOCK_STREAM, 0); 
    if (socket_desc == -1) { 
        printf("Could not create socket"); 
    } 
  
    server.sin_family = AF_INET; 
    server.sin_addr.s_addr = INADDR_ANY; 
    server.sin_port = htons(8880); 
   
    if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) 
        perror("bind failed. Error"); 
   
 
    listen(socket_desc, 3);  
    c = sizeof(struct sockaddr_in); 
  
    while (client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c)){

	    pthread_t mythread;
	    new_sock = malloc(sizeof *new_sock);
           *new_sock = client_sock;
	  
	    if( pthread_create(&mythread, NULL, socketThread, (void*) new_sock) != 0 )
           	printf("Failed to create thread\n");
	    
    }
    return 0; 
} 
 
void *socketThread(void *socket_desc){
	int client_sock = *(int*)socket_desc;
    	char client_message[2000];

    //Receive a message from client
	    while( (recv(client_sock , client_message , 2000 , 0)) > 0 )
	    {
		 //Send the message back to client
		 send(client_sock,"hello client.\n",strlen("hello client.\n"),0);
		 printf("Message from Client: %s\n",client_message);
	    }
	
	free(socket_desc);
   	close(client_sock);
    	pthread_exit(NULL); 
}
