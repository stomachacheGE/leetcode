/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
private:
    int calculate(vector<string> tokens, int operand1, int operand2, int operato) {
        string oper = tokens[operato];
        int i = atoi(tokens[operand1].c_str()), j = atoi(tokens[operand2].c_str()), res = 0;
        cout << i << oper << j << endl;
        if (oper == "+") res = i + j; 
        else if (oper == "-") res = i - j; 
        else if (oper == "*") res = i * j; 
        else if (oper == "/") res = i / j; 
        return res;
    }

    int calculate(int operand1, int operand2, string oper) {
        int i = operand1, j = operand2, res;
        if (oper == "+") res = i + j; 
        else if (oper == "-") res = i - j; 
        else if (oper == "*") res = i * j; 
        else if (oper == "/") res = i / j; 
        return res;
    }

    bool isOperator(string str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
public:
    int evalRPN(vector<string>& tokens) {
        // solution one
        // 用三个指针分别代表当前参与运算的算子
        // 方法有问题，只能通过10/20
        // ["4","-2","/","2","-3","-","-"] 不能通过
        // if(tokens.size() < 3) return atoi(tokens[0].c_str());
        // int operand1 = 0, operand2 = 1, operato = 2, temp = 0;
        // while (tokens[operato] != "+" && tokens[operato] != "-" && tokens[operato] != "*" && tokens[operato] != "/") {
        //     operato++;
        //     cout << "increment" << endl;
        // }
        // cout << operato << tokens[operato] << endl;
        // operand2 = operato;
        // while (tokens[operand2] == "+" || tokens[operand2] == "-" || tokens[operand2] == "*" || tokens[operand2] == "/") {
        //     operand2--;
        // }
        // operand1 = operand2-1;
        // while (tokens[operand1] == "+" || tokens[operand1] == "-" || tokens[operand1] == "*" || tokens[operand1] == "/") {
        //     operand1--;
        // }
        // cout << tokens[operand1] << tokens[operato] << tokens[operand2] << endl;
        // while (operato < tokens.size()) {
        //     cout << "before" << operand1 << " " << operand2 << " " << operato << endl;
        //     temp = calculate(tokens, operand1, operand2, operato);
        //     tokens[operand1] = to_string(temp);
        //     tokens[operand2] = "#";
        //     tokens[operato] = "#";
        //     if (operato == tokens.size() - 1) break;
        //     while (tokens[operato] != "+" && tokens[operato] != "-" && tokens[operato] != "*" && tokens[operato] != "/") {
        //         ++operato;
                
        //     }
        //     // try to find operand2 on the right
        //     while (operand2 < operato && tokens[operand2] == "#") {
        //         operand2++;
        //     }
        //     // operand on the left
        //     if (operand2 == operato || tokens[operand2] == "#") {
        //         operand2 = operand1;
        //         --operand1;
        //         while (tokens[operand1] == "#") {
        //             operand1--;
        //         }
        //     }
        //     cout << "after" << operand1 << " " << operand2 << " " << operato << endl;
        // } 
        // return atoi(tokens[operand1].c_str());

        // solution two
        // ref.https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/solution/javachun-shu-zu-he-zhan-liang-chong-shi-xian-jian-/
        if(tokens.size() < 3) return atoi(tokens[0].c_str());
        int m, n, temp;
        stack<int> s;
        for (int i=0; i<tokens.size(); i++) {
            string cur = tokens[i];
            if (isOperator(cur)) {
                m = s.top();
                s.pop();
                n = s.top();
                s.pop();
                temp = calculate(n, m, cur);
                s.push(temp);
            } else {
                s.push(atoi(cur.c_str()));
            }
        }
        return s.top();
    }
};
// @lc code=end

