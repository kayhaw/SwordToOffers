# 二叉树的下一个结点

## :question:题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

## :bulb:解决思路
- 当前节点有右子树，中序遍历的下一个结点为右子树的最左下结点
- 当前节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。

## :pencil2:代码
```c++
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* node;
        if(!pNode)
            return NULL;
        if(pNode->right){
            node = pNode->right;
            while(node->left)
                node = node->left;
            return node;
        }
        while(pNode->next){
            node = pNode->next;
            if(node->left == pNode)
                return node;
            pNode = pNode->next;
        }
        return NULL;
    }
};
```