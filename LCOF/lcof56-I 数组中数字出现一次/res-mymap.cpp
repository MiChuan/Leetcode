class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        map<int,bool> resMap;
        vector<int> res;
        for(int num : nums){
            if(resMap.count(num) > 0){
                resMap[num] = false;
            }
            else{
                resMap[num] = true;
            }
        }
        for (auto iter = resMap.begin(); iter != resMap.end(); ++iter) {
            if(iter->second == true) res.push_back(iter->first);
        }
        return res;
    }
};