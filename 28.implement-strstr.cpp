/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.90%)
 * Total Accepted:    433.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {

        ////////// Solution One //////////
        // Naive. 97.09%, 73.22%
        // if (needle.size() == 0) return 0;
        // if (needle.size() > haystack.size()) return -1; // this is necessary 
        // for (int i=0; i<=haystack.size()-needle.size(); i++) { // note the =
        //     if (haystack[i] == needle[0]) {
        //         bool flag = true;
        //         for (int j=1; j<needle.size(); j++) {
        //             if (haystack[i+j] != needle[j]) {
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //         if (flag) return i;
        //     }
        // }
        // return -1;

        ////////// Solution Two //////////
        // KMP Algorithm. 71.55%, 39.94%
        // Ref. https://leetcode.com/problems/implement-strstr/discuss/12956
        // Ref. https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
        // Ref. https://www.youtube.com/watch?v=BXCEFAzhxGY
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        // vector<int> lps = kmpProcess(needle);
        int lps[n];
        computeLPSArray(needle, n, lps);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++; // note the j-1
            }
        }
        return -1;
    }

private:
void computeLPSArray(string pat, int M, int *lps)
   {
      int len = 0;  // lenght of the previous longest prefix suffix
      int i;
   
      lps[0] = 0; // lps[0] is always 0
      i = 1;
   
      // the loop calculates lps[i] for i = 1 to M-1
      while (i < M)
      {
         //example "abababca" and i==5, len==3. The longest prefix suffix is "aba", when pat[i]==pat[len],
         //we get new prefix "abab" and new suffix "abab", so increase length of  current lps by 1 and go to next iteration. 
         if (pat[i] == pat[len])
         {
           len++;
           lps[i] = len;
           i++;
         }
         else // (pat[i] != pat[len])
         {
           if (len != 0)
           {
             len = lps[len-1];
             //This is tricky. Consider the example "ababe......ababc", i is index of 'c', len==4. The longest prefix suffix is "abab",
             //when pat[i]!=pat[len], we get new prefix "ababe" and suffix "ababc", which are not equal. 
             //This means we can't increment length of lps based on current lps "abab" with len==4. We may want to increment it based on
             //the longest prefix suffix with length < len==4, which by definition is lps of "abab". So we set len to lps[len-1],
             //which is 2, now the lps is "ab". Then check pat[i]==pat[len] again due to the while loop, which is also the reason
             //why we do not increment i here. The iteration of i terminate until len==0 (didn't find lps ends with pat[i]) or found
             //a lps ends with pat[i].
           }
           else // if (len == 0)
           { // there isn't any lps ends with pat[i], so set lps[i] = 0 and go to next iteration.
             lps[i] = 0;
             i++;
           }
         }
      }
   }  
};
