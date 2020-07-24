//
// Created by chj on 2020/6/25.
//

#include <vector>

using namespace std;

// 记录更改的历史
class SubrectangleQueries {
 public:
  explicit SubrectangleQueries(vector<vector<int>>& rectangle) {
    rectangle_ = rectangle;
  }

  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    actions_.push_back(Action{row1, col1, row2, col2, newValue});
  }

  int getValue(int row, int col) {
    // 首先查询历史记录
    for (auto it = actions_.rbegin(); it != actions_.rend(); ++it) {
      const auto& action = *it;
      if (row >= action.row1 && row <= action.row2 && col >= action.col1 &&
          col <= action.col2) {
        return action.val;
      }
    }

    return rectangle_[row][col];
  }

 private:
  struct Action {
    int row1, col1, row2, col2;
    int val;
  };
  vector<Action> actions_;
  vector<vector<int>> rectangle_;
};

int main() {}
