#include <vector>

using namespace std;

// 暴力更新每个矩形区域的值
class SubrectangleQueries {
 public:
  explicit SubrectangleQueries(vector<vector<int>> &rectangle) {
    rectangle_ = rectangle;
  }

  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    for (int i = row1; i <= row2; ++i) {
      for (int j = col1; j <= col2; ++j) {
        rectangle_[i][j] = newValue;
      }
    }
  }

  int getValue(int row, int col) { return rectangle_[row][col]; }
  vector<vector<int>> rectangle_;
};

void test() {
  vector<vector<int>> rectangle = {{1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};
  SubrectangleQueries *obj = new SubrectangleQueries(rectangle);
  obj->getValue(0, 2);
  obj->updateSubrectangle(0, 0, 3, 2, 5);
  obj->getValue(0, 2);
  obj->getValue(3, 1);
  obj->updateSubrectangle(3, 0, 3, 2, 10);
  obj->getValue(3, 1);
  obj->getValue(0, 2);
}

int main() {
  test();
  return 0;
}
