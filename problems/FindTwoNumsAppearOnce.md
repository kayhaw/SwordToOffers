# 数组中只出现一次的数

## :question:题目描述
一个整型数组里除了两个数之外，其他的数都出现了两次。请写程序找出这两个只出现一次的数。

## :bulb:解决思路
全体异或运算得到hash=num1^num2，hash的二进制中数位上为1的表示这个位置num1和num2是不同的，以此为判断条件再次把数组分成两类，相同的两个数肯定会被分到同一类，然后这两个类里面的所有数异或运算得到num1和num2

## :pencil2:代码
```c++
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int hash = 0, tag = 1;
        *num1 = 0;
        *num2 = 0;
        for(int a : data){
            hash ^= a;
        }
        while((hash & 1) != 1){
            tag = tag << 1;
            hash = hash >> 1;
        }
        for(int a : data){
            if(a & tag)
                *num1 = *num1 ^ a;
            else
                *num2 = *num2 ^ a;
        }
        return;
    }
};
```