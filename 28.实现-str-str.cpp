/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr1(string haystack, string needle) {
        // solution one
        // two pointers
        if (needle == "") return 0;
        if (haystack.size() < needle.size()) return -1;
        for (int i=0; i<haystack.size()-needle.size()+1; i++) {
            int m = i, n = 0;
            // 注意需要判断边界
            while (m < haystack.size() && n < needle.size() && haystack[m] == needle[n]) {
                m++;
                n++;
            }
            if (n == needle.size()) return i;
        }
        return -1;

        // solution two
        // ref.:https://leetcode-cn.com/problems/implement-strstr/solution/kmp-suan-fa-xiang-jie-by-labuladong/
        // KMP算法（TODO）
    }

    int strStr(string haystack, string needle) {
        // KMP 算法
        if (needle == "") return 0;
        if (haystack.size() < needle.size()) return -1;
        // get next
        int n = haystack.size(), m = needle.size(), j = 0;
        vector<int> next(m, 0);
        next[0] = -1;
        for (int i=1; i<m-1; i++) {
            j = next[i];
            while (j > 0 && needle[j] != needle[i]) {
                j = next[j];
            }
            if (needle[j] == needle[i]) j++;
            next[i+1] = j;
        }
        // for (auto x: next) cout << x << " ";
        // cout << "here";
        // search
        j = 0;
        for (int i=0; i<n; i++) {
            while (j != -1 && haystack[i] != needle[j]) {
                j = next[j];
            }
            j++;
            if (j == needle.size()) return i - j + 1;
        }
        return -1;
    }
};
// @lc code=end

