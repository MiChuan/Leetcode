### [lcof04 二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

### 题目

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

### 解析

- 每列第一个最小，每行最后一个最大
- 利用右上角元素进行比较，小于该元素小于该列元素，大于该元素大于该行元素
- 注意边界

### 代码

```C++
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int row = 0, col = matrix[0].size()-1;
        while(row<matrix.size() && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) --col;
            else ++row;
        }
        return false;
    }
};
```

