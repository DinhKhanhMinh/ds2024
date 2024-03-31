#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fstream>
#include <cstring>

#define SIZE 900000 // size of buffer 

void write_file(int sockfd){
  int n;
  std::ofstream fp;
  std::string filename = "recieve.txt";
  std::cout << "File recieving: " << filename << std::endl;
  char buffer[SIZE];

  fp.open(filename);
  while (1) {
    n = recv(sockfd, buffer, SIZE, 0);
    if (n <= 0){
      break;
      return;
    }
    fp << buffer;
    std::memset(buffer, 0, SIZE);
  }
  return;
}

int main() // main function
{
  std::string ip = "127.0.0.1";
  int port = 8080; // port number
  int e;

  int sockfd, new_sock;
  struct sockaddr_in server_addr, new_addr;
  socklen_t addr_size;
  char buffer[SIZE];

  sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
  if(sockfd < 0) {
    perror("[-]Socket error."); 
    exit(1);
  }
  std::cout << "[+]Successfully created server socket.\n";

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

  e = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)); // bind the socket
  if(e < 0) {
    perror("[-]Bind error.");
    exit(1);
  }
  std::cout << "[+]Binding successful.\n";

  if(listen(sockfd, 10) == 0){ // listen for connection
    std::cout << "[+]Listening....\n";
  }else{
    perror("[-]Listening error.");
    exit(1);
  }

  addr_size = sizeof(new_addr); // accept the connection
  new_sock = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);
  write_file(new_sock);
  std::cout << "[+]Data written in the file successfully.\n";

  return 0;
}