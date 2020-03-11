/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode-cn.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (46.73%)
 * Total Accepted:    6.5K
 * Total Submissions: 13.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 现在你总共有 n 门课需要选，记为 0 到 n-1。
 * 
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 
 * 给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
 * 
 * 示例 1:
 * 
 * 输入: 2, [[1,0]] 
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 * 
 * 示例 2:
 * 
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
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
                if (indegrees.find(ele)->second == 0) {
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