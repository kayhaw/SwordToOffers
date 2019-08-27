# 把数组排成最小的数

## :question:题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

## :bulb:解决思路
拼数的想法：长度相同的数字小的在前边，长度不同的依次比较，首先出现较小数位的在前面，这样的比较思路写代码很难，如果直接把两个数都转为string，然后正反拼在一起，这样长度相同就好比较了，即实现一个compare函数，根据这个函数对数组排序然后依次拼接在一起就是最后的结果，注意compare类函数必须是static类型的。

## :pencil2:代码
```c++
class Solution {
public:
    static bool compare(int &a, int &b){
        string A, B;
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);
        return A < B;
    }
    string PrintMinNumber(vector<int> numbers) {
        string res;
        sort(numbers.begin(), numbers.end(), compare);
        for(auto num : numbers){
            res += to_string(num);
        }
        return res;
    }
};
```