class Solution {
public:
    int count = 0;
    void dfs(vector<vector<int>>& land, int i, int j) {
        if (!(i >= 0 && j >= 0 && i < land.size() && j < land[0].size()))
            return;
        if (land[i][j] == 0) {
            land[i][j] = -1;
            count++;
        } else return;                     // 注意这里，在不是0的时候，即不是水坑的时候要返回，不再遍历
        dfs(land, i - 1, j);
        dfs(land, i, j - 1);
        dfs(land, i + 1, j);
        dfs(land, i, j + 1);
        dfs(land, i - 1, j - 1);
        dfs(land, i - 1, j + 1);
        dfs(land, i + 1, j - 1);
        dfs(land, i + 1, j + 1);
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> ans;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[i].size(); j++) {
                if (land[i][j] == 0) {                 // 注意，0的时候即是水坑才进入dfs
                    dfs(land, i, j);
                    if (count != 0) {
                        ans.push_back(count);
                        count = 0;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};