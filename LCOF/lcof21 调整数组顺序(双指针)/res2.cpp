class Solution {
public:
    vector<int> exchange(vector<int>& nums) {//头尾双指针
        int i = 0, j = nums.size() - 1, tmp;
        while(i < j) {
            while(i < j && (nums[i] % 2) == 1) i++;
            while(i < j && (nums[j] % 2) == 0) j--;
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        return nums;
    }
};