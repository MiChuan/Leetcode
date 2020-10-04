## [LCOF59 - I 滑动窗口的最大值](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)

### 题目

给定一个数组 `nums` 和滑动窗口的大小 `k`，请找出所有滑动窗口里的最大值。

示例:

```
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值

[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

### 解析

两个指针作为窗口左右边界，维护一个递减的双端队列，当前窗口最大值在队列头部

### 代码

```C++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size() != 0){
            deque<int> dq;
            for(int j = 0, i = 1 - k; j < nums.size(); ++i, ++j){//i为窗口左边界,j为右边界
                if(i > 0 && dq.front() == nums[i-1]) dq.pop_front();//删除dq中对应nums[i-1]
                while(!dq.empty() && dq.back() <nums[j]) dq.pop_back();//保持dq递减
                dq.push_back(nums[j]);
                if(i >= 0) res.push_back(dq.front());//记录窗口最大值
            }
        }
        return res;
    }
};
```

