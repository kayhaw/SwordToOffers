# 二维数组中的查找

## :question:题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

## :bulb:解决思路
从二维数组最后一行的第一个数开始比较，当前元素小于查找元素，查找当前行的下一个元素，当前元素大于查找元素，查找上一行，等于查找元素返回true

## :pencil2:代码
```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int cloumn = array[0].size();
        
        for(int i = row-1, j = 0; i>=0 && j < cloumn;){
            if(target == array[i][j]){
                return true;
            }else if(target < array[i][j]){
                i--;
                continue;
            }else{
                j++;
                continue;
            }
        }
        return false;
    }
};
```