//
// Created by shecannotsee on 23-10-19.
//

#ifndef DFA_GENERATOR_T1_SCANNING_TEST_H
#define DFA_GENERATOR_T1_SCANNING_TEST_H

#include <scanning.h>

TEST(scanning,get_line) {
  auto lines = scanning::get_line("../resource/DFA_model.dfa");
  ASSERT_EQ(lines[0], "States");
  ASSERT_EQ(lines[1], "S1 : Explanation of S1");
  ASSERT_EQ(lines[2], "S2 : Explanation of S2");
  ASSERT_EQ(lines[3], "S3 : Explanation of S3");
  ASSERT_EQ(lines[4], "");
  ASSERT_EQ(lines[5], "Initial_State");
  ASSERT_EQ(lines[6], "S1");
  ASSERT_EQ(lines[7], "");
  ASSERT_EQ(lines[8], "Accept_States");
  ASSERT_EQ(lines[9], "S3");
  ASSERT_EQ(lines[10], "");
  ASSERT_EQ(lines[11],"Alphabet");
  ASSERT_EQ(lines[12],"Q1 : '\\n'");
  ASSERT_EQ(lines[13],"Q2 : '\\\\'");
  ASSERT_EQ(lines[14],"Q3 : ' '");
  ASSERT_EQ(lines[15],"Q4 : 'other'");
  ASSERT_EQ(lines[16],"");
  ASSERT_EQ(lines[17],"Transition_Function");
  ASSERT_EQ(lines[18],"S1(Q1) > S3");
  ASSERT_EQ(lines[19],"S1(Q2) > S2");
  ASSERT_EQ(lines[20],"S1(Q3) > S1");
  ASSERT_EQ(lines[21],"S1(Q4) > S1");
  ASSERT_EQ(lines[22],"S2(Q1) > S1");
  ASSERT_EQ(lines[23],"S2(Q2) > S1");
  ASSERT_EQ(lines[24],"S2(Q3) > S2");
  ASSERT_EQ(lines[25],"S2(Q4) > S1");
  ASSERT_EQ(lines[26],"");
}

#endif //DFA_GENERATOR_T1_SCANNING_TEST_H
