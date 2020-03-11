/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
bool comp(int lhs, int rhs) {
        string l = to_string(lhs), r = to_string(rhs);
        int min_size = min(l.size(), r.size());
        int idx = 0;
        while (idx < min_size) {
            if (l[idx] == r[idx]) {
                idx++;
                continue;
            }
            return l[idx] < r[idx];
        }
        return l.size() < r.size();
}

class comp1 {
public:
    bool operator() (const int& lhs, const int& rhs) {
        return comp(lhs, rhs);
    }
};
class Solution {
private:   
    int getCountForPrefix(int prefix, int n) {
        long left = prefix, right = prefix+1;
        int count = 0;
        while (left <= n) {
            count += min(long(n+1), right) - left;
            left *= 10;
            right *= 10;
        }
        return count;
    }
    
public:
    int findKthNumber(int n, int k) {

        // priority queue
        // 思路ok，但是复杂度太高，会超时
        // 能通过29/69
        // priority_queue<int, vector<int>, comp1> q;
        // for (int i=1; i<=n; i++) {
        //     if (q.size() < k) {
        //         q.push(i);
        //         continue;
        //     }
        //     if (comp(i, q.top())) {
        //         q.pop();
        //         q.push(i);
        //     }
        // }
        // return q.top();

        // 构造字典序十叉数，类似于前缀树
        // 其前序遍历序列就是字典序排列
        // https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/
        int prefix = 1, kth = 1;
        while (kth < k) {
            int count = getCountForPrefix(prefix, n);
            if (kth + count <= k) { // 往右走
                prefix += 1;
                kth += count;
            } else {                // 往下走
                prefix *= 10;
                kth += 1;
            }
        }
        return prefix;

    }
};
// @lc code=end

