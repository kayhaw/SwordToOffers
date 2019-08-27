# 按之字形顺序打印二叉树

## :question:题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

## :bulb:解决思路
二叉树的层序遍历使用queue辅助实现，而这里要求每次打印后更改打印顺序，使用空指针标记打印二叉树每一层的结尾，当遇到NULL时标记打印顺序取反，同时让前面的父节点出队列，再将子节点入队列

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
    vector<vector<int> > Print(TreeNode* pRoot) {
        deque<TreeNode*> que;
        TreeNode* node;
        vector<vector<int>> res;
        vector<int> tmp;
        
        //最简单的情况漏掉了，到了while循环里面会有NULL->val导致段溢出
        if(!pRoot)
            return res;
        
        que.push_back(NULL);
        que.push_back(pRoot);
        bool reverse = false;
        while(que.size() != 1){
            node = que.front();
            que.pop_front();
            if(!node){
                if(!reverse)
                    for(auto iter = que.begin(); iter != que.end(); iter++)
                        tmp.push_back((*iter)->val);
                else
                    for(auto iter = que.rbegin(); iter != que.rend(); iter++)
                        tmp.push_back((*iter)->val);
                reverse = !reverse;
                //之前把tmp.clear()放在res push之前了
                que.push_back(NULL);
                res.push_back(tmp);
                tmp.clear();
                continue;
            }
            if(node->left)
                que.push_back(node->left);
            if(node->right)
                que.push_back(node->right);
        }
        return res;
    }
};
```