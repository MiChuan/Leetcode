class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        long sum = 0;
        for (auto x: nums) sum += x;

        int sumTwo = n * (n + 1) / 2 - sum, limits = sumTwo / 2;
        sum = 0;
        for (auto x: nums)
            if (x <= limits) sum += x; // 两个数不相同那么一个大于，一个小于
        int one = limits * (limits + 1) / 2 - sum;
        return {one, sumTwo - one};
    }
};