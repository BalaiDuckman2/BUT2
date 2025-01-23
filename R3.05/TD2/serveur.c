#include <stdio.h>            
#include <stdlib.h>          
#include <string.h>           
#include <unistd.h>         
#include <arpa/inet.h>        
#include <netinet/in.h>      
#include <sys/types.h>        
#include <sys/socket.h>       
int main(){
int sock;
int ret;
struct sockaddr_in addr;
int size;
int cnx;
struct sockaddr_in conn_addr;
size = sizeof(conn_addr);
cnx = accept(sock, (struct sockaddr *)&conn_addr, (socklen_t *)&size);

sock = socket(AF_INET, SOCK_STREAM, 0);
addr.sin_addr.s_addr = inet_addr("127.0.0.1");
addr.sin_family = AF_INET;
addr.sin_port = htons(8080);
ret = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
ret = listen(sock, 1);
}