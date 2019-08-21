# 矩阵中的路径

## :question:题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bccced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

## :bulb:解决思路
添加辅助数组记录已经访问过的位置，使用递归回溯判断是否存在蛮子条件的位置

## :pencil2:代码
```c++
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        int *flag = new int[strlen(matrix)]();
        for(int i = 0; i < rows; i++) {
            for(int j= 0; j < cols; j++) {
                if(match(matrix, rows, cols, i, j, str, 0, flag))
                    return true;
            }
        }
        return false;
    }
    
    bool match(char* matrix, int rows, int cols, int i, int j, char* str, int k, int* flag) {
        int index = i * cols + j;
        if(i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index]) {
            return false;
        }
        if(k == strlen(str)-1)
            return true;
        //回溯试探，标记为1
        flag[index] = 1;
        if(match(matrix, rows, cols, i-1, j, str, k+1, flag) || \
            match(matrix, rows, cols, i+1, j, str, k+1, flag) || \
            match(matrix, rows, cols, i, j-1, str, k+1, flag) || \
            match(matrix, rows, cols, i, j+1, str, k+1, flag)) {
            return true;
        }
        //检测失败，重新置为0
        flag[index] = 0;
        return false;
    }
};
```