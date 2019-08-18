# 字符流中第一个不重复的字符

## :question:题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。如果当前字符流没有存在出现一次的字符，返回#字符。

## :bulb:解决思路
用数组统计，没什么难度

## :pencil2:代码
```c++
class Solution
{
public:
  //Insert one char from stringstream
    string s;
    int hash[256]={0};
    void Insert(char ch)
    {
        s += ch;
        hash[ch] += 1;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(auto c : s)
            if(hash[c] == 1)
                return c;
        return '#';
    }

};
```