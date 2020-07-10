class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,bool> resMap;
        for(int num : nums){
            if(resMap.count(num) > 0){
                resMap[num] = false;
            }
            else{
                resMap[num] = true;
            }
        }
        for (auto iter = resMap.begin(); iter != resMap.end(); ++iter) {
            if(iter->second == true) return iter->first;
        }
        return 0;
    }
};