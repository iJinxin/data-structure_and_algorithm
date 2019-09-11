#include <iostream>
using namespace std;

int main() {
  // 指针取值
  int i = 10;
  int *p = &i;         // 指针p，指向i，p存储的是i在内存中地址
  cout << p << endl;   // 0x61fex4
  cout << *p << endl;  // 10
  *p = 11;             // 解引用符，内存中存储的值被改变
  cout << p << endl;   // 0x61fex4
  cout << *p << endl;  // 11
  cout << i << endl;   // 11

  // 空指针
  int *p2=0;
  cout << p2 << endl;

  return 0;
}