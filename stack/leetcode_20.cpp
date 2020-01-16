/**
 * ## 有效的括号
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * *** Notice ***
 * 1.左括号必须用相同类型的右括号闭合。
 * 2.左括号必须以正确的顺序闭合
 * 3.空字符串可被认为是有效字符串
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string s);
};

bool Solution::isValid(string s) {
  stack<char> st;
  for (auto ch : s) {
    if (ch == '(' || ch == '[' || ch == '{') {
      st.push(ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      if (st.empty()) return false;
      char stTop = st.top();
      if (stTop == '(' && ch == ')' || stTop == '[' && ch == ']' ||
          stTop == '{' && ch == '}') {
        st.pop();
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
  return st.empty();
}

int main() {
  string testStr = "(){}";
  Solution solution;
  solution.isValid(testStr);
  
  return 0;
}