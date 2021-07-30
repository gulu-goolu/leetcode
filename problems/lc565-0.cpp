class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> S(nums.size(), 0);
        vector<int> visited(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;

            // 初始化
            S[i] = 1;
            int k = i;
            visited[i] = 1;

            while (nums[k] != i) {
                S[i]++;
                k = nums[k];
                visited[k] = 1;
            }
        }

        const auto debug = [&]() {
            stringstream ss;
            for (auto it = S.begin(); it != S.end(); ++it) {
                ss << *it << ", ";
            }
            printf("%s\n", ss.str().c_str());
        };
        debug();

        int res = 0;
        for (auto& s: S) {
            res = std::max<int>(s, res);
        }
        return res;
    }
};
