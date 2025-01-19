#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#include "buffer.h"
#include "client.h"
#include <thread>


class DataProcessing {
public:
  DataProcessing() = default;
  void Output(Buffer& buffer, Client& client) const;

private:
  int DigitsSum(std::string& buffer) const;
};
#endif //DATA_PROCESSING_H
