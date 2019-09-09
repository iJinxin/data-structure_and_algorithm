#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
  vector<int> twoSum(vector<int> &nums, int target){
    int start=0;
    int end=nums.size()-1;
    for (int i=start;i<=end;i++) {
      bool break_out = false;
      for (int j=i+1;j<=end;j++) {
        if (nums[i]+nums[j] == target) {
          start = i;
          end = j;
          break_out = true;
          break;
        }
      }
      if (break_out) break;
    }
    vector <int> result = {start, end};
    return result;
  }
};

int main(){
  Solution solution;
  vector<int> obj = {1,4,3,7,8, 10, 20, 50, 11, 5, 6, 13};
  int target = 19;
  vector<int> result;
  result = solution.twoSum(obj, target);

  for (int i=0;i<result.size();i++) {
    cout << result[i];
    cout << ",";
  }
}