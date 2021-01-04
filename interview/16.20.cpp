// https://leetcode-cn.com/problems/t9-lcci/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<string> getValidT9Words(string num, vector<string>& words) {
  std::unordered_map<char, std::unordered_set<char>> m = {
      {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}},
      {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}},
      {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}},
      {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}},
  };

  // 从前往后遍历 num 中的字符
  for (int i = 0; i < num.length(); ++i) {
    const int idx = num[i] - '0';
    const auto& s = m[idx];
    int pos = 0;
    while (pos < words.size()) {
      // 把不匹配的元素挪到数组的尾部
      if (words[pos].length() < i || s.find(words[pos][i]) == s.end()) {
        std::swap(words[pos], words[words.size() - 1]);
        words.resize(words.size() - 1);
        continue;
      }

      pos++;
    }
  }

  return words;
}

int main() {
  {
    std::vector<std::string> words = {"tree", "used"};
    auto res = getValidT9Words("8733", words);
    for (const auto& s : res) {
      std::cout << s << std::endl;
    }
  }
  {
    std::vector<std::string> words = {"a", "b", "c", "d"};
    auto res = getValidT9Words("2", words);
    for (const auto& s : res) {
      std::cout << s << std::endl;
    }
  }

  return 0;
}