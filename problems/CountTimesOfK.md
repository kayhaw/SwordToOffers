# 数字在排序数组中出现的次数。

## :question:题目描述
统计一个数字在排序数组中出现的次数。

## :bulb:解决思路
排序数组想到用二分法，确定数字出现的上界和下界，然后相减即可，这里巧妙用k±0.5来进行搜索

## :pencil2:代码
```c++
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return BinSearch(data, k+0.5) - BinSearch(data, k-0.5);
    }
    int BinSearch(vector<int> &data, double k) {
        int left = 0, right = data.size()-1;
        while(left <= right) {
            int mid = left + ((right-left)>>1);
            if(data[mid] < k)
                left = mid+1;
            else
                right = mid-1;
        }
        return left;
    }
};
```