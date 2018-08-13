// Copyright 2018 <Author>

#ifndef NODE_H_
#define NODE_H_

class Node {
 public:
  explicit Node(char data);
  char GetData();
  Node* InsertPreviousNode(char data);
  Node* InsertNextNode(char data);
  Node* GetPreviousNode();
  Node* GetNextNode();
  bool ErasePreviousNode();
  bool EraseNextNode();

  //newly added functions
  bool EraseNode();

private:
  //newly added variables
  char _data;
  Node * _prev;
  Node * _next;
};

#endif  // NODE_H_
