# 链表中环的入口结点

## :question:题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

## :bulb:解决思路
寻找环入口的两种方法：
- hash表法，记录每个结点的地址，循环时出现重复结点地址即为环入口
- 快慢指针法，快指针每次走两步，满指针每次走一步，相遇时停止，再让慢指针重新移到头结点，同步遍历直到快慢指针再次一样，此时地址为入口结点

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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        unordered_set<ListNode*> s;
        //while条件多加了个!导致出错！！！
        while(pHead){
            if(s.find(pHead) != s.end())
                break;
            s.insert(pHead);
            pHead = pHead->next;
        }
        return pHead;
    }
};
```
```C++
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode*fast=pHead,*low=pHead;
        while(fast&&fast->next){
            fast=fast->next->next;
            low=low->next;
            if(fast==low)
                break;
        }
        if(!fast||!fast->next)return NULL;
        low=pHead;          //low从链表头出发
        while(fast!=low){   //fast从相遇点出发
            fast=fast->next;
            low=low->next;
        }
        return low;
    }
};
```