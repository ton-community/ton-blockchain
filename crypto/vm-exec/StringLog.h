//
// Created by Narek Abovyan on 22.02.2022.
//


#ifndef TON_STRINGLOG_H
#define TON_STRINGLOG_H

#include <thread>


class StringLog : public td::LogInterface {
 public:
  StringLog() {
  }

  void append(td::CSlice new_slice, int log_level) override {
    lock.lock();
    this->str.append(new_slice.str());
    lock.unlock();
  }

  void rotate() override {
  }

  void clear() {
    this->str.clear();
  }

  std::string get_string() const {
    return this->str;
  }

 private:
  std::string str;
  std::mutex lock;
};

#endif  //TON_STRINGLOG_H
