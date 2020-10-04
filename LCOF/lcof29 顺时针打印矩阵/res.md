## [LCOF29 顺时针打印矩阵](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)

### 题目

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字

### 解析

设置上下左右四个边界

### 代码

```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        if(matrix.size() == 0) return out;
        int top,bottom,left,right,i,j;
        top = 0, bottom = matrix.size()-1,left = 0, right = matrix[0].size()-1;
        while(1){
            for(i=top,j=left; j<=right; ++j) {
                out.push_back(matrix[i][j]);
            }
            if(++top>bottom) break;
            for(i=top,j=right; i<=bottom; ++i){
                out.push_back(matrix[i][j]);
            }
            if(--right<left) break;
            for(i=bottom,j=right; left<=j; --j){
                out.push_back(matrix[i][j]);
            }
            if(--bottom<top) break;
            for(i=bottom,j=left; top<=i; --i){
                out.push_back(matrix[i][j]);
            }
            if(++left>right) break;
        }
        return out;
    }
};
```

