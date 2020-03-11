/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        // ref.:https://leetcode-cn.com/problems/string-to-integer-atoi/solution/cli-yong-du-qu-kai-shi-pan-bie-wei-de-jie-fa-by-wo/
        int result = 0;
        int str_size=str.size();
        int flag=1;//存储+-标志位
        bool start=false;//数字读取是否已经开始
        //若之后再出现不是数字的字符，则break
        for(int i=0;i<str_size;i++){
            if(str[i]==' '&&start==false){
                continue;
            }
            if(str[i]=='-'&&start==false){
                flag=-1;
                start=true;
                continue;
            }
            if(str[i]=='+'&&start==false){
                flag=1;
                start=true;
                continue;
            }
            if(str[i]>='0'&&str[i]<='9'){
                start=true;
                //判断溢出
                if (result > INT_MAX/10 || (result == INT_MAX/10 && str[i]-'0'>7)) {
                    return INT_MAX;
                }
                if (result < INT_MIN/10 || (result == INT_MIN/10 && str[i]-'0'>8)) {
                    return INT_MIN;
                }
                result=result*10+flag * (str[i]-'0'); // 每一步都把符号位乘进去
                continue;
            } else {
                break;
            }
        }
        return result;
    }
};
// @lc code=end

