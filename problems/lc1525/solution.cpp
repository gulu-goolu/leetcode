#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
#include <cstdio>
#include <sstream>

using namespace std;

void print(const char* tag, const vector<int>& v) {
  stringstream ss;
  for (int i = 0; i < v.size(); ++i) {
    ss << v[i];
    if (i + 1 != v.size()) ss << ",";
  }
  printf("%s: %s\n", tag, ss.str().c_str());
}

class Solution {
public:
  int numSplits(string s) {
    vector<int> v1, v2;
    unordered_set<char> h1, h2;
    for (int i = 0; i < s.length(); ++i) {
      h1.insert(s[i]);
      v1.push_back(h1.size());

      h2.insert(s[s.length() - i - 1]);
      v2.push_back(h2.size());
    }
    std::reverse(v2.begin(), v2.end());
    print("v1", v1);
    print("v2", v2);

    int res = 0;
    for (int i  = 1; i < s.length(); ++i) {
      if (v1[i - 1] == v2[i]) res++;
    }

    return res;
  }
};

int main() {
  Solution solution;
  string s = "";
  printf("%d\n", solution.numSplits(s));
}
