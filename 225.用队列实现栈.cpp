/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
private:
    deque<int> queue1;
    deque<int> queue2;
    int stack_top;

public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stack_top = x;
        if (queue1.empty()) {
            queue2.push_back(x);
        } else {
            queue1.push_back(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int cur = stack_top;
        if (!queue1.empty()) {
            while (queue1.size() != 1) {
                cur = queue1.front();
                queue1.pop_front();
                queue2.push_back(cur);
            }
            stack_top = cur;
            cur = queue1.front();
            queue1.pop_front();
            return cur;
        } else {
            while (queue2.size() != 1) {
                cur = queue2.front();
                queue2.pop_front();
                queue1.push_back(cur);
            }
            stack_top = cur;
            cur = queue2.front();
            queue2.pop_front();
            return cur;
        }
    }
    
    /** Get the top element. */
    int top() {
        return stack_top; 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

