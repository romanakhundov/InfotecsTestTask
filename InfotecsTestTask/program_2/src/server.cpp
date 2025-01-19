#include <../server.h>

void Server::error(std::string&& msg) {
  std::cerr << msg << '\n';
  return;
}

Server::Server() {
  socket_ = socket(PF_INET, SOCK_STREAM, 0);
  if (socket_ <= 0) {
    error("ERROR socket creation failed\n");
    exit(1);
  }
  
  std::cout << "Socket creation completed\n";
  
  struct sockaddr_in si;
  si.sin_family = AF_INET;
  inet_pton(AF_INET, server_ip_.c_str(), &(si.sin_addr));
  si.sin_port = htons(port_);
  
  if (bind(socket_, (struct sockaddr*) &si, sizeof(si)) != 0 ){
    error("ERROR bind failed\n");
    close(socket_);
    exit(1);
  }
  
  std::cout << "Bind completed\n";
}


void Server::Run() {
  if (listen(socket_, 2) < 0) {
    error("ERROR listening failed\n");
    close(socket_);
    exit(1);
  }
  
  std::cout << "Server running...\n";
  
  int clientsd = accept(socket_, 0, 0);
  while (true) {
    if (clientsd <= 0) {
      error("ERROR accept failed\n");
      close(clientsd);
      close(socket_);
      exit(1);
    }
    
    char buffer[200];
    memset(buffer, 0, 200);
    if (read(clientsd, buffer, 199) <= 0) {
      close(clientsd);
      clientsd = accept(socket_, 0, 0);
    } else {
      std::string data(buffer);
      if (data.size() >= 2 && std::atoi(data.c_str()) % 32 == 0) {
        std::cout << "Data received\n";
      } else {
        error("ERROR data does not meet requirements\n");
      }
    }
  }
}
