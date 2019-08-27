# 合并两个排序的链表

## :question:题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

## :bulb:解决思路
采用递归的方法：当其中一个链表到达末尾是返回另一个链表的结点，否则的话取当前两个链表结点值较大的结点作为合并的新结点，新结点的next指针指向两条链表剩余部分merge的链表

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1)
            return pHead2;
        else if(!pHead2)
            return pHead1;
        else if(pHead1->val <= pHead2->val) {
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        } else {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
};
```