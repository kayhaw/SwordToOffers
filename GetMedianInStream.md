# 数据流中的中位数

## :question:题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

## :bulb:解决思路
一个最大堆，一个最小堆，分成较小数和较大数两部分，并且确保最小堆的体积比最大堆的体积大1或者0，这样当总数为偶数时中位数为两个堆顶元素平均值，否则为最小堆顶

## :pencil2:代码
```c++
class Solution {
public:
    priority_queue<int, vector<int>, less<int>> smaller;
    priority_queue<int, vector<int>, greater<int>> bigger;
    void Insert(int num)
    {
        if(smaller.empty() || num < smaller.top())
            smaller.push(num);
        else
            bigger.push(num);
        if(smaller.size() == bigger.size() + 2)
            bigger.push(smaller.top()), smaller.pop();
        if(smaller.size() + 1 == bigger.size())
            smaller.push(bigger.top()), bigger.pop();
    }

    double GetMedian()
    {
        return smaller.size() == bigger.size() ? (smaller.top()+bigger.top())/2.0 : smaller.top();
    }

};
```