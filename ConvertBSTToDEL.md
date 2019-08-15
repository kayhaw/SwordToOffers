# 二叉搜索树与双向链表

## :question:题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

## :bulb:解决思路
二叉搜索树的中序遍历即是排好序的，使用非递归的中序遍历改变左右子节点指针完成转换

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
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        stack<TreeNode*> s;
        TreeNode *node = pRootOfTree, *pre = NULL;
        if(!pRootOfTree)
            return pRootOfTree;
        while(node || !s.empty()){
            while(node){
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            if(!pre){
                pRootOfTree = node;
                pre = pRootOfTree;
            }else{
                pre->right = node;
                node->left = pre;
                pre = node;
            }
            node = node->right;
        }
        return pRootOfTree;
    }
};
```