class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 1; i <= n + 2; i ++) ans ^= i;
        for (auto x: nums) ans ^= x;

        int one = 0;
        int diff = ans & -ans; 
        for (int i = 1; i <= n + 2; i ++)
            if (diff & i) one ^= i; // ?
        for (auto x: nums)
            if (diff & x) one ^= x;
        return {one, one ^ ans};
    }
};