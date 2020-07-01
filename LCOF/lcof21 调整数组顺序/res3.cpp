class Solution {
public:
    vector<int> exchange(vector<int>& nums) {//快慢指针
        int slow = 0,fast = 0, tmp;
        while(fast<nums.size()){
            if((nums[fast] % 2)==1){
                tmp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = tmp;
                ++slow; 
            }
            ++fast;
        }
        return nums;
    }
};