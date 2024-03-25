#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <iostream>
#include <fstream>
#include <cstring>
#include <arpa/inet.h>
#define SIZE 99999

void send_file(std::ifstream& fp, int sockfd){
  int n;
  char data[SIZE] = {0};

  while(fp.getline(data, SIZE)) {
    if (send(sockfd, data, sizeof(data), 0) == -1) {
      perror("[-]File sending error.");
      exit(1);
    }
    std::memset(data, 0, SIZE);
  }
}

int main(){
  std::string ip = "127.0.0.1";
  int port = 8080;
  int e;

  int sockfd;
  struct sockaddr_in server_addr;
  std::ifstream fp;
  std::string filename;
  std::cout << "Enter filename to send: ";
  std::getline(std::cin, filename);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("[-]Socket error.");
    exit(1);
  }
  std::cout << "[+]Successfully created server socket.\n";

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

  e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(e == -1) {
    perror("[-]Socket error");
    exit(1);
  }
  std::cout << "[+]Connected to Server.\n";
  std::cout << "Name of the file to send: ";
  std::getline(std::cin, filename);
  fp.open(filename);
  if (!fp) {
    perror("[-]File reading error.");
    exit(1);
  }

  send_file(fp, sockfd);
  std::cout << "[+]Successfully sent file data.\n";

  std::cout << "[+]Closing connection...\n";
  close(sockfd);

  return 0;