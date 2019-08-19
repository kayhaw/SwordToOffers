# 二叉搜索树的第K个结点

## :question:题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

## :bulb:解决思路
二叉搜索树的中序遍历结果即是递增排序的序列，所以只需要返回中序遍历到第k步的节点值

## :pencil2:代码
```c++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        stack<TreeNode*> s;
        TreeNode* node = pRoot;
        int i = 0;
        
        if(!pRoot)
            return pRoot;
        
        while(!s.empty() || node) {
            while(node){
                s.push(node);
                node = node->left;
            }
            if(!s.empty()){
                node = s.top();
                s.pop();
                if(++i == k)
                    return node;
                node = node->right;
            }
        }
        return NULL;
    }
};
```