// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
	Node *prev_node;
	Node *next_node;
	//basic function : p<->A(node)<->n
    ASSERT_EQ(node->GetData(), 'A');
	EXPECT_NE(node->InsertPreviousNode('p'), nullptr);
	EXPECT_NE(node->InsertNextNode('n'), nullptr);
	prev_node = node->GetPreviousNode();
	EXPECT_NE(prev_node, nullptr);
	next_node = node->GetNextNode();
	EXPECT_NE(next_node, nullptr);
	EXPECT_EQ(prev_node->GetData(), 'p');
	EXPECT_EQ(next_node->GetData(), 'n');
	EXPECT_EQ(node->ErasePreviousNode(), true);
	EXPECT_EQ(node->ErasePreviousNode(), false);
	EXPECT_EQ(node->EraseNextNode(), true);
	EXPECT_EQ(node->EraseNextNode(), false);


    delete node;
  }

public:
  static void RunTest() {
    SingleNodeTest();
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

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  // add more..
}