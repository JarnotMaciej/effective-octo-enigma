//
// Created by Menox on 25.04.2023.
//

// Google Test
#include <gtest/gtest.h>

// C++
#include <vector>

// header files
#include "../functions.h"

class NameValidationTest : public ::testing::TestWithParam<std::pair<std::string, bool>> {};

TEST_P(NameValidationTest, NameValidation) {
  std::string name = GetParam().first;
  bool expected = GetParam().second;
  ASSERT_EQ(nameValidation(name), expected);
}

INSTANTIATE_TEST_SUITE_P(Names, NameValidationTest,
                         ::testing::Values(
                             std::make_pair("JanuszTracz", true),
                             std::make_pair("JanuszTracz123", false),
                             std::make_pair("123JanuszTracz", false),
                             std::make_pair("JanuszTracz!@#", false),
                             std::make_pair("JanuszTracz$%^", false),
                             std::make_pair("", false),
                             std::make_pair("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", false),
                             std::make_pair("JanuszTracz&*()", false)));

class DeadTamagotchiValidationTest : public ::testing::TestWithParam<std::pair<std::string, bool>> {};

TEST_P(DeadTamagotchiValidationTest, DeadTamagotchiValidation) {
  std::string name = GetParam().first;
  bool expected = GetParam().second;
  ASSERT_EQ(deadTamagotchiValidation(name), expected);
}

INSTANTIATE_TEST_SUITE_P(Names, DeadTamagotchiValidationTest,
                         ::testing::Values(
                             std::make_pair("JanuszTracz.dtf", true),
                             std::make_pair("JanuszTracz123.txt", false),
                             std::make_pair("123JanuszTracz", false),
                             std::make_pair("JanuszTracz", false),
                             std::make_pair(".dtf", false),
                             std::make_pair("maciusPL.dtf", true),
                             std::make_pair("JanuszTracz!@#", false),
                             std::make_pair("JanuszTracz$%^", false),
                             std::make_pair("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", false),
                             std::make_pair("JanuszTracz&*()", false)));