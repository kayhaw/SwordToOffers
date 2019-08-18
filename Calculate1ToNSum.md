# 求1+2+3+...+n

## :question:题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

## :bulb:解决思路
递推公式要用到乘法，不可行，两种方法：
- 递归配合&&
- sizeof

## :pencil2:代码
```c++
class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n-1));
        return ans;
    }
};
```
```C++
class Solution {
public:
    int Sum_Solution(int n) {
        bool a[n][n+1];
        return sizeof(a)>>1;
    }
};
```