class Solution {
private:
    int ans = -1;
public:
    int findMagicIndex(vector<int>& nums) {
        biSearch(0, nums.size() - 1, nums);
        return ans;
    }

    bool biSearch(int l, int r, vector<int>& nums) {
        if (l > r) return false;
        int mid = (l + r) >> 1;
        if (mid == nums[mid]) {
            ans = mid;
            biSearch(l, mid - 1, nums);
            return true; //找到魔术索引
        }
        if (biSearch(l, mid - 1, nums)) return true;
        return biSearch(mid + 1, r, nums);
    }
};