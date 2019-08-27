# 数组中重复的数字

## :question:题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

## :bulb:解决思路
使用元素值在0至n-1范围内这个关键点，把元素值作为下标，构造n大小的查找表记录下标值是否出现过一次

## :pencil2:代码
```c++
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        vector<bool> t(length, false);
        for(int i = 0; i < length; ++i){
            if(t[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            t[numbers[i]] = true;
        }
        return false;
    }
};
```