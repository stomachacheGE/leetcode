/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
private:
    int wordDistance(string word1, string word2) {
        int res = 0;
        for (int i=0; i<word1.size(); i++) {
            if (word1[i] != word2[i]) res++;
            if (res >= 2) return res;
        }
        return res;

    }

    int numUsed(vector<bool> used) {
        int res = 0;
        for (int i=0; i<used.size(); i++) {
            if (used[i]) res++;
        }
        return res;
    }
    void ladderLength(string cur, string endWord, vector<bool>& used,
        unordered_map<string, int> word2idx,
        unordered_map<string, vector<string>> table, int& step, int& res) {

        if (cur == endWord) {
            if (step < res) res = step;
            return;
        }

        if (numUsed(used) == used.size() || used[word2idx[cur]]) {
            return;
        }

        step++;
        used[word2idx[cur]] = true;
        for (auto &word: table[cur]) {  
            ladderLength(word, endWord, used, word2idx, table, step, res);
        }
        used[word2idx[cur]] = false;
        step--;
    }
public:
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        
        // solution one
        // 建立每个单词与它只有一个字母距离的hashmap
        // 递归深度优先搜索，
        // 因为要找最短路径，需要遍历所有情况，耗时爆炸，只能通过19个
        // if (wordList.size() == 0) return 0;
        // unordered_map<string, vector<string>> table;
        // unordered_map<string, int> word2idx;
        // wordList.push_back(beginWord);
        // for (int i=0; i<wordList.size(); i++) {
        //     word2idx[wordList[i]] = i;
        //     for (int j=0; j<wordList.size(); j++) {
        //         if (i != j) {
        //             if (wordDistance(wordList[i], wordList[j]) == 1) {
        //                 table[wordList[i]].push_back(wordList[j]);
        //             }
        //         }
        //     }
        // }

        // vector<bool> used(wordList.size(), false);
        // string cur = beginWord;
        // int res = INT_MAX, step = 1;
        // ladderLength(cur, endWord, used, word2idx, table, step, res);
        // return res == INT_MAX ? 0 : res;

        // solution two
        // 非递归广度优先搜索
        // 仍旧超时，怀疑构造table时间过长
        // if (wordList.size() == 0) return 0;
        // unordered_map<string, vector<string>> table;
        // unordered_map<string, int> word2idx;
        // wordList.push_back(beginWord);
        // for (int i=0; i<wordList.size(); i++) {
        //     word2idx[wordList[i]] = i;
        //     for (int j=0; j<wordList.size(); j++) {
        //         if (i != j) {
        //             if (wordDistance(wordList[i], wordList[j]) == 1) {
        //                 table[wordList[i]].push_back(wordList[j]);
        //             }
        //         }
        //     }
        // }
        // vector<bool> used(wordList.size(), false);
        // int res = 1, cur_level = 1, next_level = 0;
        // deque<string> queue;
        // queue.push_back(beginWord);
        // used[used.size()-1] = true;
        // while (!queue.empty()) {
        //     string cur = queue.front();
        //     queue.pop_front();
        //     cur_level--;
        //     for (auto &word: table[cur]) {
        //         // cout << "cur=" << cur << ", word=" << word << endl; 
        //         if (used[word2idx[word]]) continue;
        //         if (word == endWord) return res+1;
        //         used[word2idx[word]] = true;
        //         queue.push_back(word);
        //         next_level++;
        //         // cout << "cur_level=" << cur_level << ", next_level=" << next_level << ", res=" << res << endl;
        //     }
        //     if (cur_level == 0) {
        //         res++;
        //         cur_level = next_level;
        //         next_level = 0;
        //     }
        // }
        // return 0;

        // solution three
        // 非递归广度优先搜索
        set<string> words;
        unordered_map<string, int> word2idx;
        int i = 0;
        for (auto &word: wordList) {
            words.insert(word);
            word2idx[word] = i++;
        }
        vector<bool> used(wordList.size(), false);
        int res = 1, cur_level = 1, next_level = 0;
        deque<string> queue;
        queue.push_back(beginWord);
        while (!queue.empty()) {
            string cur = queue.front();
            queue.pop_front();
            cur_level--;
            for (int i=0; i<cur.size(); i++) {
                for (int j=0; j<26; j++) {
                    string word = cur;
                    if ('a' + j == cur[i]) continue;
                    word[i] = 'a' + j;
                    auto it = words.find(word);
                    if (it != words.end()) {
                        // cout << "cur=" << cur << ", word=" << word << endl; 
                        if (used[word2idx[word]]) continue;
                        if (word == endWord) return res+1;
                        used[word2idx[word]] = true;
                        queue.push_back(word);
                        next_level++;
                        // cout << "cur_level=" << cur_level << ", next_level=" << next_level << ", res=" << res << endl;
                    }
                }
            }
            if (cur_level == 0) {
                res++;
                cur_level = next_level;
                next_level = 0;
            }
        }
        return 0;

        // solution three
        // Ref.:https://leetcode-cn.com/problems/word-ladder/comments/
        // 双向bfs搜索(TODO)
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Ref.:https://leetcode-cn.com/problems/word-ladder/comments/
        // 双向bfs搜索(TODO)
        // 每次从中间结果少的地方搜索
        unordered_set<string> words(wordList.begin(), wordList.end());
        // corner case
        if (words.count(endWord) == 0) return 0; // necessary
        unordered_set<string> starts, ends; // 用set因为要判断中间结果是否在ends里面
        starts.insert(beginWord);
        ends.insert(endWord);
        int res = 0;
        while (!starts.empty()) {
            res++;
            unordered_set<string> temp_set;
            for (auto cur: starts) {
                // remove used word from words
                words.erase(cur);
                for (int n=0; n < cur.size(); n++) {
                    for (int c='a'; c<='z';c++) {
                        if (cur[n] == c) continue;
                        string cur_temp = cur;
                        cur_temp[n] = c;
                        if (words.count(cur_temp) == 0) continue;
                        if (ends.count(cur_temp) == 1) { // 在ends中找到了结果
                            return res+1;
                        }
                        temp_set.insert(cur_temp); 
                    }
                }
            }

            // 选中间结果小的作为下一轮starts
            if (temp_set.size() <= ends.size()) {
                starts = temp_set;
            } else {
                starts = ends;
                ends = temp_set;
            }
        }
        return 0;
    }
};
// @lc code=end