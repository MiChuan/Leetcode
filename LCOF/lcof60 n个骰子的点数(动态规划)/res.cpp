class Solution {
public:
    vector<double> twoSum(int n) {
        //n <= 11
        vector<double>dp(6*n + 1, 0);//n*6的二维矩阵，优化为一维数组
        vector<double> ans;
        for(int i = 1; i <= n; i ++){//投n次
            for(int j = 6*i; j >= i; j --){
                dp[j] = 0;
                if(i == 1) {//第一颗骰子投到6面
                    dp[j] = 1;
                    continue;
                }
                for(int k = 1; k <= 6; k ++){
                    //由上一轮结果推出本轮结果
                    if(j - k >= i - 1) dp[j] += dp[j - k];
                }
            }
        }
        for(int i = n; i <= 6*n; i ++){//计算每个点数出现概率
            ans.push_back(dp[i] * pow(1.0/6, n));
        }
        return ans;
    }
};