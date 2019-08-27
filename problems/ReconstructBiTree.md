# 重建二叉树

## :question:题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

## :bulb:解决思路
根据前序遍历的结果，依次把中序遍历分成左右两个子树，然后再递归调用

## :pencil2:代码
```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> &pre,vector<int> &vin) {
        if(pre.size() == 0 || vin.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        auto pos = find(vin.begin(), vin.end(), pre[0]);
        pre.erase(pre.begin());
        vector<int> left (vin.begin(), pos);
        vector<int> right (pos+1, vin.end());
        root->left = reConstructBinaryTree(pre, left);
        root->right = reConstructBinaryTree(pre, right);
        return root;
    }
};
```