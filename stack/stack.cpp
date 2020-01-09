#include <iostream>

using namespace std;

class Stack {
 private:
  int flag;
  int count;
  int container[];
 public:
  Stack(/* args */);
  ~Stack();
  int pop();
  void push();
};

Stack::Stack(/* args */) {}

Stack::~Stack() {}
 
int main() { return 0; }