class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits_num(32, 0);
        const int m = 3;
        for (int num: nums) {
            int index = 0;
            while (num > 0) {
                bits_num[index++] += num & 1;
                num = num/2;
            }
        }
        int b = 0, res = 0;
        for (int bit: bits_num) {
            bit = bit % 3;
            res |= bit<<b;
            ++b;
        }
        return res;
    }
};