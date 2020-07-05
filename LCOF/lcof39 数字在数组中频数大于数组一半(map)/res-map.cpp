class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> numMap;
        map<int,int>::iterator it;
        int size = nums.size()/2;
        for(int num : nums){
            if((it = numMap.find(num)) != numMap.end()){
                ++numMap[num];
            }
            /*if(numMap.count(num) > 0){
                ++numMap[num];
            }*/
            else{
                numMap[num] = 0;
            }
            if(numMap[num] >= size) return num;
        }
        return 6;
    }
};