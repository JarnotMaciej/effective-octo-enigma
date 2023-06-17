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

class scoreLineValidationTest : public ::testing::TestWithParam<std::pair<std::string, bool>> {};

TEST_P(scoreLineValidationTest, scoreLineValidation) {
  std::string name = GetParam().first;
  bool expected = GetParam().second;
  ASSERT_EQ(scoreLineValidation(name), expected);
}

INSTANTIATE_TEST_SUITE_P(Names, scoreLineValidationTest,
                        ::testing::Values(
                             std::make_pair("JanuszTracz 0 12", true),
                             std::make_pair("JanuszTracz.sad 0 12", false),
                             std::make_pair("dsadsa 22222222222 11111111111111", true),
                             std::make_pair("JanuszTracz s 12", false),
                             std::make_pair("JanuszTracz 0 s", false),
                             std::make_pair("JanuszTracz a s", false),
                             std::make_pair("fsfad 0 12", true),
                             std::make_pair("afsdfasd", false),
                             std::make_pair("adsfafsdasfd 12", false)));

class foodConfigValidationTest : public ::testing::TestWithParam<std::pair<std::string, bool>> {};

TEST_P(foodConfigValidationTest, foodConfigValidation) {
  std::string name = GetParam().first;
  bool expected = GetParam().second;
  ASSERT_EQ(foodConfigValidation(name), expected);
}

INSTANTIATE_TEST_CASE_P(Names, foodConfigValidationTest,
                        ::testing::Values(
                             std::make_pair("JanuszTracz 0 12", false),
                             std::make_pair("banana 10 -5 35 5 -10 -15", true),
                             std::make_pair("blueberries 12 -5 40 10 -15 -15", true),
                             std::make_pair("carrot 8 0 25 5 -5 -10", true),
                             std::make_pair("cherry 5 0 15 0 -5 -5", true),
                             std::make_pair("grapes 10 -5 30 5 -10 -10", true),
                             std::make_pair("strawberries 10 -5 30 5 -10 -10", true),
                             std::make_pair("apple 3 5 10 0 -2 -5", true),
                             std::make_pair("apple -3 -5 -10 -12 -2 -5", true),
                             std::make_pair("apple 3 5 10 0 2 5", true)));


class tamagotchiFileValidationTest : public ::testing::TestWithParam<std::pair<std::string, bool>> {};

TEST_P(tamagotchiFileValidationTest, tamagotchiFileValidation) {
  std::string name = GetParam().first;
  bool expected = GetParam().second;
  ASSERT_EQ(tamagotchiSaveValidation(name), expected);
}

INSTANTIATE_TEST_CASE_P(Names, tamagotchiFileValidationTest,
                        ::testing::Values(
                             std::make_pair("0\nNeko\n45\n100\n100\n0\n0\n572\n1\n1686422245\n1687002698\n1687002704", true),
                             std::make_pair("0\nNeko\n45\n100\n100\n0\n0\n572\n1\n1686422245\n1687002698\n1687002704\n", true),
                                std::make_pair("0\nNeko\n45\n100\n100\n0\n0\n572\n1\n1686422245\n1687002698\n1687002704\n1687002704", false),
                                std::make_pair("0", false),
                                std::make_pair("dasd", false),
                                std::make_pair("0\nDog\n70\n90\n20\n0\n0\n500\n1\n1686422245\n1687002698\n", false),
                                std::make_pair("1\nRabbit\n20\n200\n80\n0\n0\n100\n1\n1686422245\n1687002698\n1687002704\n", true)
                             ));

// TODO -> foodSaveValidation test