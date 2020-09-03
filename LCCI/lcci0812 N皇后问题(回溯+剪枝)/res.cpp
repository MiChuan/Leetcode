class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> l;
        lineByLine(l,n);
        return res;
    }
    /* 逐行遍历 */
    void lineByLine(vector<int>& placed, int& n){
        if(placed.size() == n) {res.push_back(placedResult(placed)); return;}   // 摆放完毕, 此时的placed就是结果之一
        vector<bool> placable(toPlacable(placed,n));    // 调用toPlacable(), 得到当前可放置位
        for(int i=0; i<n; ++i){     // 遍历placable, 0为不可摆放, 1为可摆放
            if(placable[i]){
                auto tmp = placed;
                tmp.push_back(i);       // 在placed中加入一个placable位置, 遍历下一行
                lineByLine(tmp,n);
            }
        }
    }
    /* 根据placed计算placable */
    vector<bool> toPlacable(vector<int>& placed, int& n) {
        vector<bool> subres(n,true);
        for(int i=0, s=placed.size(); i<s; ++i){
            if(placed[i]+s-i < n) subres[placed[i]+s-i] = 0;
            if(placed[i]-s+i >=0) subres[placed[i]-s+i] = 0;	// 左下,右下,正下,三个方向都不能放皇后
            subres[placed[i]] = 0;
        }
        return subres;
    }
    /* 将placed转换为二维摆放图 */
    vector<string> placedResult(vector<int>& placed){
        vector<string> subres(placed.size(),string(placed.size(),'.'));//N个字符串，每个串N个‘.’字符
        for(int i=0; i<placed.size(); ++i) subres[i][placed[i]] = 'Q';
        return subres;
    }
};