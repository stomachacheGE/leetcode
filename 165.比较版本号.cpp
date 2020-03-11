/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
private:
    int compare(string version1, int i, int p, string version2, int j, int q) {
        string v1, v2;

        while(i < p && version1[i] == '0') i++;
        while(j < q && version2[j] == '0') j++;

        v1 = i > p ? "0" : version1.substr(i, p-i+1);
        v2 = j > q ? "0" : version2.substr(j, q-j+1);

        // cout << "v1=" << v1 << ", v2=" << v2 << endl;
        if (v1.size() < v2.size()) return -1;
        if (v1.size() > v2.size()) return 1;

        for (int x=0; x<v1.size(); x++) {
            if (v1[x] < v2[x]) return -1;
            if (v1[x] > v2[x]) return 1;
        }
        return 0;
     }
public:
    int compareVersion(string version1, string version2) {

        // solution one
        // 用两个指针挨次比较
        // 能过36/72个
        // 不能过 "1.1"， "1.10"
        // int m = version1.size(), n = version2.size();
        // int i = 0, j = 0;
        // char v1='0', v2='0';

        // bool leading_zero1 = true, leading_zero2 = true;
        // while (i < m || j < n) {
            
        //     if (i < m && version1[i] == '.') {
        //         leading_zero1 = true;
        //         i++;
        //         continue;
        //     }
        //     if (j < n && version2[j] == '.') {
        //         leading_zero2 = true;
        //         j++;
        //         continue;
        //     }

        //     while (leading_zero1 && version1[i] == '0' && i < m-1 && version1[i+1] != '.') {
        //         i++;
        //     }
        //     leading_zero1 = false;
        //     while (leading_zero2 && version2[i] == '0' && j < n-1 && version2[j+1] != '.') {
        //         j++;
        //     }
        //     leading_zero2 = false;

        //     v1 = i >=m ? '0' : version1[i];
        //     v2 = j >=n ? '0' : version2[j];

        //     if (v1 - '0' > v2 - '0') return 1;
        //     if (v1 - '0' < v2 - '0') return -1;

        //     i++;
        //     j++;
        // }
        // return 0;

        // solution two
        // https://leetcode-cn.com/problems/compare-version-numbers/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-40/
        // 先切分，再比较
        int m = version1.size(), n = version2.size();
        int i = 0, j = 0, p = 0, q = 0;
        int v1 = 0, v2 = 0;
        while (i < m || j < n) {
            while (i < m && version1[i] != '.') {
                i++;
            }
            while (j < n && version2[j] != '.') {
                j++;
            }

            int cur_res = compare(version1, p, i-1, version2, q, j-1);
            if ( cur_res != 0) return cur_res;
            p = ++i;
            q = ++j;
        }
        return 0;
    }
};
// @lc code=end

