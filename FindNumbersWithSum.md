# 和为S的两个数字

## :question:题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

## :bulb:解决思路
- 使用hash表进行快速查找
- 使用首尾指针进行查找

最先找到的，在排序数组中相隔最远的一组数即是乘积最小的

## :pencil2:代码
```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        map<int, int> table;
        vector<int> res;
        for(int i = 0; i < array.size(); i++){
            table[array[i]] = i;
        }
        for(int i : array){
            if(table.find(sum - i) != table.end()){
                res.push_back(i);
                res.push_back(sum-i);
                return res;
            }
        }
        return res;
    }
};
```