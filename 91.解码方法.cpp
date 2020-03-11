/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings1(string s) {

        // solution one
        // dynamic programing
        // 特别需要注意处理10的情况
        int size = s.size();
        if (s == "0") return 0;
        
        if (size <= 1) return size;
        int minus1 = s[s.size()-1] == '0' ? 0 : 1, minus2 = 0, res;
        for (int i=2; i<=size; i++) {
            if (s[size-i] == '0') {
                res = 0;
            } else if (atoi(s.substr(size-i, 2).c_str()) <= 26) {
                res = minus1 + minus2;
                if (i == 2) res += 1;
            } else {
                res = minus1;
            }
            minus2 = minus1;
            minus1 = res;
        }
        return res;
        
    }

    int numDecodings(string s) {
        // solution one
        // dynamic programming
        // if (s.empty()) return 0;
        // if (s[0] == '0') return 0; // corner case
        // int num = s.size();
        // // 以某个位置为结尾的子串的解码方法数量
        // vector<int> states(num, 0);
        // states[0] = 1;
        // for (int i=1; i<num; i++) {
        //     int cur = atoi(s.substr(i-1, 2).c_str());
        //     if (s[i] == '0' && cur != 10 && cur != 20) {
        //         return 0;
        //     } else if (cur == 10 || cur == 20) {
        //         states[i] = i >= 2 ? states[i-2] : 1;
        //     } else if (cur <= 26 && cur > 10) { // 如果cur是个位数，说明s[i-1]是0
        //         states[i] = i >= 2 ? states[i-1] + states[i-2] : states[i-1] + 1;
        //     } else {
        //         states[i] = states[i-1];
        //     }
        // }
        // return states.back();

        // solution two
        // 更优雅的条件判断
        // ref.:https://leetcode-cn.com/problems/decode-ways/solution/dong-tai-gui-hua-ting-jian-dan-de-a-by-cai-liao-xi/
        if (s.empty()) return 0;
        if (s[0] == '0') return 0; // corner case
        int num = s.size();
        // 以某个位置为结尾的子串的解码方法数量
        vector<int> states(num, 0);
        states[0] = 1;
        for (int i=1; i<num; i++) {
            int cur = (s[i-1]-'0') * 10 + s[i] - '0';
            if (s[i] > '0') {
                states[i] = states[i-1];
            } 
            if (cur > 9 && cur <= 26) {
                states[i] += i >= 2 ? states[i-2] : 1;
            }
            if (states[i] == 0) return 0;
        }
        return states.back();
    }
};
// @lc code=end

