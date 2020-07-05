class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i : nums) 
            if (++ map[i] > nums.size() / 2) return i;
        return 0;
    }
};