# 数值的整数次方

## :question:题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

## :bulb:解决思路
首先要考虑指数的正负性
- 指数为0，返回1
- 指数为负数，去掉负号求幂再返回其倒数
- 指数为正数，使用快速求幂法：从低到高遍历指数的二进制，为1乘base，同时base平方，相比于exponent-1直到为0的循环次数减少

## :pencil2:代码
```c++
class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1, curr = base;
        int n;
        if(exponent < 0){
            if(base == 0)
                return -1;
            n = -exponent;
        }else if(exponent > 0){
            n = exponent;
        }else{
            return 1;
        }
        while(n != 0){
            if(n & 1)
                res *= curr;
            curr *= curr;
            n>>=1;
        }
        return exponent > 0 ? res : (1/res);
    }
};
```