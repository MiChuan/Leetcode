class Solution {
public:
    int missingNumber(vector<int>& nums) {//二分法
        int i = 0, j = nums.size() - 1;
        if(nums[0] == 0){
            while(i <= j) {
                int m = (i + j) / 2;
                if(nums[m] == m) i = m + 1;
                else j = m - 1;
            }
        }
        return i;
    }
};