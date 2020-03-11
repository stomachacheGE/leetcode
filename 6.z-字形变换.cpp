/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert1(string s, int numRows) {
        
        // Solution One
        // 利用余数找关系
        // string res;
        // if (s.size()==0 || numRows==0) return res;
        // if (numRows==1) return s;

        // int cycle = 2 * numRows - 2;
        // for (int i=0; i<=cycle/2; i++) {
        //     for (int j=0; j<s.size(); j++) {
        //         if (j % cycle == i || j % cycle == cycle - i) {
        //             res += s[j];
        //         }
        //     }
        // }
        // return res;

        // Solution Two
        // Ref.:https://leetcode-cn.com/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode/
        // 官方解答的解法二
        // 在solution one中，因为第二层循环每次都要遍历一遍s，所以整个时间复杂度位O(n**2)
        // 实际上，第二层循环可以优化，使s中每个字符都只被访问一次，整体复杂度为O(n)
        // string res;
        // if (s.size()==0 || numRows==0) return res;
        // if (numRows==1) return s;

        // int cycle = 2 * numRows - 2;
        // for (int i=0; i<=numRows-1; i++) {
        //     for (int j=i; j<s.size(); j+=cycle) {
        //         res += s[j];
        //         if (i != 0 && i != numRows -1 && j+2*(numRows-1-i) < s.size()) {
        //             res += s[j+2*(numRows-1-i)];
        //         }               
        //     }
        // }
        // return res;

        // Solution Three
        // Ref.:https://leetcode-cn.com/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode/
        // 官方解答的解法一
        // 依次遍历字符串，为每行建立一个列表，并将每个字符放在对应的行列表中
        string res;
        if (s.size()==0 || numRows==0) return res;
        if (numRows==1) return s;

        vector<string> strings(min(int(s.size()), numRows));
        bool goDownwards = true;
        int row = 0;
        for (int i=0; i<s.size(); i++) {
            strings[row] += s[i];
            if (row == numRows-1) goDownwards = false;
            if (row == 0) goDownwards = true;
            row += goDownwards ? 1 : -1;
        }

        for (auto &rowString: strings) res += rowString;
        return res;
    }   

    string convert(string s, int numRows) {

        string res;
        if (s.size()==0 || numRows==0) return res;
        if (numRows==1) return s;

        vector<string> strings(min(int(s.size()), numRows));
        int n = numRows + numRows - 2, idx;
        for (int i=0; i<s.size(); i++) {
            idx = i % n;
            if (i % n > n/2) idx = n - idx;
            strings[idx] += s[i]; 
        }

        for (auto &rowString: strings) res += rowString;
        return res;
    }
};
// @lc code=end

