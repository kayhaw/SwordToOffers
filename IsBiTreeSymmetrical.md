# 对称的二叉树

## :question:题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

## :bulb:解决思路
利用栈的特性，根节点的左右结点一对入栈，每次出栈两个，进行比较，相同的话根据镜像关系[左子树左结点，右子树右结点]，[左子树右结点，右子树左结点]一对一对入栈，重复上述操作

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
    bool isSymmetrical(TreeNode* pRoot)
    {
        stack<TreeNode*> s;
        TreeNode *left, *right;
        if(!pRoot)
            return true;
        s.push(pRoot->left);
        s.push(pRoot->right);
        while(!s.empty()){
            right = s.top();
            s.pop();
            left = s.top();
            s.pop();
            if(!left && !right)
                continue;
            if(!left || !right)
                return false;
            if(left->val != right->val)
                return false;
            s.push(left->left);
            s.push(right->right);
            s.push(left->right);
            s.push(right->left);
        }
        return true;
    }

};
```