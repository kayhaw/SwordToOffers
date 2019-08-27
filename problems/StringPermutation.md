# 字符串的排列

## :question:题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。输入字符串长度不超过9(可能有字符重复),字符只包括大小写字母。

## :bulb:解决思路
递归方法，依次固定字符串的首字符，对剩余序列进行全排列，得到所有字符的全排列，然后排序输出

## :pencil2:代码
```c++
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.size() == 0)
            return res;
        Permutation(res, str, 0);
        sort(res.begin(), res.end());
        return res;
    }
    void Permutation(vector<string> &array, string str, int begin){
        if(begin == str.size()-1)
            array.push_back(str);
        for(int i = begin; i < str.size(); ++i){
            if(i != begin && str[i]==str[begin])
                continue;
            swap(str[i], str[begin]);
            Permutation(array, str, begin+1);
            swap(str[i], str[begin]);
        }
    }
};
```