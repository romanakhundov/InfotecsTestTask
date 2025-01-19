#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <thread>
#include <string>
#include <sys/socket.h>


class Server {
  public:
    Server();
    void Run();
    
  private:
    void error(std::string&& msg);
    void RecieveData();
    
    std::string server_ip_ = "127.0.0.1";
    int port_ = 8080;
    int socket_ = 0;
};

#endif //SERVER_H
