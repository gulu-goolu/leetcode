#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string s = "1";
    while (--n) {
      s = helper(s);
    }
    return s;
  }

  static string helper(const string& s) {
    string res;
    size_t pos = 0;
    while (pos < s.size()) {
      char c = s[pos++];
      int num = 1;
      while (pos < s.size() && s[pos] == c) {
        pos++;
        num++;
      }

      // 本字符描述
      auto cur = to_string(num);
      cur.push_back(c);

      res += cur;
    }
    return res;
  }
};

int main() {
  Solution solution;
  for (int i = 1; i <= 10; ++i) {
    cout << solution.countAndSay(i) << endl;
  }
}
