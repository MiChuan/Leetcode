class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size() != 0){
            for(int i = 0; i <= nums.size()-k; ++i){
                int max = nums[i];
                for(int j = i; j < i + k; ++j){
                    if(nums[j] > max) max = nums[j];
                }
                res.push_back(max);
            }
        }
        return res;
    }
};