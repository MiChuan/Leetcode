class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> card;
        int max = 0, min = 14;
        for(int num : nums){
            if(num == 0) continue;
            max = max < num ? num : max;//最大
            min = min < num ? min : num;//最小
            if(card.count(num) > 0) return false;//重复
            card.insert(num);//添加到手牌
        }
        return max - min < 5;
    }
};