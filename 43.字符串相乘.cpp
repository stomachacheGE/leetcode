/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {

        // Solution one
        // Ref.:https://leetcode-cn.com/problems/multiply-strings/solution/you-hua-ban-shu-shi-da-bai-994-by-breezean/

        if (num1 == "0" || num2 == "0") return "0";

        int size1 = num1.size(), size2 = num2.size();
        vector<int> resVec(size1+size2, 0);
        // 从后往前计算避免进位处理，具体见答案的留言
        for (int i=size1-1; i>=0; i--) {
            for (int j=size2-1; j>=0; j--) {
                int temp = (num1[i] - '0') * (num2[j] - '0');
                int sum = resVec[i+j+1] + temp;
                resVec[i+j] += sum / 10; // 此处可能有进位，但是会在下一次被处理
                resVec[i+j+1] = sum % 10; // 注意此处是等于，不是累加
            }
        }

        string res;
        for (int i=0; i<resVec.size(); i++) {
            // 最多只有第一位为0
            if (i==0 && resVec[i] == 0) continue;
            res += resVec[i] + '0';
        }
        return res;
        
    }
};
// @lc code=end

