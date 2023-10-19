//
// Created by shecannotsee on 23-10-19.
//

#ifndef DFA_GENERATOR_DATA_TREE_H
#define DFA_GENERATOR_DATA_TREE_H

#include <string>
#include <tuple>
#include <vector>

#include <error_message.h>

enum class five_tuples : int {
  just_init,
  state,    //
  init,     //
  accept,   //
  alphabet, //
  tf,       // Transition_Function
};

class data_tree {
 public:
  data_tree() = default;
 private:
  using double_tuples = std::vector<std::tuple<std::string,std::string>>;
  using third_tuples = std::vector<std::tuple<std::string,std::string,std::string>>;

  double_tuples states_;
  static std::string get_state(double_tuples _, int _index) {
    return std::get<0>(_[_index]);
  }
  static std::string get_state_note(double_tuples _, int _index) {
    return std::get<1>(_[_index]);
  }
  std::string init_state_;
  std::string accept_state_;
  double_tuples alphabet_;
  static std::string get_alphabet(double_tuples _, int _index) {
    return std::get<0>(_[_index]);
  }
  static std::string get_alphabet_real(double_tuples _, int _index) {
    return std::get<1>(_[_index]);
  }
  third_tuples transition_function_;
  static std::string get_now_state(third_tuples _, int _index) {
    return std::get<0>(_[_index]);
  }
  static std::string get_input(third_tuples _, int _index) {
    return std::get<1>(_[_index]);
  }
  static std::string get_later_state(third_tuples _, int _index) {
    return std::get<2>(_[_index]);
  }


  five_tuples now_state_ = five_tuples::just_init;

 private:
  void process_states(const std::string& one_line);
  void process_init_state(const std::string& one_line);
  void process_accept_state(const std::string& one_line);
  void process_alphabet(const std::string& one_line);
  void process_transition_function(const std::string& one_line);

 public:
  void process_line(std::string one_line);

 public:
  std::string generate();
};


#endif //DFA_GENERATOR_DATA_TREE_H
