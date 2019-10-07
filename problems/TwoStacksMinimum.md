# 包含min函数的栈

## :question:题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数(时间复杂度应为O(1))。

## :bulb:解决思路
双栈数据结构：stack1专注于普通的压栈出栈，stack2用于最小元素的压栈入栈，当stack2为空时无条件和stack1压相同元素入栈，当stack2不为空时，~~当前元素比stack2栈顶元素小才入栈~~(当前元素不大于stack2栈顶元素时入栈，否则两个连续相同最小元素只有一个元素被压入stack2中，导致连续出栈时stack2会出现空栈pop的错误)，确保栈顶元素始终是stack1中的最小元素，出栈时要注意比较stack1，stack2栈顶元素，相同则stack2也要出栈

## :pencil2:代码
```c++
class Solution {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int value) {
        s1.push(value);
        //注意，判断条件value<=s2.top()
        if(s2.empty() || value <= s2.top())
            s2.push(value);
    }
    void pop() {
        if(s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};
```