# 把二叉树打印成多行

## :question:题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

## :bulb:解决思路
上一道题的退化版本，不同区分正向反向就是

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
        //只能用deque，queue没有begin和end方法
        deque<TreeNode*> que;
        vector<int> tmp;
        vector<vector<int>> res;
        TreeNode* node;
        
        if(!pRoot)
            return res;
        
        que.push_back(NULL);
        que.push_back(pRoot);
        while(que.size() != 1) {
            node = que.front();
            que.pop_front();
            if(!node){
                for(auto iter = que.begin(); iter != que.end(); iter++)
                    //iter解引用必须要用括号
                    tmp.push_back((*iter)->val);
                res.push_back(tmp);
                tmp.clear();
                que.push_back(NULL);
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