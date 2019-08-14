# 反转链表

## :question:题目描述
输入一个链表，反转链表后，输出新链表的表头。

## :bulb:解决思路
单向链表的就地反转，需要两个额外的指针，指针pre指向当前已经反转部分的首结点，指针next指向当前未反转部分的首结点，注意pre初始化为NULL，如下图所示
![](reverselinkedlist.gif "图片来自GeeksforGeeks: Reverse a linked list")

## :pencil2:代码
```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pre = NULL, *next;
        while(pHead){
            next = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;
    }
};
```