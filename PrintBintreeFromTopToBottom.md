# 从上往下打印二叉树

## :question:题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

## :bulb:解决思路
使用队列作为辅助进行二叉树的层序遍历，注意空树直接返回

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> que;
        TreeNode* node = NULL;
        vector<int> res;
        if(!root)
            return res;
        que.push(root);
        while(!que.empty()) {
            node = que.front();
            res.push_back(node->val);
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
            que.pop();
        }
        return res;
    }
};
```