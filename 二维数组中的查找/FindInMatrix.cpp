#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > &array) {
        int row = array.size();
        int cloumn = array[0].size();
        
        for(int i = row-1, j = 0; i>=0 && j < cloumn;){
            if(target == array[i][j]){
                return true;
            }else if(target < array[i][j]){
                i--;
                continue;
            }else{
                j++;
                continue;
            }
        }
        return false;
    }
};