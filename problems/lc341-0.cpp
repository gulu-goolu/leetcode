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
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto& t: nestedList) {
            helper(t);
        }
    }

    void helper(NestedInteger& val) {
        if (val.isInteger()) {
            vals_.push_back(val.getInteger());
        } else {
            for (auto& t: val.getList()) {
                helper(t);
            }
        }
    }
    
    int next() {
        return vals_[cursor_++];
    }
    
    bool hasNext() {
        return cursor_ != vals_.size();
    }

    std::vector<int> vals_;
    int cursor_ = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
