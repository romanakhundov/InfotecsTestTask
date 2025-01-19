#include "../client.h"

void Client::error(std::string&& msg) {
  std::cerr << msg << '\n';
  return;
}

void Client::SendData(int sum) {
  socket_ = socket(PF_INET, SOCK_STREAM, 0);
  if (socket_ <= 0) {
    error("ERROR socket creation failed\n");
    return;
  } 
  
  std::cout << "Socket creation completed\n";
  
  struct sockaddr_in si;
  si.sin_family = AF_INET;
  inet_pton(AF_INET, server_ip_.c_str(), &(si.sin_addr));
  si.sin_port = htons(port_);
  
  if(connect(socket_, (struct sockaddr*) &si, sizeof(si)) < 0) {
    close(socket_);
    error("ERROR connection failed\n");
    return;
  } 
  std::cout << "Connection completed\n";
  
  
  std::string sum_to_str = std::to_string(sum);
  if (send(socket_, sum_to_str.c_str(), sum_to_str.size(), 0) == -1) {
    close(socket_);
    error("ERROR sending failed\n");
    return;
  }
  
  std::cout << "Sending completed\n";
  close(socket_);
}
