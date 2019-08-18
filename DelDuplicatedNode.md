# 删除链表中重复的结点

## :question:题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5。

## :bulb:解决思路
第一个结点就是重复的怎么办？引入一个头结点。

## :pencil2:代码
```c++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode *head = new ListNode(-1);
        head->next = pHead;
        ListNode *pre = head, *unique = pHead;
        
        //又是漏了最简单的情况
        if(!pHead || !(pHead->next))
            return pHead;
        
        while(unique){
            if(unique->next && unique->val == unique->next->val){
                while(unique->next && unique->val == unique->next->val)
                    unique = unique->next;
                //重复节点不保留
                pre->next = unique->next;
                unique = unique->next;
            }else{
                pre = pre->next;
                unique = unique->next;
            }
        }
        pHead = head->next;
        delete head;
        return pHead;
    }
};
```