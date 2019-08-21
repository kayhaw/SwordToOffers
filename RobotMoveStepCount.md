# 机器人的运动范围

## :question:题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

## :bulb:解决思路
类似于上一道题，这里要注意搜索的是机器人能够按照要求一步一步走达到的格子，如果某个方格满足行坐标和列坐标的数位之和大于k但是它四周的方格都不满足，机器人是不能到达这个格子的，使用广度优先，每到达一个新的方格，记录位置，总数res加1，然后朝上下左右四个方向继续探索

## :pencil2:代码
```c++
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int res = 0;
        char* visited = new char[rows*cols];
        memset(visited, 0, rows*cols);
        countSteps(threshold, rows, cols, 0, 0, visited, res);
        return res;
    }
    void countSteps(int &threshold, int &rows, int &cols, int r, int c, char *visited, int &res)
    {
        if(r < 0 || r >= rows || c < 0 || c >= cols || visited[r*cols+c] || !check(r, c, threshold))
            return;
        else{
            ++res;
            visited[r*cols+c] = 1;
            countSteps(threshold, rows, cols, r-1, c, visited, res);
            countSteps(threshold, rows, cols, r, c-1, visited, res);
            countSteps(threshold, rows, cols, r+1, c, visited, res);
            countSteps(threshold, rows, cols, r, c+1, visited, res);
        }
    }
    bool check(int r, int c, int &threshold){
        int sum = 0;
        while(r != 0){
            sum += r % 10;
            r /= 10;
        }
        while(c != 0){
            sum += c % 10;
            c /= 10;
        }
        return sum <= threshold;
    }
};
```