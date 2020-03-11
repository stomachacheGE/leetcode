/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
private:
    double calcEquation(unordered_map<string, vector<pair<string, double>>>& graph, string a, string b) {
        if (graph.count(a) == 0 || graph.count(b) == 0) return -1.0;
        if (a == b) return 1.0;
        deque<pair<string, double>> q;
        q.push_back(make_pair(a, 1.0));
        unordered_set<string> visited;
        visited.insert(a);
        double res = -1.0;
        while (!q.empty() && res == -1.0) {
            pair<string, double> cur = q.front();
            q.pop_front();
            for (auto &item: graph[cur.first]) {
                double cur_val = cur.second * item.second;
                if (item.first == b) {
                    res = cur_val;
                    break;
                }
                if (visited.count(item.first) == 0) {
                    q.push_back(make_pair(item.first, cur_val));
                    visited.insert(item.first);
                }
            }
        }
        return res;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        // solution one
        // 思路错误，不能处理连续除法
        // 通过8/11
        // unordered_map<string, vector<pair<string, double>>> dividends;
        // // unordered_map<string, vector<pair<string, int>>> divisors;

        // for (int i=0; i<equations.size(); i++) {
        //     vector<string> cur = equations[i];
        //     pair<string, double> dividend_temp = make_pair(cur[1], values[i]);
        //     pair<string, double> dividend_temp_1 = make_pair(cur[0], 1.0/values[i]);

        //     // pair<string, int> divisor_temp = make_pair(cur[0], values[i]);
        //     if (dividends.count(cur[0]) == 0) {
        //         dividends[cur[0]] = vector<pair<string, double>>{dividend_temp};
        //     } else {
        //         dividends[cur[0]].push_back(dividend_temp);
        //     }
        //     if (dividends.count(cur[1]) == 0) {
        //         dividends[cur[1]] = vector<pair<string, double>>{dividend_temp_1};
        //     } else {
        //         dividends[cur[1]].push_back(dividend_temp_1);
        //     }
        // }

        // vector<double> res;
        // double cur_res = -1.0;
        // for (auto &q: queries) {
        //     cur_res = -1.0;
        //     string dividend = q[0], divisor = q[1];
            
        //     if (dividends.count(dividend) == 0) {
        //         res.push_back(cur_res);
        //         continue;
        //     }

        //     if (dividend == divisor) {
        //         res.push_back(1.0);
        //         continue;
        //     }

        //     for (auto &divisor_: dividends[dividend]) {
        //         if (divisor_.first == divisor) {
        //             cur_res = divisor_.second;
        //             break;
        //         }
        //         if (dividends.count(divisor_.first)) {
        //             for (auto &temp: dividends[divisor_.first]) {
        //                 if (temp.first == divisor) {
        //                     cur_res = divisor_.second * temp.second;
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        //     res.push_back(cur_res);
        // }
        // return res;

        // solution two
        // ref.:https://leetcode-cn.com/problems/evaluate-division/solution/bfsyi-ci-gao-ding-shi-jian-100-by-tomwillow/
        // 双向图bfs, 用dfs也可以做
        unordered_map<string, vector<pair<string, double>>> graph;

        // 构建图
        for (int i=0; i<equations.size(); i++) {
            vector<string> cur = equations[i];
            pair<string, double> temp1 = make_pair(cur[1], values[i]);
            pair<string, double> temp2 = make_pair(cur[0], 1.0/values[i]);
            graph[cur[0]].push_back(temp1);
            graph[cur[1]].push_back(temp2);
        }

        // bfs找答案
        vector<double> res;
        for (auto &q: queries) {
            res.push_back(calcEquation(graph, q[0], q[1]));
        }
        return res;
    }
};
// @lc code=end

