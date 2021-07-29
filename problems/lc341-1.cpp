/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    using Cursor = pair<vector<NestedInteger>*, int>;
    NestedIterator(vector<NestedInteger> &nestedList) {
        cursor = std::pair<vector<NestedInteger>*, int>(&nestedList, 0);
    }

    
    int next() {
        int val = (*cursor.first)[cursor.second++].getInteger();

        hasNext();

        return val;
    }
    
    bool hasNext() {
        if (is_integer(cursor)) {
            return true;
        }

        // 找到下一个 integer
        while (cursor.second < (*cursor.first).size() || !st.empty()) {
            if (cursor.second < (*cursor.first).size()) {
                auto& temp = (*cursor.first)[cursor.second];
                if (temp.isInteger()) {
                    break; // found
                }

                cursor.second++; // 指向当前 vector 的下一个元素。
                // 发现一个 list
                st.push(cursor);
                cursor = std::pair<vector<NestedInteger>*, int>(&temp.getList(), 0);
            } else {
                cursor = st.top(); // 已经遍历完 vector 中的所有元素，从栈中取出下一个待处理的列表
                st.pop();
            }
        }

        return is_integer(cursor);
    }

    bool is_integer(const Cursor& c) const {
        if (!c.first || (*c.first).size() == c.second) return false; //  cursor 必须指向一个有效的 NestedInteger

        return (*c.first)[c.second].isInteger();
    }

    // <list, cursor>
    Cursor cursor;
    std::stack<Cursor> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
