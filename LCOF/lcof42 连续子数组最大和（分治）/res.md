## [LCOF42 连续子数组的最大和](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/)

### 题目

输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

### 解析

- 分治
- 连续子数组最大和，要么出现在数组左边，要么在右边，要么跨越中点
- 求左边和右边的最大和，是当前问题的子问题，递归求解
- 跨越中点的，从中点出发分别计算左右两边的最大和，加起来即为结果

### 代码

```C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; //only one element
        return findMaxSubArray(nums,0,nums.size()-1);
    }
    int findMaxSubArray(vector<int>& sub,int low,int high){
        if (low == high) {
            return sub[low];
        }
        int mid = (low+high)/2;
        int leftsum = findMaxSubArray(sub,low,mid);
        int rightsum = findMaxSubArray(sub,mid+1,high);
        int crosssuum = findCrossMax(sub,low,mid,high);
        if(leftsum>=rightsum && leftsum>=crosssuum) return leftsum;
        else if(rightsum>=leftsum && rightsum>=crosssuum) return rightsum;
        else return crosssuum;
    }
    int findCrossMax(vector<int>& cross,int low,int mid,int high){
        if(low == high) return cross[low];
        int leftsum = INT_MIN;
        int rightsum = INT_MIN;
        int sum = 0;
        for(int i = mid;low<=i;i--){//find left half max
            sum = sum + cross[i];
            if(sum>leftsum){
                leftsum = sum;
            }
        }
        sum = 0;
        for(int j = mid+1;j<=high;j++){
            sum = sum + cross[j];
            if(sum>rightsum){
                rightsum = sum;
            }
        } 
        return leftsum+rightsum;
    }
};
```

