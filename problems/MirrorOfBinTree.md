# 二叉树的镜像

## :question:题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。

## :bulb:解决思路
递归调用，空结点返回，否则交换左右子结点值，递归调用交换左右子节点下的左右结点的值
```
    	    8
    	   /  \
    	  6   10
源二叉树: / \  / \
    	5  7 9 11
    	
    	    8
    	   /  \
镜像二叉树:10   6
    	 / \  / \
    	11 9 7  5
```
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
    void Mirror(TreeNode *pRoot) {
        if(!pRoot)
            return;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return;
    }
};
```