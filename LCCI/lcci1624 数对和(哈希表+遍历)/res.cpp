class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<vector<int>>res;
        for(auto i : nums){
            if(m[target-i]>0){
                m[target-i]--;
               res.push_back({target-i,i}); 
            }
            else m[i]++;
        }
        return res;
    }
};