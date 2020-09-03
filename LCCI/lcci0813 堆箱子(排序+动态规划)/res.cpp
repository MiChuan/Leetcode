class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        if ( !box.size() || !box[0].size() ) return 0;
        // 可以按照任意边长排序，以下使用宽度，最终最大长度的排列，两两箱子的相对顺序一定与以下排序后的相对顺序相同（否则上面的箱子比下面的箱子宽，不满足约束）
        sort( box.begin(), box.end(), width_bigger );
        // dp一维数组用于记录第i个箱子为顶时，所能达到的最大高度。假设箱子k是能够支撑箱子i的箱子，则有状态转移方程dp[i] = dp[k] + box[i][2];
        vector<int> dp( box.size(), 0 );
        int max_height = 0;
        for ( int i = 0; i < box.size(); i++ ){
            // 寻找能够支撑箱子i的序号k
            dp[i] = box[i][2];  // i为顶，所以高度至少为box[i][2]
            for( int k = i-1; k >= 0; k-- ){
                if ( box[k][0] > box[i][0] && box[k][1] > box[i][1] && box[k][2] > box[i][2] ){
                    dp[i] = dp[i] > box[i][2] + dp[k] ? dp[i] : box[i][2] + dp[k];
                }
            }
            max_height  = max_height > dp[i] ? max_height : dp[i];
        }
        return max_height;
    }
    
    // 降序
    static bool width_bigger( const vector<int> &b1, const vector<int> &b2 ){
        return b1[0] > b2[0];
    }
};