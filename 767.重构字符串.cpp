/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string S) {
        // 思路太复杂，倒数第二个case过不了
        // 统计个数，能把出现次数最多的那个字母分开就可以
        // if (S.size() == 0 || S.size() == 1) return S;
        // unordered_map<char, int> counter;
        // for (auto &c: S) {
        //     counter[c]++;
        // }
        // string res;
        // priority_queue<pair<int, char>> max_heap;
        // for (auto &it: counter) {
        //     max_heap.push(make_pair(it.second, it.first));
        // }
        // if (max_heap.size() == 1) return "";

        // char cur, next_;
        // int cur_num = 0, next_num = 0;

        // while (!max_heap.empty()) {

        //     if (cur_num == 0 && !max_heap.empty()) {
        //         cur = max_heap.top().second;;
        //         cur_num = max_heap.top().first;
        //         max_heap.pop();
        //     } 
            
        //     if (next_num == 0 && !max_heap.empty()) {
        //         next_ = max_heap.top().second;
        //         next_num = max_heap.top().first;
        //         max_heap.pop();
        //     }
        //     // cout << cur << ":"  << cur_num  << ", " << next_ << ":" << next_num << endl;
        //     while (cur_num > 0 && next_num > 0) {
        //         // cout << cur << ":"  << cur_num  << ", " << next_ << ":" << next_num << endl;
        //         res += cur;
        //         res += next_;
        //         cur_num--;
        //         next_num--;
        //     }
        //     // cout << "cur_num = " << cur_num << endl;
            
        // }
        // cout << cur << ":"  << cur_num  << ", " << next_ << ":" << next_num << endl;
        // if (cur_num + next_num >= 2) return "";
        // if (cur_num == 1) res += cur;
        // if (next_num == 1) res.insert(res.begin(), 1, next_);
        // return res;

        // ref.:https://leetcode-cn.com/problems/reorganize-string/solution/you-xian-dui-lie-gen-ju-zi-mu-shu-liang-pai-xu-by-/
        // 用map和max_heap
        // 固定输出大小，再分奇偶位置填空
        if (S.size() == 0 || S.size() == 1) return S;
        unordered_map<char, int> counter;
        for (auto &c: S) {
            counter[c]++;
        }
        string res(S.size(), ' ');
        priority_queue<pair<int, char>> max_heap;
        for (auto &it: counter) {
            max_heap.push(make_pair(it.second, it.first));
        }

        int idx = 0; // starts with odd position
        while (!max_heap.empty()) {
            pair<int, char> cur = max_heap.top();
            max_heap.pop();
            int num = cur.first;
            if (num > (S.size()+1)/2 ) return ""; // check whether input is valid
            while (num-- > 0) {
                res[idx] = cur.second;
                idx += 2;
                if (idx >= S.size()) idx = 1; // to even position
            }
        }
        return res;

    }
};
// @lc code=end

