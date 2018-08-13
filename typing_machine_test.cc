// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
	EXPECT_EQ(tm.TypeKey('a'), true);
	EXPECT_EQ(tm.TypeKey('b'), true);
	EXPECT_EQ(tm.TypeKey('c'), true);
	ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	ASSERT_EQ(tm.Print(0), std::string("abc"));

	//basic erase test
	ASSERT_EQ(tm.EraseKey(), true);
	ASSERT_EQ(tm.EraseKey(), true);
	ASSERT_EQ(tm.EraseKey(), true);
	ASSERT_EQ(tm.EraseKey(), false);

	//basic left/right move test
	EXPECT_EQ(tm.TypeKey('a'), true);
	EXPECT_EQ(tm.TypeKey('b'), true);
	EXPECT_EQ(tm.TypeKey('c'), true);
	tm.LeftKey();
	tm.LeftKey();
	EXPECT_EQ(tm.Print('|'), std::string("a|bc"));
	tm.RightKey();
	EXPECT_EQ(tm.Print('|'), std::string("ab|c"));
	tm.RightKey();
	tm.RightKey();
	tm.RightKey();
	EXPECT_EQ(tm.Print('|'), std::string("abc|"));
	tm.LeftKey();
	EXPECT_EQ(tm.Print('|'), std::string("ab|c"));
	tm.LeftKey();
	tm.LeftKey();
	tm.LeftKey();
	tm.LeftKey();
	EXPECT_EQ(tm.Print('|'), std::string("|abc"));

	//basic home key test
	tm.RightKey();
	tm.RightKey();
	tm.HomeKey();
	EXPECT_EQ(tm.Print('|'), std::string("|abc"));
	tm.RightKey();
	tm.RightKey();
	tm.EndKey();
	EXPECT_EQ(tm.Print('|'), std::string("abc|"));

	//invalid character input
	EXPECT_EQ(tm.TypeKey(0), false);
	EXPECT_EQ(tm.TypeKey(31), false);
	EXPECT_EQ(tm.TypeKey(32), true);
	EXPECT_EQ(tm.TypeKey(100), true);
	EXPECT_EQ(tm.TypeKey(126), true);
	EXPECT_EQ(tm.TypeKey(127), false);

	//erase all
	for (int i = 0; i < 6; i++)
		EXPECT_EQ(tm.EraseKey(), true);
	EXPECT_EQ(tm.EraseKey(), false);

	//max input 100
	for (int i = 0; i < 100; i++)
		EXPECT_EQ(tm.TypeKey('a'), true);
	EXPECT_EQ(tm.TypeKey('a'), false);


  }

public:
  static void RunTest() {
    BarSeparatorTest();
    // add more..
  }
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  // add more..
}