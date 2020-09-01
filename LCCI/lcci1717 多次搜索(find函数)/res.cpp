class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> res;
        if (smalls.size() == 0 || smalls[0].size() == 0) {
            res.push_back({});
            return res;
        }
        for (auto &s : smalls) {
            vector<int>ans;
            int start = 0;
            int pos = 0;
            while (pos != -1) {
                pos = big.find(s, start);
                if (pos != -1) {
                    ans.push_back(pos);
                }
                start = pos + 1;
            }
            res.push_back(ans);
        }
        return res;
    }
};