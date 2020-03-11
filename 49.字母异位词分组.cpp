/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
private:

    string word2key(string str) {
        string res;
        res.insert(0, 26, '0');
        for (auto& ele: str) {
            res[ele-'a'] += 1;
        }
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Solution One
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        string key;
        for (auto& str: strs) {
            key = word2key(str); 
            // word2key可以用以下代替
            // key = str;
            // sort(key.begin(), key.end());

            // auto it = map.find(key);
            // if (it == map.end()) {
            //     map[key] = {str};
            // } else {
            //     map[key].push_back(str);
            // }
            // 以上find的部分可以用以下一句替代
            map[key].push_back(str);
        }

        for (auto it=map.begin(); it!=map.end(); it++) {
            res.push_back(it->second);
        }
        return res;
        
    }
};
// @lc code=end

