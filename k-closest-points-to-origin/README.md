# k-closest-points-to-origin
[k-closest-points-to-origin](https://leetcode.com/problems/k-closest-points-to-origin/)

## 解法1
首先使用前 K 个数据初始化一个大根堆，然后从第 K + 1 个数据开始遍历数组中余下的数据，对于任意一个数据执行如下操作：
- 将数和大根堆的 root 相比
  - 如果比 root 大，跳过这个元素
  - 如果比 root 小，将 root 出队列，然后将数据入队列