class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size() != 0){
            deque<int> dq;
            for(int j = 0, i = 1 - k; j < nums.size(); ++i, ++j){
                if(i > 0 && dq.front() == nums[i-1]) dq.pop_front();//删除dq中对应nums[i-1]
                while(!dq.empty() && dq.back() <nums[j]) dq.pop_back();//保持dq递减
                dq.push_back(nums[j]);
                if(i >= 0) res.push_back(dq.front());//记录窗口最大值
            }
        }
        return res;
    }
};