#include "../data_receiver.h"

bool DataReceiver::Checker() const {
  if (data_.length() > 64) {
    return false;
  }
  for (char ch : data_) {
    if (!(ch >= '0' && ch <= '9')) {
      return false;
    }
  }
  return true;
}

void DataReceiver::DataProcessing() {
  std::string processed_data;
  for (char ch : data_) {
    if (ch % 2 == 0) {
      processed_data += "KB";
    } else {
      processed_data += ch;
    }
  }
  std::sort(processed_data.rbegin(), processed_data.rend());
  data_ = std::move(processed_data);
}

void DataReceiver::Input (Buffer &buffer) {
  std::cout << "Enter data: \n";
  while (true) {
    std::cin >> data_;
    if (this->Checker()) {
      this->DataProcessing();

      std::mutex mut;
      std::lock_guard lg(mut);
      buffer.data = std::move(data_);
      buffer.update_data = true;
      buffer.cv.notify_one();
    }
  }
}
