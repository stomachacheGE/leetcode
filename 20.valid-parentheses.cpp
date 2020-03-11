/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.43%)
 * Total Accepted:    595.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        if (s.size()%2 != 0) return false;
        string stack = "";
        for (int i=0; i<s.size(); i++) {
            switch (s[i]) {
                case '[':
                case '{':
                case '(':
                    stack.push_back(s[i]);
                    break;
                case ']': 
                    if (stack.empty() || stack.back() != '[') return false;
                    else stack.pop_back();
                    break;
                case ')': 
                    if (stack.empty() || stack.back() != '(') return false;
                    else stack.pop_back();
                    break;
                case '}': 
                    if (stack.empty() || stack.back() != '{') return false;
                    else stack.pop_back();
                    break;
            }
        }
        return stack.empty();

    }
};
