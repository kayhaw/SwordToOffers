# 链表中倒数第k个结点

## :question:题目描述
输入一个链表，输出该链表中倒数第k个结点。

## :bulb:解决思路
使用快慢两个指针，快指针就是平常的遍历，遍历时计数，当快指针走了k步后慢指针才开始遍历，当快指针达到链表尾部停止时，慢指针也随之停止，比快指针慢k步，由此指向倒数第k个结点

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *slow = pListHead;
        int i = 0;
        for (; pListHead != NULL; i++) {
            if (i >= k)
                slow = slow->next;
            pListHead = pListHead->next;
        }
        return i < k ? NULL : slow;
    }
};
```