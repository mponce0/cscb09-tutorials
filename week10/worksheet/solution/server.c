#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// The port at which the server will be listening
#define PORT 50001

int main(int argc, char **argv)
{
  // The message you want to send to the server
  char *msg = "Hello client!\r\n";
  
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    perror("server: socket");
    exit(1);
  }
      
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(addr.sin_zero), 0, 8);

  if (bind(sock_fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_in)) == -1) {
    perror("server: bind");
    close(sock_fd);
    exit(1);
  }

  if (listen(sock_fd, 5) < 0) {
    perror("server: listen");
    close(sock_fd);
    exit(1);
  }

  struct sockaddr_in client_addr;
  client_addr.sin_family = AF_INET;
  unsigned int client_len = sizeof(struct sockaddr_in);

  int client_socket = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len);
  if (client_socket == -1) {
      perror("accept");
      return -1;
  }

  char buf[128];
  int len = read(client_socket, buf, 128);
  buf[len] = '\0';
  
  printf("%s\n", buf);

  write(client_socket, msg, strlen(msg));

  close(client_socket);
  close(sock_fd);
  
  return 0;
}