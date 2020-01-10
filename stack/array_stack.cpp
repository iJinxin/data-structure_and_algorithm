#include <iostream>

using namespace std;

class Stack {
 private:
  int flag;
  int size;
  int *array;

 public:
  Stack(/* args */);
  ~Stack();
  int pop();
  void push(int data);
  int stackSize();
  int stackMaxSize();
};

Stack::Stack(/* args */) {
  this->size = 10;
  this->flag = 0;
  this->array = new int[10];
}

Stack::~Stack() {
  this->size = 0;
  this->flag = 0;
  if (this->array) {
    delete[] this->array;
    this->array = NULL;
  }
}

void Stack::push(int data) {
  // 栈满
  if (this->size == this->flag) {
    cout << "stack overflow, expandding"<< endl;
    // 栈扩容,1.5倍
    this->size = int(1.5 * this->size);
    cout << "current size: " << this->size << endl;
    int *temp = new int[this->size];
    for (int i = 0; i < this->flag; i++) {
      temp[i] = this->array[i];
    }
    delete[] this->array;
    temp[this->flag] = data;
    this->flag++;
    this->array = temp;
  } else {
    this->array[this->flag] = data;
    this->flag++;
  }
}

int Stack::pop() {
  if (this->flag == 0) {
    cout << "empty stack" << endl;
    return -1;
  }
  this->flag--;
  int temp = this->array[this->flag];
  cout << "pop: " << temp << endl;
  return temp;
}

int Stack::stackSize() {
  return this->flag;
}

int Stack::stackMaxSize() {
  return this->size;
}

int main() { 
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  stack.pop();

  stack.push(11);
  stack.push(21);
  stack.push(14);
  stack.push(15);

  stack.pop();

  stack.push(23);
  stack.push(23);
  stack.push(23);
  stack.push(23);
  stack.push(23);
  stack.push(343);

  stack.pop();
  return 0; 
}