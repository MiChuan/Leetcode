class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        size_t idx = 0, len = nums.size();
        if (len < 3) return;
        size_t low = 0, high = len - 1;
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        while (low < high) {
            nums[idx++] = sorted[high--];
            nums[idx++] = sorted[low++];
        }
        if (len % 2 > 0) nums[idx] = sorted[low];
    }
};