/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        ////////// Solution One (From Solution)//////////
        // Ref.:https://leetcode.com/problems/roman-to-integer/discuss/6851
        // Use unordered map

        // std::unordered_map<char, int> map = {
        //     {'I', 1},
        //     {'V', 5},
        //     {'X', 10},
        //     {'L', 50},
        //     {'C', 100},
        //     {'D', 500},
        //     {'M', 1000}
        // };

        // int res = 0;
        // for (int i=0; i<s.size()-1; i++) {
        //     if (map[s[i]] < map[s[i+1]]) res -= map[s[i]];
        //     else  res += map[s[i]];
        // }
        // res += map[s.back()];
        // return res;

        ////////// Solution Two (From Solution)//////////
        // Ref.:https://leetcode.com/problems/roman-to-integer/discuss/6851
        // Use array, which is faster than unordered_map
        int map[24];
        map['I' - 'A'] = 1;
        map['V' - 'A'] = 5;
        map['X' - 'A'] = 10;
        map['L' - 'A'] = 50;
        map['C' - 'A'] = 100;
        map['D' - 'A'] = 500;
        map['M' - 'A'] = 1000;

        int res = map[s.back() - 'A'];
        for (int i=s.size()-2; i>=0; i--) {
            if (map[s[i]-'A'] < map[s[i+1]-'A']) res -= map[s[i]-'A'];
            else res += map[s[i]-'A'];
        }
        return res;
    }
};
// @lc code=end

