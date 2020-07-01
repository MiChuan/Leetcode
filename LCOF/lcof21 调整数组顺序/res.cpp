class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int num : nums){
            (num % 2 == 0) ? even.push_back(num) : odd.push_back(num);
        }
        odd.insert(odd.end(), even.begin(), even.end());
        return odd;
    }
};