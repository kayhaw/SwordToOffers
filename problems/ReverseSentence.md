# 翻转单词顺序列

## :question:题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

## :bulb:解决思路
同上道题目类似，首先从左到右翻转每个单词序列，然后翻转整个句子。使用快指针e和满指针s，e标记空格符的位置，然后翻转s，e之间的单词，然后s移动到e的下一个位置，表示下一个单词的开始位置。**注意：退出循环后最后一个单词是没有翻转的，还需要再进行一次翻转操作**

## :pencil2:代码
```c++
class Solution {
public:
    string ReverseSentence(string str) {
        string:: iterator s, e;
        for(s = str.begin(), e = str.begin(); e != str.end(); e++){
            if(*e == ' '){
                reverse(s, e);
                s = e+1;
            }
        }
        reverse(s, e);
        reverse(str.begin(), str.end());
        return str;
    }
};
```