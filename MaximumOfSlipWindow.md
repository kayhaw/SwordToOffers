# 滑动窗口的最大值

## :question:题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

## :bulb:解决思路
使用双端队列维护窗口下标，当前元素比队列末尾元素大，pop末尾元素，当队首超过当前滑动窗口范围，pop队首元素，然后统一push当前元素，窗口满时保存当前窗口的最大值

## :pencil2:代码
```c++
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        deque<int> que;
        vector<int> res;
        
        for(int i = 0; i < num.size(); ++i) {
            while(que.size() && num[que.back()] <= num[i])
                que.pop_back();
            while(que.size() && i-que.front()+1>size)
                que.pop_front();
            que.push_back(i);
            if(size && i+1>=size)
                res.push_back(num[que.front()]);
        }
        return res;
    }
};
```