#ifndef BUFFER_H
#define BUFFER_H

#include <condition_variable>
#include <string>

struct Buffer {
  std::string data;
  bool update_data = false;
  std::condition_variable cv;
};

#endif //BUFFER_H
