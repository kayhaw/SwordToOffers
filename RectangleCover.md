# 矩形覆盖

## :question:题目描述
我们可以用2\*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2\*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

## :bulb:解决思路
设2×n大矩形高为2，宽为n
- 使用2*1竖着覆盖，剩下的部分等于宽为n-1的大矩形，
- 使用2*1横着覆盖，大矩形高为2，下一块的摆放也只能横着覆盖,剩下的部分等于宽为n-2的大矩形
因此，f(n)=f(n-1)+f(n-2)，转为求解斐波那契数列

## :pencil2:代码
```c++
class Solution {
public:
    int rectCover(int number) {
        int a = 0, b = 1, c;
        if(number == 0)
            return 0;
        while(number--){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
```