/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class mycomparison{
public:
  bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const
  {
    return lhs.second > rhs.second;
  }
};

class mycomparison1{
public:
  bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const
  {
    return lhs.second < rhs.second;
  }
};

class Solution {
public:
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        // 用最小堆维护，能够保证heap的空间较小
        // counter
        unordered_map<int, int> counter;
        for (auto &num: nums) {
            if (counter.count(num) == 0) {
                counter.insert(make_pair(num, 1));
            } else {
                counter.find(num)->second++;
            }
        }
        
        // for (auto& x: counter) {
        //     std::cout << x.first << ": " << x.second << std::endl;
        // }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> heap;
        for (auto &count: counter) {
            if (heap.size() < k) {
                heap.push(count);
                continue;
            }
            
            int smallest = heap.top().second;
            // cout << "smallest: " << smallest << endl;
            if (count.second > smallest){
                heap.pop();
                heap.push(count);
            } 
        }
        
        vector<int> res;
        while (heap.size() > 0) {
            res.push_back(heap.top().first);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 先计数，然后用最大堆保存前k高元素
        unordered_map<int, int> counter;
        for (auto &num: nums) {
            counter[num]++;
        }

        // priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison1> max_heap;
        // auto it = counter.begin();
        // while (it != counter.end()) {
        //     max_heap.push(*it);
        //     it++;
        // }

        priority_queue<pair<int, int>> max_heap; // 默认最大堆
        for (auto &ele: counter) {
            max_heap.push(make_pair(ele.second, ele.first));
        }
    
        vector<int> res;
        while (k-- > 0) {
            pair<int, int> cur = max_heap.top();
            max_heap.pop();
            res.push_back(cur.second);
        }
        return res;

    }
};
// @lc code=end

