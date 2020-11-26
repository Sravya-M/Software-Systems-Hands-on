/*
MT2019114
Server side: concurrent server using fork()
socket->bind->listen->accept->recv/send->close
*/
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <stdio.h> 
#include <stdlib.h> 
   
int main(void) {
 
    int socket_desc, client_sock, c; 
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
  
    while (1){

	    client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c); 
	  
	    if (!fork()){
		    close(socket_desc);
		    recv(client_sock, &buf, sizeof(buf), 0);
		    printf("Message from client: %s\n",buf);
		    send(client_sock,"hello client.\n",strlen("hello client.\n"),0);
		    exit(0);
	    }
	    else
	    	close(client_sock);
    }
    return 0; 
} 
  

