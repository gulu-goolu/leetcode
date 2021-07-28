class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({}); // 空集

        for (int i = 0; i < nums.size(); ++i) {
            vector<vector<int>> temp = res;
            for (auto& v: temp) {
                v.push_back(nums[i]);
                res.emplace_back((v));
            }

            const auto debug = [&res, i]() {
                std::stringstream ss;
                for (auto it = res.begin(); it != res.end();) {
                    auto& v = *it;
                    for (auto it2 = v.begin(); it2 != v.end();) {
                        ss << *it2;
                        if (++it2 != v.end()) ss << ",";
                    }
                    if (++it != res.end()) {
                        ss << "|";
                    }
                }
                printf("eat %d, produce [%s]\n", i, ss.str().c_str());
            };
            // debug();
        }
        return res;
    }
};
