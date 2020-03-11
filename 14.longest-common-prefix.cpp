/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.44%)
 * Total Accepted:    468.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ////////// Solution One //////////
        int res = 0;
        if (strs.size() == 0) return "";
        for (int i=0; i<strs[0].size(); i++) {
            for (int j=1; j<strs.size(); j++) {
                if (strs[j].size() == i || 
                    strs[0][i] != strs[j][i]) return strs[0].substr(0, res); 
            }
            res++;
        }
        return strs[0].substr(0, res);
        
        ////////////  Solution Two  ////////////
        // (From Solution, copied, Java)
        // Divide and conquer
        // public String longestCommonPrefix(String[] strs) {
        //     if (strs == null || strs.length == 0) return "";    
        //         return longestCommonPrefix(strs, 0 , strs.length - 1);
        // }

        // private String longestCommonPrefix(String[] strs, int l, int r) {
        //     if (l == r) {
        //         return strs[l];
        //     }
        //     else {
        //         int mid = (l + r)/2;
        //         String lcpLeft =   longestCommonPrefix(strs, l , mid);
        //         String lcpRight =  longestCommonPrefix(strs, mid + 1,r);
        //         return commonPrefix(lcpLeft, lcpRight);
        // }
        // }

        // String commonPrefix(String left,String right) {
        //     int min = Math.min(left.length(), right.length());       
        //     for (int i = 0; i < min; i++) {
        //         if ( left.charAt(i) != right.charAt(i) )
        //             return left.substring(0, i);
        //     }
        //     return left.substring(0, min);
        // }

        ////////////  Solution Three  ////////////
        // (From Solution, copied, Java)
        // Binary search
        // public String longestCommonPrefix(String[] strs) {
        //     if (strs == null || strs.length == 0)
        //         return "";
        //     int minLen = Integer.MAX_VALUE;
        //     for (String str : strs)
        //         minLen = Math.min(minLen, str.length());
        //     int low = 1;
        //     int high = minLen;
        //     while (low <= high) {
        //         int middle = (low + high) / 2;
        //         if (isCommonPrefix(strs, middle))
        //             low = middle + 1;
        //         else
        //             high = middle - 1;
        //     }
        //     return strs[0].substring(0, (low + high) / 2);
        // }

        // private boolean isCommonPrefix(String[] strs, int len){
        //     String str1 = strs[0].substring(0,len);
        //     for (int i = 1; i < strs.length; i++)
        //         if (!strs[i].startsWith(str1))
        //             return false;
        //     return true;
        // }


    }
};
