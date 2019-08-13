# 斐波那契数列

## :question:题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
**n<=39** 

## :bulb:解决思路
注意n从0开始，斐波那契数列依次为0,1,1,2,3...，当n为0或1时返回0,1，n从2开始需要执行while循环n-1次，注意在while循环之前n还需要再减一，另外本题特地指出n<=39，因为n稍微大一点就会产生溢出

## :pencil2:代码
```c++
class Solution {
public:
    int Fibonacci(int n) {
        int a =0, b =1, c;
        if(n < 2)
            return n;
        n--;
        while(n--){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
```