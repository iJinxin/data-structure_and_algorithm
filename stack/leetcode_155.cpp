/**
 * 最小栈
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈
 */

#include <iostream>
#include <limits>

using namespace std;

class MinStack {
 private:
  int size;
  int flag;
  int minValue;
  int *array;

 public:
  MinStack(/* args */);
  void push(int data);
  int pop();
  int top();
  int getMin();
};

MinStack::MinStack(/* args */) {
  this->flag = 0;
  this->size = 10;
  this->minValue = INT_MIN;
  this->array = new int[10];
}
void MinStack::push(int data) {
  // 栈满，扩容
  if (this->flag == this->size) {
    this->size = int(this->size * 1.5);
    int *temp = new int[this->size];
    for (int i = 0; i < this->flag; ++i) {
      temp[i] = this->array[i];
    }
    delete[] this->array;
    this->array = temp;
    this->array[this->flag] = data;
    this->flag++;
  } else {
    this->array[this->flag] = data;
    this->flag++;
  }
  // 更新minValue
  if (this->minValue == INT_MIN || data < this->minValue) {
    this->minValue = data;
  }
}
int MinStack::pop() {
  if (this->flag == 0) return -1;
  if (this->flag == 1) {
    this->minValue = INT_MIN;
  }
  this->flag--;
  // 更新 minValue
  if (this->array[this->flag] == minValue) {
    minValue = this->array[0];
    for (int i = 0; i < this->flag; i++) {
      if (this->array[i] < minValue) {
        minValue = this->array[i];
      }
    }
  }
  // cout << this->array[this->flag] << endl;
  return this->array[this->flag];
}

int MinStack::top() { 
  cout << this->array[this->flag - 1] << endl;
  return this->array[this->flag - 1]; 
}

int MinStack::getMin() { 
  cout << this->minValue << endl;
  return this->minValue; 
}

int main() {
  MinStack minStack;
  minStack.push(2147483646);
  minStack.push(2147483646);
  minStack.push(2147483647);

  minStack.top();
  minStack.pop();
  minStack.getMin();
  minStack.pop();
  minStack.getMin();
  minStack.pop();

  minStack.push(2147483647);

  minStack.top();
  minStack.getMin();

  minStack.push(-2147483648);

  minStack.top();
  minStack.getMin();
  minStack.pop();
  minStack.getMin();

  return 0;
}
