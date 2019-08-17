# 左旋转字符串

## :question:题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

## :bulb:解决思路
三次翻转法完成循环移动
- 循环左移n等于循环右移s-n，s为字符串长度
- n大于s时取n = n % s;

## :pencil2:代码
```c++
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(!str.length())
            return str;
        n = n % str.length();
        reverse(str.begin(), str.begin()+n);
        reverse(str.begin()+n, str.end());
        reverse(str.begin(), str.end());
        return str;
    }
};
```