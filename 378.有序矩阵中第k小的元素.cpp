/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 */

// @lc code=start
class mycomparison {
    public:
        bool operator () (const pair<int, pair<int, int>>& lhs, pair<int, pair<int, int>>& rhs) {
            return lhs.first > rhs.first;
        }
};

class Solution {
private:
    int getNthSmallest(vector<vector<int>>& matrix, int val) {
        int i = matrix.size() - 1, j = 0, res = 0;
        while (i >= 0 && j < matrix.size()) {
            if (matrix[i][j] <= val) {
                res += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return res;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // solution one (v2)
        // 对角线元素的左上角必定比此元素小，
        // 它对应的行和列上的的大小关系不好确定，需要一一判断
        // 思路错误不能通过
        // int m = matrix.size(), n = matrix[0].size();
        // int idx = sqrt(k);
        // k -= idx * idx;
        // if (k == 0) return matrix[idx-1][idx-1];
        // int counter = 0, i = 0, j = 0;
        // while (true) {
        //     if (matrix[idx][j] < matrix[i][idx]) {
        //         counter++;
        //         if (counter == k) return matrix[idx][j];
        //         j++;
        //     } else {
        //         counter++;
        //         if (counter == k) return matrix[i][idx];
        //         i++;
        //     }
        // }
        // return 0;

        // solution two (v2)
        // ref.:https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/378-you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-liang/
        // 矩阵的最小最大值由左上角和右下角确定
        // 在此范围内进行二分搜索，对mid求它是第几大的元素
        // int n = matrix.size();
        // int l = matrix[0][0], r = matrix.back().back(), mid;
        // while (l < r) {
        //     mid = l + (r - l) / 2;
        //     // v1: 用upper_bound对每一行进行扫描
        //     // 当mid存在在矩阵里的时候，mid是第nthsmallest小的数;
        //     // 当mid不在矩阵里的时候，mid是第nthsmallest+1小的数
        //     // int nthsmallest = 0;
        //     // for (int i=0; i<n; i++) {
        //     //     auto it = upper_bound(matrix[i].begin(), matrix[i].end(), mid);
        //     //     nthsmallest += it - matrix[i].begin();
        //     // }
        //     // v2: 用矩阵中查找元素是否存在的方式计算
        //     // 效率比v1逐行扫描高
        //     int nthsmallest = getNthSmallest(matrix, mid);
        //     // cout << "mid = " << mid << ", nthsmallest = " << nthsmallest << endl;
        //     if (nthsmallest < k) {
        //         l = mid + 1;
        //     } else {
        //         r = mid;
        //     }
            
        // }
        // return l;

        // solution three (v2)
        // 最小堆
        int n = matrix.size();
        // 最小堆
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, mycomparison> heap;
        
        // 标记位
        // bool used[n][n] = { {false} };
        // vector<vector<bool>> used (n, vector<bool>(n, false));
        
        // heap.push(make_pair(matrix[0][0], make_pair(0, 0)));
        // int counter = 1;
        // while (counter++ < k) {
        //     auto curt = heap.top();
        //     heap.pop();            
        //     int i = curt.second.first, j = curt.second.second;
        //     cout << counter-1 << " --> " << "(" << i << "," << j << ")"  << " --> " << curt.first << endl;
        //     if (i <= n-2 && !used[i+1][j]){
        //         heap.push(make_pair(matrix[i+1][j], make_pair(i+1,j)));
        //         used[i+1][j] = true;
        //     }
        //     if (j <= n-2 && !used[i][j+1]) {
        //         heap.push(make_pair(matrix[i][j+1], make_pair(i,j+1)));
        //         used[i][j+1] = true;
        //     }
        // }
        
        // return heap.top().first;

        // solution four (v2)
        // ref.:https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/378-you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-liang/
        // 用最大堆
        priority_queue<int> pq;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};
// @lc code=end

