# 连续子数组的最大和

## :question:题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

## :bulb:解决思路
变量cur是以当前array[i]为结尾的最大子向量和,如果上一个元素结尾的cur大于0,则加上array[i],否则和就是array[i],然后cur和全局的max比较取较大值

## :pencil2:代码
```c++
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int cur = 0;
        int sum = array[0];
        int size = array.size();
        for(int i = 0; i < size; i++){
            cur = max(cur, 0) + array[i];
            sum = max(cur, sum);
        }
        return sum;
    }
};
```