//
// Created by shecannotsee on 23-10-19.
//

#include "data_tree.h"

void data_tree::process_line(std::string one_line) {
  if(one_line=="States") {
    now_state_ = five_tuples::state;
  }
  else if(one_line=="Initial_State") {
    now_state_ = five_tuples::init;
  }
  else if(one_line=="Accept_States") {
    now_state_ = five_tuples::accept;
  }
  else if(one_line=="Alphabet") {
    now_state_ = five_tuples::alphabet;
  }
  else if(one_line=="Transition_Function") {
    now_state_ = five_tuples::tf;
  }
  else {
    if (now_state_ == five_tuples::just_init)
      throw error_message("error file content");
    else {
      switch (static_cast<int>(now_state_)) {
        case static_cast<int>(five_tuples::state):
          this->process_states(one_line);break;
        case static_cast<int>(five_tuples::init):
          this->process_init_state(one_line);break;
        case static_cast<int>(five_tuples::accept):
          this->process_accept_state(one_line);break;
        case static_cast<int>(five_tuples::alphabet):
          this->process_alphabet(one_line);break;
        case static_cast<int>(five_tuples::tf):
          this->process_transition_function(one_line);break;
        default:
          throw error_message("error branch");
      }
    }
  }

}

void data_tree::process_states(std::string one_line) {

}

void data_tree::process_init_state(std::string one_line) {

}

void data_tree::process_accept_state(std::string one_line) {

}

void data_tree::process_alphabet(std::string one_line) {

}

void data_tree::process_transition_function(std::string one_line) {

}
