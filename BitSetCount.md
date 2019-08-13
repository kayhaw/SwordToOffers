# 二进制中1的个数

## :question:题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

## :bulb:解决思路
基础方法：n&1看最后一位是否是1，然后n向右1一位，直到n为0，需要进行32次循环
经典方法：[Brian Kernighan](http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan)，计算n = n&(n-1)，当n最低位为1时n=n-1，当n最低位为0时，向前借位，前面的0都变成了1，首次遇到的1变成了0，也就是每进行一次n = n&(n-1)，相当于从最低位开始，依次把遇到的1变成0，直到所有位为0，此时n=0退出循环，循环次数等于1的个数

## :pencil2:代码
```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n){
             ++count;
             n = n & (n-1);
         }
         return count;
     }
};
```