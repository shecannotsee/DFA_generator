//
// Created by shecannotsee on 23-10-19.
//

#ifndef DFA_GENERATOR_T2__DATA_TREE__TEST_H
#define DFA_GENERATOR_T2__DATA_TREE__TEST_H

#include <scanning.h>
#include <data_tree.h>

TEST(data_tree, process_line) {
  auto lines = scanning::get_line(DFA_model);
  data_tree entity;
  for (const auto& line:lines) {
    entity.process_line(line);
  }

}

#endif //DFA_GENERATOR_T2__DATA_TREE__TEST_H
