# 栈的压入、弹出序列

## :question:题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

## :bulb:解决思路
用代码模拟一遍入栈出栈操作，看最后栈是否为空。当栈为空或者栈顶元素不为出栈序列元素时，按入栈序列压入元素，否则弹出元素

## :pencil2:代码
```c++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        for(int i = 0, j = 0; i < popV.size(); i++) {
            while(s.empty() || s.top() != popV[i]) {
                s.push(pushV[j++]);
            }
            s.pop();
        }
        return s.empty();
    }
};
```