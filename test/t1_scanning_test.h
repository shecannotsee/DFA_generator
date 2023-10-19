//
// Created by shecannotsee on 23-10-19.
//

#ifndef DFA_GENERATOR_T1_SCANNING_TEST_H
#define DFA_GENERATOR_T1_SCANNING_TEST_H

#include <scanning.h>

TEST(scanning,get_line) {
  auto lines = scanning::get_line("../resource/DFA_model");
  ASSERT_EQ(lines[0],"States");

  States
  S1 : Explanation of S1
  S2 : Explanation of S2
  S3 : Explanation of S3

  Initial_State
    S1

  Accept_States
    S3

  Alphabet
  Q1 : '\n'
  Q2 : '\\'
  Q3 : ' '
  Q4 : ' '


  Transition_Function
  S1(Q1) > S3
  S1(Q2) > S2
  S1(Q3) > S1
  S1(Q4) > S1
  S2(Q1) > S1
  S2(Q2) > S1
  S2(Q3) > S2
  S2(Q4) > S1
}

#endif //DFA_GENERATOR_T1_SCANNING_TEST_H
