# 从尾到头打印链表

## :question:题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

## :bulb:解决思路
遍历链表元素并压栈，然后出栈到结果数组中

## :pencil2:代码
```c++
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> stk;
        vector<int> val;
        while(head != NULL) {
            stk.push(head->val);
            head = head->next;
        }
        while(!stk.empty()){
            val.push_back(stk.top());
            stk.pop();
        }
        return val;
    }
};
```