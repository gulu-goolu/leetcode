#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> three_sum(vector<int> nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end(), [](const int &l, const int &r) {
        return abs(l) < abs(r);
    });
    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i - 2] + nums[i - 1] + nums[i]) {
            continue;
        }
        result.push_back({ nums[i - 2], nums[i - 1], nums[i] });
    }

    return result;
}

int main(int argc, char *argv[]) {
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    three_sum(nums);
}
