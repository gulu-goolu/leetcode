class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> pairs;
        for (const auto& str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            pairs[s].push_back(str);
        }

        const auto debug = [&]() {
            stringstream ss;
            for (auto it = pairs.begin(); it != pairs.end(); ++it) {
                ss << it->first << ":";
                for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                    ss << *it2 << ",";
                }
                ss << "\n";
            }
            printf("%s\n", ss.str().c_str());
        };
        // debug();

        vector<vector<string>> res;
        for (auto& pair: pairs) {
            res.emplace_back(move(pair.second));
        }
        return res;
    }
};
