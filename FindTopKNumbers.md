# 最小的K个数

## :question:题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

## :bulb:解决思路
TOP K问题的解决方法
- 全排序
- 堆代替数组

## :pencil2:代码
```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size() < k)
            return res;
        sort(input.begin(), input.end());
        for(int i = 0; i < k; i++){
            res.push_back(input[i]);
        }
        return res;
    }
};
```