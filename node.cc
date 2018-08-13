// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	_data = data;
	_prev = nullptr;
	_next = nullptr;
  return;
}

char Node::GetData() {
	
	return _data;
	//return '\0';
}

Node* Node::GetPreviousNode() {
	return _prev;
	//return nullptr;
}

Node* Node::GetNextNode() {
	return _next;
  //return nullptr;
}

Node* Node::InsertPreviousNode(char data) {
	Node *prevNode;
	Node *newNode;

	newNode = new Node(data);
	prevNode = GetPreviousNode();

	if (prevNode == nullptr){
		_prev = newNode;
		newNode->_next = this;
	}else{
		prevNode = _prev;
		prevNode->_next = newNode;

		newNode->_prev = prevNode;
		newNode->_next = this;

		_prev = newNode;
	}
  return newNode;
}

Node* Node::InsertNextNode(char data) {

	Node *nextNode;
	Node *newNode;

	newNode = new Node(data);
	if (newNode == nullptr)
		return nullptr;

	nextNode = GetNextNode();

	if (nextNode == nullptr){
		_next = newNode;
		newNode->_prev = this;
	}
	else{
				
		_next = newNode;

		newNode->_prev = this;
		newNode->_next = nextNode;

		nextNode->_prev = newNode;
	}

  return newNode;
}

bool Node::ErasePreviousNode() {
	//Node* node;
	Node* prevNode;

	prevNode = GetPreviousNode();
	if (prevNode == nullptr)
		return false;

	if (prevNode->GetPreviousNode() != nullptr){
		_prev = prevNode->_prev;
		_prev->_next = this;
	}else{
		_prev = nullptr;
	}
	delete prevNode;

	
  return true;
}

bool Node::EraseNextNode() {
	//Node* node;
	Node* nextNode;

	nextNode = GetNextNode();
	if (nextNode == nullptr)
		return false;

	if (nextNode->_next != nullptr){
		_next = nextNode->_next;
		_next->_prev = this;
	}
	else{
		_next = nullptr;
	}

	delete nextNode;

  return true;
}


bool Node::EraseNode()
{
	Node *prevNode;
	Node *nextNode;

	prevNode = this->GetPreviousNode();
	if (prevNode != nullptr) {
		prevNode->EraseNextNode();
		return true;
	}

	nextNode = this->GetNextNode();
	if (nextNode != nullptr){
		nextNode->ErasePreviousNode();
		return true;
	}
	return false;
}