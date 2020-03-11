/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class DSU {
public:
    DSU(int N) { // 提前预留空间避免频繁内存分配
        parent.reserve(N);
    }
    void Add(int x) { // 添加一个节点
        parent[x] = x;
    }
    void Union(int x, int y) { // 合并两个节点
        int rootx = Find(x);
        int rooty = Find(y);
        if (rootx != rooty) {
            parent[rootx] = rooty;
        }
    }
    int Find(int x) { // 找根节点
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
    bool Contains(int x) { // 是否在并查集中
        return parent.find(x) != parent.end();
    }
private:
    unordered_map<int, int> parent;
};

class Solution {
public:
    int longestConsecutive1(vector<int>& nums) {
        // ref.:https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode/
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0, cur = 1;
        for (auto num: nums) {
            if (s.count(num-1)) continue; // 如果num-1在数组中，num会在num-1的查找过程中被用到，此时就不用了
            cur = 1;
            while (s.count(num+1)) {
                num++;
                cur++;
            }
            res = max(res, cur);
        }
        return res;

    }

    int longestConsecutive(vector<int>& nums) {
        // 并查集解法
        // https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/bing-cha-ji-by-krystollia/
        
        DSU dsu(nums.size());
        for (const auto& num : nums) {
            // 重复出现的，跳过
            if (dsu.Contains(num)) continue;
            dsu.Add(num);
            if (dsu.Contains(num-1)) dsu.Union(num, num-1);
            if (dsu.Contains(num+1)) dsu.Union(num, num+1);
        }
        unordered_map<int, int> roots; // 连通子集根节点 -> 连通子集包含节点个数
        unordered_set<int> checked; // 保存已经检查过的数字，避免重复计算同一个数字
        for (const auto& num : nums) {
            if (checked.find(num) != checked.end()) continue;
            roots[dsu.Find(num)]++;
            checked.insert(num);
        }
        int max = 0;
        for (const auto& it : roots) {
            if (it.second > max) max = it.second;
        }
        return max;
    }
    
};
// @lc code=end

