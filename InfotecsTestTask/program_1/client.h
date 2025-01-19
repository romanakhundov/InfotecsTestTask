#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>


class Client {

public:
  Client() = default;
  void SendData(int sum);

private:
  void error(std::string&& msg);
  
  std::string server_ip_ = "127.0.0.1";
  int port_ = 8080;
  int socket_ = 0;
  
};


#endif //CLIENT_H
