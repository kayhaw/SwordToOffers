# 复杂链表的复制

## :question:题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

## :bulb:解决思路
如果一开始就是照常的单链表沿着next复制，到了random指针这里会变得无从下手，直接复制random指针结点和后面的next结点无法合并，不复制的话random根本就不知道指向新链表的哪个结点。解这道题巧妙的方法是直接在原链表上进行结点复制，复制结点跟在原结点后面，**然后让复制结点的random指针指向原结点random指针指向的结点**，这样巧妙地完成了random指针的问题，最后切断这条长链表，组织next指针形成原链表和复制链表，如下图所示
![](clonecomplexlist.png "来源见水印")

## :pencil2:代码
```c++
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        //Duplicate list
        RandomListNode *dup = NULL, *head = pHead, *res = NULL;
        if(!pHead)
            return pHead;
        while(head){
            dup = new RandomListNode(head->label);
            dup->next = head->next;
            head->next = dup;
            head = dup->next;
        }
        //Copy random pointer
        head = pHead;
        while(head){
            dup = head->next;
            //注意random可能为空结点
            dup->random = head->random ? head->random->next : NULL;
            head = dup->next;
        }
        //Cut off list
        head = pHead;
        res = head->next;
        while(head){
            dup = head->next;
            head->next = dup->next;
            //注意可能已经是最后一个的复制结点
            dup->next = dup->next ? dup->next->next : NULL;
            head = head->next;
        }
        return res;
    }
};
```