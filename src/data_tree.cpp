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

std::string data_tree::generate() {
  std::string content;
  /* states */ {
    std::string temp;
    temp += "/********** States ***************************************************************************************"
            "*************/\n";
    temp += "enum class states : int {\n";
    // enum class value
    for (int i = 0; i < states_.size(); ++i) {
      temp += "  " + data_tree::get_state(states_,i) + ",";
      temp += "// " + data_tree::get_state_note(states_,i);
      temp += "\n";
    }

    temp += "  REFUSE// refuse str\n";

    temp += "};\n\n";
    content += temp;
  }
  /* init state */ {
    std::string temp;
    temp += "/********** init state ***********************************************************************************"
            "*************/\n";
    temp += "constexpr states start_state = states::";
    temp += init_state_ + ";\n\n";
    content += temp;
  }
  /* accept state */ {
    std::string temp;
    temp += "/********** accept state *********************************************************************************"
            "*************/\n";
    temp += "constexpr states accept_state = states::";
    temp += accept_state_ + ";\n\n";
    content += temp;
  }
  /* alphabet */ {
    std::string temp;
    temp += "/********** alphabet *************************************************************************************"
            "*************/\n";
    temp += "enum class alphabet : int {\n";
    // enum class value
    for (int i = 0; i < alphabet_.size(); ++i) {
      temp += "  {" + data_tree::get_alphabet_real(alphabet_, i) +
              ", alphabet::" + data_tree::get_alphabet(alphabet_, i) + "}";

      if (i!= (alphabet_.size()-1)) {
        temp += ",\n";
      } else {
        temp += "\n";
      }
    }

    temp += "};\n\n";
    content += temp;

    content += "// convert Character to State\n"
               "template<typename char_type>\n"
               "alphabet get_alphabet(char_type input) {\n"
               "  if (cher_table.find(input) != cher_table.end()) {\n"
               "    return cher_table[input];\n"
               "  } else {\n"
               "    return alphabet::??;\n"
               "  }\n"
               "}\n\n";
  }
  /*  Transition Function */ {
    std::string temp;
    temp += "/********** Transition Function **************************************************************************"
            "*************/\n";
    temp += "static std::unordered_map<std::tuple<int,int>,states> transfer_function = {\n";
    for (int i = 0; i < transition_function_.size(); ++i) {
      std::string _1 = data_tree::get_now_state(transition_function_,i);
      std::string _2 = data_tree::get_input(transition_function_,i);
      std::string _3 = data_tree::get_later_state(transition_function_,i);
      temp += "  {{static_cast<int>(states::" + _1 +
              "),static_cast<int>(alphabet::" + _2 +
              ")},/* -> */states::" + _3 + "}";
      if (i!= (transition_function_.size()-1)) {
        temp += ",";
      }
      temp += "\n";
    }

    temp += "}\n\n";
    temp += "template<typename char_type>\n"
            "states transition_status(states now, char_type input) {\n"
            "  int input_S = static_cast<int>(now);\n"
            "  int input_Q = static_cast<int>(get_alphabet(input));\n"
            "  auto key = std::make_tuple(input_S,input_Q);\n"
            "  if(transfer_function.find(key)!= transfer_function.end())\n"
            "    return transfer_function[key];\n"
            "  else {\n"
            "    return states::REFUSE;\n"
            "  }\n"
            "}\n\n";
    content += temp;
  }
  /* Processing of other modules */ {
    std::string define_;
    define_ += "#ifndef DFA_MODEL_H\n";
    define_ += "#define DFA_MODEL_H\n\n";
    define_ += "#include <tuple>\n";
    define_ += "#include <unordered_map>\n\n";
    define_ += "// Provide custom hashes to <>\n"
               "namespace std {\n"
               "template<>\n"
               "struct hash<std::tuple<int, int>> {\n"
               "  std::size_t operator()(const std::tuple<int, int> &key) const {\n"
               "    using std::hash;\n"
               "    // Combine the hash values of the two enum values to create a unique hash\n"
               "    return hash<int>()(static_cast<int>(std::get<0>(key))) ^ hash<int>()(static_cast<int>(std::get<1>(key)));\n"
               "  }\n"
               "};\n"
               "}// namespace std\n\n";
    define_ += "namespace DFA_model {\n\n";
    content = define_ + content;
    content += "}// namespace DFA_model \n\n";
    content += "#endif // DFA_MODEL_H\n\n";
  }
  return content;
}
