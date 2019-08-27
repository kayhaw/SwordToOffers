# 最小的K个数

## :question:题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

## :bulb:解决思路
递归实现，简单易懂

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
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)
            return 0;
        return max(TreeDepth(pRoot->left)+1, TreeDepth(pRoot->right)+1);
    }
};
```