#ifndef DATA_RECEIVER_H
#define DATA_RECEIVER_H

#include <string>
#include "buffer.h"
#include <iostream>
#include <algorithm>
#include <mutex>

class DataReceiver {
public:
  DataReceiver() = default;
  void Input(Buffer& buffer);

private:
  bool Checker() const;
  void DataProcessing();
  std::string data_;
};
#endif //DATA_RECEIVER_H
