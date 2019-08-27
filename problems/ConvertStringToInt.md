# 把字符串转换成整数

## :question:题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
>输入：一个字符串,包括数字字母符号,可以为空
输出：如果是合法的数值表达则返回该数字，否则返回0

## :bulb:解决思路
字符串转10进制数的总结
- 初始化结果num为0
- 确定符号flag，首字符为-则flag为false，为+则flag为true，因为+可以不用写表示正数，flag初始化为为true表示正数
- 遇到数字字符，首先是num*=10！然后num加上表示的数
- 其他情况转换失败返回0

## :pencil2:代码
```c++
class Solution {
public:
    int StrToInt(string str) {
        int num = 0;
        bool flag = true;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '-' && i==0){
                flag = false;
            }else if(str[i] == '+' && i==0){
                flag = true;
            }else if(str[i] >= '0' && str[i] <= '9'){
                num *= 10;
                num += str[i]-'0';
            }else{
                return 0;
            }
        }
        return flag ? num : -num;
    }
};
```