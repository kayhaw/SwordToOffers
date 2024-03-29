# 整数中1出现的次数(从1到n整数中1出现的次数)

## :question:题目描述
求出1\~13的整数中1出现的次数,并算出100\~1300的整数中1出现的次数？为此他特别数了一下1\~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。


## :bulb:解决思路
[编程之美上的题目](https://www.cnblogs.com/cyjb/p/digitOccurrenceInRegion.html)

## :pencil2:代码
```c++
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int high, low, curr, tmp, i = 1;
        high = n;
        int total = 0;
        while(high != 0) {
            high = n/(int)pow(10, i);
            tmp = n%(int)pow(10, i);
            curr = tmp/(int)pow(10, i-1);
            low = tmp%(int)pow(10, i-1);
            if(curr == 1)
                total += high*(int)pow(10, i-1)+low+1;
            else if(curr < 1)
                total += high*(int)pow(10, i-1);
            else
                total += (high+1)*(int)pow(10, i-1);
            i++;
        }
        return total;
    }
};
```