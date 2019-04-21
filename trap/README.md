# 方法一：穷举
- 优点：内存占用小；
- 缺点：速度慢，复杂度 `O(n^2)`
```cpp
int trap(vector<int>& height) {
    if (height.size() < 3) {
        return 0;
    }
    // 穷举法
    int total = 0;
    for (int i = 1; i < height.size() -1; ++i) {
        int left = 0;
        int right = 0;
        for (int k = 0; k < i; ++k) {
            if (height[k] > left) {
                left = height[k];
            }
        }
        
        for (int k = i + 1; k <height.size(); ++k) {
            if (height[k] > right) {
                right = height[k];
            }
        }
        
        total += std::max(std::min(left, right) - height[i], 0);
    }
    return total;
}
```

# 方法二：空间换时间
- 优点：速度快，复杂度 `O(n)`
- 缺点：占用内存
```cpp
int trap(vector<int>& height) {
    if (height.size() < 3) {
        return 0;
    }
    
    vector<int> left(height.size());
    vector<int> right(height.size());
    int a = height[0];
    left[0] = a;
    for (int i = 1; i < height.size(); ++i) {
        if (height[i] > a) {
            a = height[i];
        }
        left[i] = a;
    }
    
    a = *height.rbegin();
    *right.rbegin() = a;
    for (int i = height.size() - 1; i > 0; --i) {
        if (height[i] > a) {
            a = height[i];
        }
        right[i] = a;
    }
    
    // 穷举法
    int total = 0;
    for (int i = 1; i < height.size() -1; ++i) {
        total += std::max(std::min(left[i], right[i]) - height[i], 0);
    }
    return total;
}
```

# 方法三：使用栈来记录最大值
```cpp
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}
```