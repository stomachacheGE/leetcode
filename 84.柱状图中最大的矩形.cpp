/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea1(vector<int>& heights) {
        // monotonous stack
        if (heights.size() == 0) return 0;
        stack<int> idxs;
        heights.push_back(0);
        int res = 0;
        for (int i=0; i< heights.size(); i++) {
            if (idxs.empty() || heights[idxs.top()] <= heights[i]) {
                // 如果当前元素比栈顶元素大，直接push进栈
                idxs.push(i);
            } else {
                while (!idxs.empty() && heights[idxs.top()] >= heights[i]) {
                    // 矩形的高度即为此刻栈顶
                    int h = heights[idxs.top()];
                    idxs.pop();
        
                    // 矩形的左端点为即为栈顶元素的前一个元素的下一个元素
                    // 右端点为当前元素的前一个元素
                    // 异常处理，如果栈中没有元素了，表示矩形的左端点
                    // 应该是柱状图的开始
                    int w = idxs.empty() ? i : i - idxs.top() - 1;
                    cout << "h= " << h << ", w=" << w << endl;
                    res = max(res, h*w);
                }
                idxs.push(i);
            }
        }
        return res;
        
        
    }

    int largestRectangleArea(vector<int>& heights) {

        // solution one 
        // brute force
        // 计算所有可能的组合的矩形面积
        // int res = 0;
        // for (int i=0; i<heights.size(); i++) {
        //     int min_height = INT_MAX;
        //     for (int j=i; j<heights.size(); j++) {
        //         min_height = min(min_height, heights[j]);
        //         res = max(res, min_height * (j-i+1));
        //     }
        // }
        // return res;

        // solution two
        // monotonous stack 单调栈
        int res = 0;
        heights.insert(heights.begin(), 0); // 头部加0，方便处理当栈里只有一个有效元素时候的情况
        heights.push_back(0); // 尾部加0，方便处理当遍历结束之后，将栈中剩余的元素弹出
        stack<int> st; // stack里面的元素是每个height对应的位置
        for (int i=0; i<heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top();
                st.pop();
                res = max(res, heights[cur] * (i-st.top()-1));
            }
            st.push(i);
        }
        return res;
        

    }
};
// @lc code=end

