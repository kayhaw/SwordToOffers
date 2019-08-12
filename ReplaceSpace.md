# 替换空格

## :question:题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

## :bulb:解决思路
从题目给的函数原型来看，需要在原来字符串的地址空间上实现空格替换。首先需要意识到简单地从头开始遇到空格是不可行的，这样的话每次替换一次空格后面的所有字符需要整体挪动一次（代码复杂，效率低下），既然如此，那倒不如从后往前进行替换，前提是需要知道原来非空字符会挪动到那个位置，显然跟在它前面的空格个数有关，所以要先遍历一遍字符串统计空格的个数count，然后从末尾字符开始（注意，是从'\0'开始），非空字符向后挪动count×2个位置，空字符则依次向前赋值'0','2','%'，还需要注意count减一，表示完成了一个空格字符的替换。

## :pencil2:代码
```c++
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i = 0; i < length; i++){
            if(str[i] == ' '){
                count++;
            }
        }
        for(int i = length; i >=0; i--){
            if(str[i] != ' '){
                str[i+count*2] = str[i];
            } else {
                str[i+count*2] = '0';
                str[i+count*2-1] = '2';
                str[i+count*2-2] = '%';
                count--;
            }
        }
    }
};
```
## :ballot_box_with_check: 归纳总结
- 字符串的原地字符替换(充足空间)，从后往前进行操作
- offset=(strlen(替换成的字符串) - 1)*count
- 注意替换完成后count-1