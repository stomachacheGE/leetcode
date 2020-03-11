/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {

        // solution one
        // 从中间开始往前面走
        // 判断每个位置能否构成回文串
        if (s.empty() || s.size() == 1) return s;
        // int n = s.size(), start = n / 2, left, right;
        // if (n & 1 == 0) start--;
        // string res = s;
        // for (;start>=0; start--) {
        //     // case 1: start is left
        //     // case 1必须在case 2之前，
        //     // 因为如果两个case都满足的话，这种情况下产生的答案比case 2要少一个字符
        //     left = start;
        //     right = start+1;
        //     while (left >=0 && right < n) {
        //         if (s[left] != s[right]) break;
        //         left--;
        //         right++;
        //     }
        //     if (left == -1) break;
        //     // case 2: start is the center
        //     left = start-1;
        //     right = start+1;
        //     while (left >=0 && right < n) {
        //         if (s[left] != s[right]) break;
        //         left--;
        //         right++;
        //     }
        //     if (left == -1) break;
        // }
        // while (right < n) {
        //     res.insert(res.begin(), 1, s[right]);
        //     right++;
        // }
        // return res;

        // solution two
        // ref.:https://leetcode-cn.com/problems/shortest-palindrome/solution/zui-duan-hui-wen-chuan-by-leetcode/
        // 将本题转化为找到s的首字符开始的最大回文字串，再将后面的字符串的反转接在最大回文字串前就是
        // 为了找最大回文字串，可以先把整个字符串反转，然后依次比较不同长度的字串
        // 时间复杂度O(n*n)，最后一个case还是过不了
        // if (s.empty() || s.size() == 1) return s;
        // string rev_s = s;
        // reverse(rev_s.begin(), rev_s.end());
        // for (int n=s.size(); n>0; n--) {
        //     if (s.substr(0, n) == rev_s.substr(s.size()-n)) {
        //         return rev_s.substr(0, s.size()-n) + s;
        //     }
        // }
        // return rev_s + s;

        // solution three
        // ref.:https://leetcode-cn.com/problems/shortest-palindrome/solution/zui-duan-hui-wen-chuan-by-leetcode/
        // ref.:https://www.zhihu.com/question/21923021/answer/281346746
        // 上个solution中的if条件判断句，其实就是s+rev_s的partial match table的最后一个值
        // 借助KMP算法的思想
        if (s.empty() || s.size() == 1) return s;
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#";
        new_s += rev_s;

        vector<int> pmt(new_s.size(), 0);
        int j=0;
        for (int i=1; i<new_s.size(); i++) {
            j = pmt[i-1];
            while (j > 0 && new_s[j] != new_s[i]) {
                j = pmt[j-1];
            }
            if (new_s[j] == new_s[i]) {
                j++;
            }
            pmt[i] = j;
        }
        return rev_s.substr(0, s.size() - pmt.back()) + s;

    }
};
// @lc code=end

