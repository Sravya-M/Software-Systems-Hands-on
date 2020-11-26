/*
MT2019114
Client side:
socket->connect->send/recv->close
*/

#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <stdio.h> 
 
int main(int argc, char* argv[]) 
{ 
    int sock; 
    struct sockaddr_in server; 
    char server_reply[50]; 
     
    sock = socket(AF_INET, SOCK_STREAM, 0); 
    if (sock == -1) { 
        printf("Could not create socket"); 
    } 
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    server.sin_family = AF_INET; 
    server.sin_port = htons(8880); 
   
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
        perror("connect failed. Error"); 
    
    if (send(sock,"hello server.\n",strlen("hello server.\n"),0) < 0)  
        printf("Send failed"); 
 
    if (recv(sock, &server_reply, sizeof(server_reply), 0) < 0) 
        printf("recv failed");  
    
    printf("Message from Server: %s\n",server_reply);
    close(sock); 
    return 0; 
} 
