//
// Created by shecannotsee on 23-10-19.
//

#ifndef DFA_GENERATOR_SCANNING_H
#define DFA_GENERATOR_SCANNING_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

namespace scanning {

std::vector<std::string> get_line(std::string file_name) {
  std::vector<std::string> ret{};
  std::ifstream inputFile(file_name); // 替换为您要读取的文件名

  if (!inputFile) {
    throw std::exception();
  }

  std::string line;
  while (std::getline(inputFile, line)) {
    ret.emplace_back(std::string(line));
  }

  inputFile.close(); // 关闭文件
  return ret;
}

}// namespace scanning

#endif //DFA_GENERATOR_SCANNING_H
