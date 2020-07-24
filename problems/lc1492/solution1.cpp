//
// Created by chj on 2020/7/3.
//

// https://leetcode-cn.com/problems/the-kth-factor-of-n/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

// 先计算 n 的所有因子，然后排序
class Solution {
 public:
  int kthFactor(int n, int k) {
    std::vector<int> v;
    const int K = std::sqrt(n);
    for (int i = 1; i <= K; ++i) {
      // 如果 i 是 n 的因子，那么 n / i 也一定是 n 的因子
      if (n % i == 0) {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
    v.push_back(n);

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    return k <= v.size() ? v[k - 1] : -1;
  }
};

int main() {
  std::cout << "n = 100, k = 3, f = " << Solution().kthFactor(1000, 12);
}