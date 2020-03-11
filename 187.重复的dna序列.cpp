/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
private:
    int char2int(char c) {
        switch(c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // solution one
        // naive
        // 从头到位依次截取长度为10的substr
        // 用一个hashmap来存每个substr出现的次数

        // solution two
        // ref.:https://leetcode-cn.com/problems/repeated-dna-sequences/solution/bit-manipulation-8-ms-faster-than-9980-of-c96-mb-l/
        // 将ACGT编码为0，1，2，3
        // 依次截取长度为10的substr并没有利用重复的9个字符
        // 用位操作来保证前面9个字符没有重复利用
        // 同时用bitset代替hasmap，减少额外空间的利用
        vector<string> res;
        if (s.size() < 10) return res;
        int value = 0;
        bitset<1<<20> set1; // 注意bitset的大小是2^21
        bitset<1<<20> set2; // set2用来判断重复
        for (int i=0; i<=9; i++) {
            value = (value << 2) | char2int(s[i]);
        }
        set1[value] = 1;
        int mask = (1<<20) - 1;
        for (int i=10; i<s.size(); i++) {
            value = ((value << 2) & mask) | char2int(s[i]);
            if (set1[value]) {
                if (!set2[value]) {
                    res.push_back(s.substr(i-9, 10));
                    set2[value] = 1;
                }
            } else {
                set1[value] = 1;
            }
        }
        return res;
    }
};
// @lc code=end

