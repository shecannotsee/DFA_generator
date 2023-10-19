//
// Created by shecannotsee on 23-10-19.
//

#ifndef DFA_GENERATOR_T2__DATA_TREE__TEST_H
#define DFA_GENERATOR_T2__DATA_TREE__TEST_H

#define GTEST
#ifdef GTEST
#define private public
#define protected public
#endif


#include <scanning.h>
#include <data_tree.h>

TEST(data_tree, process_line) {
  auto lines = scanning::get_line(DFA_model);
  data_tree entity;
  for (const auto& line:lines) {
    entity.process_line(line);
  }

  ASSERT_EQ(     entity.get_state(entity.states_,0),"S1");
  ASSERT_EQ(entity.get_state_note(entity.states_,0),"Explanation of S1");
  ASSERT_EQ(     entity.get_state(entity.states_,1),"S2");
  ASSERT_EQ(entity.get_state_note(entity.states_,1),"Explanation of S2");
  ASSERT_EQ(     entity.get_state(entity.states_,2),"S3");
  ASSERT_EQ(entity.get_state_note(entity.states_,2),"Explanation of S3");

  ASSERT_EQ(entity.init_state_,"S1");

  ASSERT_EQ(entity.accept_state_,"S3");

  ASSERT_EQ(     entity.get_alphabet(entity.alphabet_,0),"Q1");
  ASSERT_EQ(entity.get_alphabet_real(entity.alphabet_,0),"'\\n'");
  ASSERT_EQ(     entity.get_alphabet(entity.alphabet_,1),"Q2");
  ASSERT_EQ(entity.get_alphabet_real(entity.alphabet_,1),"'\\\\'");
  ASSERT_EQ(     entity.get_alphabet(entity.alphabet_,2),"Q3");
  ASSERT_EQ(entity.get_alphabet_real(entity.alphabet_,2),"' '");
  ASSERT_EQ(     entity.get_alphabet(entity.alphabet_,3),"Q4");
  ASSERT_EQ(entity.get_alphabet_real(entity.alphabet_,3),"'other'");

  ASSERT_EQ(  entity.get_now_state(entity.transition_function_,0),"S1");// S1(Q1) > S3
  ASSERT_EQ(      entity.get_input(entity.transition_function_,0),"Q1");
  ASSERT_EQ(entity.get_later_state(entity.transition_function_,0),"S3");
  ASSERT_EQ(  entity.get_now_state(entity.transition_function_,1),"S1");// S1(Q2) > S2
  ASSERT_EQ(      entity.get_input(entity.transition_function_,1),"Q2");
  ASSERT_EQ(entity.get_later_state(entity.transition_function_,1),"S2");
  ASSERT_EQ(  entity.get_now_state(entity.transition_function_,2),"S1");// S1(Q3) > S1
  ASSERT_EQ(      entity.get_input(entity.transition_function_,2),"Q3");
  ASSERT_EQ(entity.get_later_state(entity.transition_function_,2),"S1");
  ASSERT_EQ(  entity.get_now_state(entity.transition_function_,3),"S1");// S1(Q4) > S1
  ASSERT_EQ(      entity.get_input(entity.transition_function_,3),"Q4");
  ASSERT_EQ(entity.get_later_state(entity.transition_function_,3),"S1");
  ASSERT_EQ(  entity.get_now_state(entity.transition_function_,4),"S2");// S2(Q1) > S1
  ASSERT_EQ(      entity.get_input(entity.transition_function_,4),"Q1");
  ASSERT_EQ(entity.get_later_state(entity.transition_function_,4),"S1");
  ASSERT_EQ(  entity.get_now_state(entity.transition_function_,5),"S2");// S2(Q2) > S1
  ASSERT_EQ(      entity.get_input(entity.transition_function_,5),"Q2");
  ASSERT_EQ(entity.get_later_state(entity.transition_function_,5),"S1");
  ASSERT_EQ(  entity.get_now_state(entity.transition_function_,6),"S2");// S2(Q3) > S2
  ASSERT_EQ(      entity.get_input(entity.transition_function_,6),"Q3");
  ASSERT_EQ(entity.get_later_state(entity.transition_function_,6),"S2");
  ASSERT_EQ(  entity.get_now_state(entity.transition_function_,7),"S2");// S2(Q4) > S1
  ASSERT_EQ(      entity.get_input(entity.transition_function_,7),"Q4");
  ASSERT_EQ(entity.get_later_state(entity.transition_function_,7),"S1");

}

#endif //DFA_GENERATOR_T2__DATA_TREE__TEST_H
