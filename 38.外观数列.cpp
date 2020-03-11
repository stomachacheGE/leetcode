/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay1(int n) {
        if (n==1) return "1";
        string ret_1 = countAndSay(n-1);
        string ret;
        char cur = ret_1[0];
        int count = 0;
        for (int i=0; i<ret_1.size(); i++) {
            if (ret_1[i] == cur) {
                count++;
                continue;
            }

            ret.push_back(count+'0');
            ret.push_back(cur);
            cur = ret_1[i];
            count = 1;
        }

        ret.push_back(count+'0');
        ret.push_back(cur);
        return ret;
    }

    string countAndSay(int n) {

        if (n == 1) return "1";
        string res = "", prev = countAndSay(n-1);
        int i = 0;
        while (i < prev.size()) {
            int count = 1;
            while (i < prev.size()-1 && prev[i] == prev[i+1]) {
                count++;
                i++;
            }
            res += to_string(count);
            res += prev[i];
            i++;
        }
        return res;
    }
};
// @lc code=end

