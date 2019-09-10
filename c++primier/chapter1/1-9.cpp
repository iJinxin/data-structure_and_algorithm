// 使用while循环计算50-100之间整数之和
#include <iostream>

using namespace std;

int main() {
  int sum = 0;
  int i = 50;
  while (i <= 100) {
    sum += i;
    i++;
  }
  cout << "the result is " << sum << endl;
  return 0;
}