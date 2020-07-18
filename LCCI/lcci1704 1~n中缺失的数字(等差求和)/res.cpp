class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int count = n * (1 + n) / 2;
        for(int num : nums){
            count -= num;
        }
        return count;
    }
};