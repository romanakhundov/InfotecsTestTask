#include "../data_processing.h"
#include "../data_receiver.h"
#include "../buffer.h"

int main() {
  Buffer buffer;
  DataProcessing data_processing;
  DataReceiver data_receiver;
  Client client;

  std::thread input(&DataReceiver::Input, &data_receiver, std::ref(buffer));
  std::thread output(&DataProcessing::Otput, &data_processing, std::ref(buffer), std::ref(client));

  input.join();
  output.join();
}
