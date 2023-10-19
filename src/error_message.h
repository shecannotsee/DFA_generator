//
// Created by shecannotsee on 23-10-19.
//

#ifndef DFA_GENERATOR_ERROR_MESSAGE_H
#define DFA_GENERATOR_ERROR_MESSAGE_H

#include <exception>
#include <string>

class error_message : public std::exception {
 public:
  error_message(const char* message) : errorMessage(message) {}

  const char* what() const noexcept override {
    return errorMessage.c_str();
  }

 private:
  std::string errorMessage;
};

#endif //DFA_GENERATOR_ERROR_MESSAGE_H
