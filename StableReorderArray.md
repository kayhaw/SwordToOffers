# 斐波那契数列

## :question:题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

## :bulb:解决思路
相对位置不变即所采用的排序算法要是稳定的，选择一个最简单，也最容易理解的冒泡排序，从尾向前让依次奇数冒泡到前面

## :pencil2:代码
```c++
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int t;
        for(int i=0; i < array.size(); i++){
            for(int j=array.size()-1; j > i; j--){
                if(!(array[j-1]%2) && array[j]%2){
                    swap(array[j-1], array[j]);
                }
            }
        }
    }
};
```