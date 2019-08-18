# 构建乘积数组

## :question:题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

## :bulb:解决思路
首先计算公式左边：1，A[0], A[0]*A[1], ... A[0]*A[1]\*...*A[n-2]    
然后计算公式右边：A[n-1]\*...*A[1]，A[n-1]\*...*A[2], ..., 1
左边一次对应乘右边就是结果，公式特点都是在原来基础上乘以后 (前)数组元素得到

## :pencil2:代码
```c++
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> mul;
        int tmp=1;
        int s = A.size();
        if(!s)
            return mul;
        //减一很关键
        mul.push_back(1);
        for(int i = 0; i < s-1; i++){
            mul.push_back(mul.back()*A[i]);
        }
        for(int i = s-1; i >=0; i--){
            mul[i] *= tmp;
            tmp *= A[i];
        }
        return mul;
    }
};
```