/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {

private:
    unordered_map<int, vector<int>> getAdjecentList(int num, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> res;
        // for (int i=0; i < num; i++) {
        //     res.insert(make_pair(i, vector<int>()));
        // }
        for (auto &edge: edges) {
            // add a new element
            // res.find(edge[1])->second.push_back(edge[0]);
            res[edge[1]].push_back(edge[0]);
        }
        return res;
    }

    unordered_map<int, int> getInDegrees(int num, unordered_map<int, vector<int>>& adjList) {
        unordered_map<int, int> res;
        // initialize with 0 in degrees
        for (int i=0; i < num; i++) {
            res.insert(make_pair(i, 0));
        }

        for (auto &pair: adjList) {
            for (auto &ele: pair.second) {
                res[ele]++;
            }
        }
        return res;

    }

    vector<int> getStartNodes(unordered_map<int, int>& indegrees) {
        vector<int> res;
        for (auto &pair: indegrees) {
            if (pair.second == 0) {
                res.push_back(pair.first);
            }
        }
        return res;
    }

    vector<int> getTopologicalOrder(vector<int>& startNodes, unordered_map<int, vector<int>>& adjList,
        unordered_map<int, int> indegrees) {
        vector<int> res;
        queue<int> q;
        
        for (auto &node: startNodes) {
            q.push(node);
            res.push_back(node);
        }

        // bfs
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &ele: adjList[cur]) {
                indegrees[ele]--;
                if (indegrees[ele] == 0) { // it can even be smaller than 0
                    q.push(ele);
                    res.push_back(ele);
                }
            }
        }
        return res;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        ///////////// Solution One ///////////////////
        // Nine chapters. 39.17%   
        vector<int> res;
        if (numCourses == 0) return true;

        unordered_map<int, vector<int>> adjList = getAdjecentList(numCourses, prerequisites);

        // count indegrees
        unordered_map<int, int> indegrees = getInDegrees(numCourses, adjList);

        // get start nodes, i.e., they have 0 indegree
        vector<int> startNodes = getStartNodes(indegrees);

        // bfs
        vector<int> order = getTopologicalOrder(startNodes, adjList, indegrees);
        // for (auto &ele: order) cout << ele << endl;
        return order.size() == numCourses;
    }
};
// @lc code=end

