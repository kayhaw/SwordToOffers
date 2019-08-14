# 二叉搜索树的后序遍历序列

## :question:题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

## :bulb:解决思路
二叉搜索数的后序遍历：最后一个为根结点，根结点前分成两部分，先是左子树，都比根结点小，然后是右子树都比根结点大，利用这个特性判断

## :pencil2:代码
```c++
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int i = 0, size = sequence.size();
        if(size == 0)
            return false;
        while(size-- > 2){
            while(sequence[i++] < sequence[size]);
            while(sequence[i++] > sequence[size]);
            if(i < size)
                return false;
            i = 0;
        }
        return true;
    }
};
```