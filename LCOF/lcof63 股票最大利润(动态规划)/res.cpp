class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        for(int price : prices) {
            cost = cost < price ? cost : price;
            profit = profit > price - cost ? profit : price - cost;
        }
        return profit;
    }
};