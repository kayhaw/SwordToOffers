# 用两个栈实现队列

## :question:题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

## :bulb:解决思路
入队列时只管往stack1里面压入元素，出队列时只管让stack2弹出元素，只需要注意当stack2为空时，把stack1中的元素依次弹出并压入到stack2中，这样stack2弹出元素都是最先进入队列的元素，实现FIFO

## :pencil2:代码
```c++
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()) {
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```