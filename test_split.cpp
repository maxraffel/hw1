/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  Node* in = new Node(0, nullptr);
  Node* odds = nullptr;
  Node* evens = nullptr;
  Node* temp = in;
  for (int i = 1; i < 10; i++) {
    Node* newNode = new Node(i, nullptr);
    temp->next = newNode;
    temp = newNode;
  }

  temp = in;
  while (temp->next != nullptr) {
    cout << temp->value << endl;
    temp = temp->next;
  }

  split(in, odds, evens);
  temp = odds;
  while (temp->next != nullptr) {
    cout << temp->value << endl;
    Node* temp2 = temp;
    temp = temp->next;
    delete temp2;
  }
  delete temp;
  temp = evens;
  while (temp->next != nullptr) {
    cout << temp->value << endl;
    Node* temp2 = temp;
    temp = temp->next;
    delete temp2;
  }
  delete temp;
}
