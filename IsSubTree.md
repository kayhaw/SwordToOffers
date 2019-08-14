# 树的子结构

## :question:题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

## :bulb:解决思路
递归调用，见代码

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2)
            return false;
        else if(pRoot1->val == pRoot2->val) {
            return HasSubtree(pRoot1->left, pRoot2->left) && HasSubtree(pRoot1->right, pRoot2->right);
        } else {
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }
    }
};
```