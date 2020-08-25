class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>> tmp;
        for(int i = 0; i < height.size(); i++) tmp.push_back({height[i], weight[i]});
        sort(tmp.begin(), tmp.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
        vector<int> dp; //长度为N的地方 最小的数字
        for(const auto &[h, w]: tmp) {
            auto p = lower_bound(dp.begin(), dp.end(), w);  //二分查找第一个大于等于的地方
            if(p == dp.end()) dp.push_back(w);
            else *p = w;
        }
        return dp.size();
    }
};