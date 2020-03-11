/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
private:
    bool isValidIP(string s, vector<int> points) {
        points.insert(points.begin(), 1, -1);
        points.push_back(s.size()-1);
        for (int i=1; i<points.size(); i++){
            int len = points[i]-points[i-1];
            if (len > 3 || len <=0) return false;
            string substr = s.substr(points[i-1]+1, len);
            if (len > 1 && substr[0] == '0') return false;
            if (atoi(substr.c_str()) > 255) return false;
        }
        return true;
    }
    void backtracking(string s, vector<int> points, int idx, int limit, vector<string>& res) {
        if (points.size() > 3) return;
        if (points.size() == 3) {
            if (isValidIP(s, points)) {
                string s1 = s;
                for (int i=0; i<=2; i++) {
                    s1.insert(points[i]+i+1, 1, '.');
                }
                res.push_back(s1);
            }
        }

        for (int i=idx; i<=min(limit, idx+3); i++) {
            points.push_back(i);
            backtracking(s, points, i+1, limit, res);
            points.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // solution one
        // 找到放三个点的位置，然后再判断是否可能
        vector<string> res;
        if (s.size() <= 3) return res;
        vector<int> points;
        int limit = s.size() - 1;
        backtracking(s, points, 0, limit, res);
        return res;
    }
};
// @lc code=end

