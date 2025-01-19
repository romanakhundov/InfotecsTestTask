#include "../data_processing.h"

int DataProcessing::DigitsSum(std::string& buffer) const {
  int ans = 0;
  for (char ch : buffer) {
    if (ch >= '0' && ch <= '9') {
      ans += static_cast<int>(ch) - '0';
    }
  }
  return ans;
}

void DataProcessing::Output(Buffer& buffer, Client& client) const {
  while(true) {
    std::mutex m;
    std::unique_lock ul(m);
    buffer.cv.wait(ul,
      [&buffer] { return buffer.update_data; });

    std::string data = std::move(buffer.data);
    buffer.update_data = false;

    int sum = this->DigitsSum(data);
    std::cout << "Sum of digits: " << sum << '\n';
    
    std::thread send_data(&Client::SendData, &client, sum);
    send_data.detach();
  }
}



