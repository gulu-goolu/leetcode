#include <algorithm>
#include <vector>

/*
# k-closest-points-to-origin
[k-closest-points-to-origin](https://leetcode.com/problems/k-closest-points-to-origin/)

## 解法1
首先使用前 K 个数据初始化一个大根堆，然后从第 K + 1 个数据开始遍历数组中余下的数据，对于任意一个数据执行如下操作：
- 将数和大根堆的 root 相比
  - 如果比 root 大，跳过这个元素
  - 如果比 root 小，将 root 出队列，然后将数据入队列
 */

using namespace std;

class Solution {
public:
    using Point = vector<int>;
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        vector<Point> heap;
        init_heap(heap, points, K);
        for (int i = K; i < (int)points.size(); ++i) {
            update_heap(heap, points[i]);
        }
        return heap;
    }
    static int distance(const Point &point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    static bool compare(const Point &l, const Point &r) {
        return distance(l) < distance(r);
    }

    void init_heap(vector<Point> &heap, const vector<Point> &points, int k) {
        heap.assign(points.begin(), points.begin() + k);
        make_heap(heap.begin(), heap.end(), compare);
    }
    void update_heap(vector<Point> &heap, const Point &point) {
        if (compare(heap[0], point))
            return;
        pop_heap(heap.begin(), heap.end(), compare);
        *heap.rbegin() = point;
        push_heap(heap.begin(), heap.end(), compare);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
}
