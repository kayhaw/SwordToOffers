# 旋转数组的最小数字

## :question:题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

## :bulb:解决思路
非递减排序的数组旋转一次后，旋转部分和未旋转部分都是排好序的，还是可以用二分查找，当mid元素大于high元素时，旋转部分在mid以右的区域内，low=mid+1到右边查找，当mid元素小于high元素时，mid元素可能就是最小元素，high=mid到左边查找，而不是high=mid+1，mid等于high时让high-1一步一步去试

## :pencil2:代码
```c++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int low = 0, high = rotateArray.size()-1, mid;
        while(low < high){
            mid = low + (high-low)/2;
            if(rotateArray[mid] > rotateArray[high])
                low = mid + 1;
            else if(rotateArray[mid] == rotateArray[high])
                high = high - 1;
            else
                high = mid;
        }
        return rotateArray[low];
    }
};
```