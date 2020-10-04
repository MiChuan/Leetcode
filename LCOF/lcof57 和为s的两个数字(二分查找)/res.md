## [LCOF57 和为s的两个数字](https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/)

### 题目

输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

### 解析

前后双指针

### 代码

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int begin = 0, end = nums.size()-1;
        for(; end > 0 && nums[end] > target; --end); //筛掉大于target的数
        while(begin < end) {
            int s = nums[begin] + nums[end]; //前后元素相加
            if(s < target) ++begin; //和小于target，前指针后移
            else if(s > target) --end; //和大于target，后指针前移
            else{//和等于target
                res.push_back(nums[begin]);
                res.push_back(nums[end]);
                return res;
            }
        }
        return res;
    }
};
```

