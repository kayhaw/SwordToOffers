# 数组中出现次数超过一般的数字

## :question:题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

## :bulb:解决思路
1. 使用map统计每个数字出现次数，然后依次找出次数多于一半的数字
2. 次数相消法，选第一个数为x，出现次数times为1，遍历数组值，值等于x则times加1，否则减1，若times为0，将x设为当前数组值，注意当不存在出现次数大于一半时，这种方法选出来的不一定是正确结果，所以还要再循环遍历一遍数组来确认到底次数有没有大于一半

## :pencil2:代码1
```C++
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.size() == 0)
            return res;
        Permutation(res, str, 0);
        sort(res.begin(), res.end());
        return res;
    }
    void Permutation(vector<string> &array, string str, int begin){
        if(begin == str.size()-1)
            array.push_back(str);
        for(int i = begin; i < str.size(); ++i){
            if(i != begin && str[i]==str[begin])
                continue;
            swap(str[i], str[begin]);
            Permutation(array, str, begin+1);
            swap(str[i], str[begin]);
        }
    }
};
```
## :pencil2:代码2
```C++
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int x = numbers[0], times = 1;
        for(int i = 1; i < numbers.size(); ++i){
            if(times == 0){
                x = numbers[i];
                times = 1;
            }else if(x == numbers[i])
                ++times;
            else
                --times;
        }
        times = 0;
        for(int y : numbers)
            if(x == y)
                ++times;
        return (times > numbers.size()/2) ? x : 0;
    }
};
```