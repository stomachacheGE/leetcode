/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int px = max(A, E);
        int py = max(B, F);
        int qx = min(C, G);
        int qy = min(D, H);
        // cout << px << " " << py << " " << qx << " " << qy << endl;
        int intersection = 0;
        if (px <= qx && py <= qy) {
            intersection = (qx - px) * (qy - py);
        }
        return int((long(C-A) * long(D-B) + long(G-E) * long(H-F)) - long(intersection));
    }
};
// @lc code=end

