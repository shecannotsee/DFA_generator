// application.cpp
#include <iostream>
#include <data_tree.h>
#include "scanning.h"

int main(int argc, char* argv[]) {
  std::cout << "\033[32m" << "application start" << "\033[0m" << std::endl;

  if (argc==2) {
    auto lines = scanning::get_line(argv[1]);
    data_tree entity;
    for (const auto& line:lines) {
      entity.process_line(line);
    }

    std::cout << entity.generate();
  } else {
    throw error_message("error input");
  }

  std::cout << "\033[32m" << "application done" << "\033[0m" << std::endl;
  return 0;
}
