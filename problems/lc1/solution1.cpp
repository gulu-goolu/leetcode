//
// Created by caohongjian on 2020/7/16.
//

// https://leetcode-cn.com/problems/two-sum/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < nums.size(); ++i) {
      indices[nums[i]].push_back(i);
    }

    for (int i = 0; i < nums.size(); ++i) {
      auto& v = indices[target - nums[i]];
      for (auto j : v) {
        // 找到一个结果
        if (i != j) {
          return {i, j};
        }
      }
    }

    return {};
  }
};

int main() {}
