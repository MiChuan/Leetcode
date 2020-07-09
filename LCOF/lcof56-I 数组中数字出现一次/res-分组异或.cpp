class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        //用于将所有的数异或起来
        int k = 0;
        for(int num: nums) {
            k ^= num;
        }
        //获得k中最低位的1
        int mask = 1;
        while((k & mask) == 0) {
            mask <<= 1;
        }
        int a = 0;
        int b = 0;
        for(int num: nums) {
            if((num & mask) == 0) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        res.push_back(a), res.push_back(b);
        return res;
    }
};