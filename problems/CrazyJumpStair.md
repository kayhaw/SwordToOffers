# 变态跳台阶

## :question:题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

## :bulb:解决思路
令f(0)=1
当n=1时，f(1)=1;
当n=2时，f(2)=f(1)+1=2;
当n=3时，f(3)=f(2)+f(1)+1=4;
以上算式中1都表示一次跨上n级台阶，得到递推公式f(n)=f(n)+f(n-1)+f(n-2)+f(n-3)+...+f(0)，由于1=2<sup>0</sup>，2=2<sup>1</sup>，4=2<sup>2</sup>，并且有2<sup>0</sup>+2<sup>1</sup>+2<sup>2</sup>+...+2<sup>n</sup>=2<sup>n+1</sup>-1,再加上1，恰好为2<sup>n+1</sup>,所以得出结论f(n)=2<sup>n-1</sup>

## :pencil2:代码
```c++
class Solution {
public:
    int jumpFloorII(int number) {
        int a  = 1;
        while(--number){
            a = a<<1;
        }
        return a;
    }
};
```
## :ballot_box_with_check: 归纳总结
- 变态跳台阶的特殊性，台阶数为n，跳台阶的方法有1级，2级...n级共n种，此时跳法等于2<sup>n-1</sup>