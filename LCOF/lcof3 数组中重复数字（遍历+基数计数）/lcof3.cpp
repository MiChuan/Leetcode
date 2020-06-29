class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int* count = new int[nums.size()];//根据nums大小动态分配
        for(int i=0; i<nums.size(); ++i) count[i] = 0;
        int i;
        for(i=0; i<nums.size(); ++i){
            ++count[nums[i]];
            if(count[nums[i]]>1){
                delete []count;
                break; 
            } 
        }
        return nums[i];
    }
};