class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a, begin = 0, upbound = nums.size()-1;
        vector<int> res;
        for(; upbound > 0 && nums[upbound] > target; --upbound);
        for(int i = 0; i <= upbound; ++i){//二分查找
            a = nums[i];
            int b = target - a;
            begin = i + 1;
            int end = upbound;
            while(begin <= end){
                int mid = (begin + end)/2;
                if(b < nums[mid]) end = mid - 1;
                else if(b > nums[mid]) begin = mid + 1;
                else{
                    res.push_back(a);
                    res.push_back(b);
                    return res;
                }
            }
        }
        return res;
    }
};