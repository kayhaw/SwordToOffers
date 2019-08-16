# 平衡二叉树

## :question:题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

## :bulb:解决思路
从下往上遍历，出现高度差大于等于2立即停止遍历

## :pencil2:代码
```c++
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return getDepth(pRoot) != -1;
    }
    int getDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left = getDepth(root->left);
        if(left == -1)
            return -1;
        int right = getDepth(root->right);
        if(right == -1)
            return -1;
        return abs(left-right) > 1 ? -1 : 1+max(left, right);
    }
};
```