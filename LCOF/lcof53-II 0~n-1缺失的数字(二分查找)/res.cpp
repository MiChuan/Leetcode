class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums[0] == 0){
            for(int i = 0; i < nums.size(); ++i){
                if(i == nums.size()-1) return nums[nums.size()-1] + 1;
                else if(nums[i] == nums[i+1] - 2) return nums[i] + 1;
            }
        }
        return 0;
    }
};