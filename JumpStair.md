# 跳台阶

## :question:题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

## :bulb:解决思路
子问题分解：跳上n级台阶最后一步要么是1级上来的，要么是2级上来的，有递推公式f(n)=f(n-1)+f(n-2)，初始值f(1)=1，f(2)=2，本质上还是斐波那契数列的求解
**代码还是没有考虑n过大导致溢出的问题**

## :pencil2:代码
```c++
class Solution {
public:
    int jumpFloor(int number) {
       int a = 0, b = 1, c;
        while(number--){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
```