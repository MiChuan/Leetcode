class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int begin = 0, end = nums.size()-1;
        while(begin < end) {
            int s = nums[begin] + nums[end];
            if(s < target) ++begin;
            else if(s > target) --end;
            else{
                res.push_back(nums[begin]);
                res.push_back(nums[end]);
                return res;
            }
        }
        return res;
    }
};