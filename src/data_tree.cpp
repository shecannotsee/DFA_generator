//
// Created by shecannotsee on 23-10-19.
//

#include "data_tree.h"

void data_tree::process_line(std::string one_line) {
  if (one_line.empty()) return;
  if (one_line == "\n") return;
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

void data_tree::process_states(const std::string& one_line) {
  std::string state;
  std::string note;
  int point = 0;// 0 means write to state, 1means write to note
  for (auto c : one_line) {
    if(c==':') {
      point = 1;
    } else if (c==' ') {
      if(point==1&&!note.empty()) {
        note.push_back(c);
      }
      continue;
    } else {
      if (point==0)
        state.push_back(c);
      else {
        note.push_back(c);
      }
    }
  }
  states_.emplace_back(state,note);
}

void data_tree::process_init_state(const std::string& one_line) {
  std::string _;
  for (auto c: one_line) {
    if (c!=' ') {
      _.push_back(c);
    }
  }
  init_state_ = _;
}

void data_tree::process_accept_state(const std::string& one_line) {
  std::string _;
  for (auto c: one_line) {
    if (c!=' ') {
      _.push_back(c);
    }
  }
  accept_state_ = _;
}

void data_tree::process_alphabet(const std::string& one_line) {
  std::string alphabet;
  std::string real;
  int point = 0;// 0 means write to alphabet, 1means write to real
  for (auto c : one_line) {
    if(c==':') {
      point = 1;
    } else if (c==' ') {
      if(point==1&&!real.empty()) {
        real.push_back(c);
      }
      continue;
    } else {
      if (point==0)
        alphabet.push_back(c);
      else {
        real.push_back(c);
      }
    }
  }
  alphabet_.emplace_back(alphabet,real);
}

void data_tree::process_transition_function(const std::string& one_line) {
  std::string old_state;
  std::string input;
  std::string new_state;
  int point = 0;// 0 means write to old_state, 1 means write to input, 2 means write to new_state
  for (auto c : one_line) {
    if (c=='>'||c==')') {
      point = 2;
    } else if (c=='(') {
      point = 1;
    } else if (c==' ') {

    } else {
      if (point==0)
        old_state.push_back(c);
      else if (point==1)
        input.push_back(c);
      else
        new_state.push_back(c);
    }
  }

  transition_function_.emplace_back(old_state, input, new_state);
}
