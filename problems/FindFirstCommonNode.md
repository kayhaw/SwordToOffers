# 两个链表的第一个公共结点

## :question:题目描述
输入两个链表，找出它们的第一个公共结点。

## :bulb:解决思路
1. 如果两个链表长度相同，只要用两个指针循环遍历两个链表，指针所指向地址首次相同时就是公共结点地址。当链表长度不相同时，让长链表的快指针先走多出来的n步，然后慢指针开始走，即可解决这个问题
2. 反转两个链表，前面都是公共结点，首次出现相异结点的前一个公共结点就是第一个公共结点

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int l1= 0, l2 = 0;
        ListNode *h1 = pHead1, *h2 = pHead2;
        while(h1 || h2){
            if(h1){
                l1++;
                h1 = h1->next;
            }
            if(h2){
                l2++;
                h2 = h2->next;
            }
        }
        h1 = pHead1, h2 = pHead2;
        if(l1 < l2){
            for(int i = 0; i < l2-l1; i++)
                h2 = h2->next;
        }else{
            for(int i = 0; i < l1-l2; i++)
                h1 = h1->next;
        }
        /**出现了问题:可能之中有个到达尾部
        *while(h1->val != h2->val)
        */
        while(h1 && h2 && h1->val != h2->val){
            h1 = h1->next;
            h2 = h2->next;
        }
        //注意这里为什么返回值是这个表达式
        return !h1 ? NULL : !h2 ? NULL : h2;
    }
};
```