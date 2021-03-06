/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 *
 * https://leetcode-cn.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (46.99%)
 * Total Accepted:    3.8K
 * Total Submissions: 8.1K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 现在你总共有 n 门课需要选，记为 0 到 n-1。
 * 
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 
 * 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
 * 
 * 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
 * 
 * 示例 1:
 * 
 * 输入: 2, [[1,0]] 
 * 输出: [0,1]
 * 解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
 * 
 * 示例 2:
 * 
 * 输入: 4, [[1,0],[2,0],[3,1],[3,2]]
 * 输出: [0,1,2,3] or [0,2,1,3]
 * 解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
 * 因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
 * 
 * 
 * 说明:
 * 
 * 
 * 输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 * 
 * 
 * 提示:
 * 
 * 
 * 这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
 * 通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
 * 
 * 拓扑排序也可以通过 BFS 完成。
 * 
 * 
 * 
 */
class Solution {

private:
    unordered_map<int, vector<int>> getAdjecentList(int num, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> res;
        for (int i=0; i < num; i++) {
            res.insert(make_pair(i, vector<int>()));
        }
        for (auto &edge: edges) {
            // add a new element
            res.find(edge[1])->second.push_back(edge[0]);
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
                res.find(ele)->second++;
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
        
        // The following logic is problematic,
        // Since it will output the same node twice,
        // e.g., when input is "3\n[[2,0],[2,1]]""

        // // push start nodes into queue
        // for (auto &node: startNodes) {
        //     q.push(node);
        // }

        // // bfs
        // while (!q.empty()) {
        //     int cur = q.front();
        //     q.pop();
        //     for (auto &ele: adjList.find(cur)->second) {
        //         indegrees.find(ele)->second--;
        //         q.push(ele);
        //     }
        //     if (indegrees.find(cur)->second > 0) {
        //         // add to queue again since it still has dependencies
        //         q.push(cur);
        //     } else if (indegrees.find(cur)->second == 0) {
        //         cout << "going to push " << cur << endl;
        //         res.push_back(cur);
        //     }
        // }

        for (auto &node: startNodes) {
            q.push(node);
            res.push_back(node);
        }

        // bfs
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &ele: adjList.find(cur)->second) {
                indegrees.find(ele)->second--;
                if (indegrees.find(ele)->second == 0) { // it can even be smaller than 0
                    q.push(ele);
                    res.push_back(ele);
                }
            }
        }
        return res;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        ///////////// Solution One ///////////////////
        // Nine chapters. 39.17%   
        vector<int> res;
        if (numCourses == 0) return res;

        unordered_map<int, vector<int>> adjList = getAdjecentList(numCourses, prerequisites);

        // count indegrees
        unordered_map<int, int> indegrees = getInDegrees(numCourses, adjList);

        // get start nodes, i.e., they have 0 indegree
        vector<int> startNodes = getStartNodes(indegrees);

        // bfs
        vector<int> order = getTopologicalOrder(startNodes, adjList, indegrees);
        // for (auto &ele: order) cout << ele << endl;
        if (order.size() == numCourses) {
            res = order;
        }
        return res;
    }
};


// @lc code=end

