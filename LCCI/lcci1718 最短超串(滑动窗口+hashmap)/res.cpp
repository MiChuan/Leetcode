class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        vector<int> res;
        unordered_map<int, int> hashSmall;
        int count = 0, j = 0;
        for (auto e : small) {
            if (!hashSmall.count(e)) count++; // count的作用是记录small中元素的个数
            hashSmall[e]++;//初始化为1
        }
        for (int i = 0; i < big.size(); i++) {
            // 这一步的作用在于逐步扩大滑窗直至将所有的small元素包含进来
            hashSmall[big[i]]--;//small中元素值为0，非small中小于-1
            if (hashSmall[big[i]] == 0) count--;//读到small中元素
            // count为0时进入循环
            while (!count) {
                // 由于上次处理后hashSmall中对应于big中非small部分hash的value = -1，因此，其加一后为0，循环直至找到第一个属于small的值，
                // 一次处理完成
                hashSmall[big[j]]++; // 这一步不仅用于分辨是否为small中元素，还用于找到下一个滑窗的进入位置。
                if (hashSmall[big[j]] > 0) {
                    count++;
                    if (res.empty() || res[1] - res[0] > i - j) res = {j, i};
                }
                j ++;
            }
        }
        return res;
    }
};