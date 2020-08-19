class Solution {
public:
    vector<string> permutation(string S) {
         vector<string> ret;
         dfs(ret, 0, S);
         return ret;
    }

    void dfs(vector<string>& ret, int index, string s) {
        if (index >= s.size()) {
            ret.push_back(s);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            swap(s[i], s[index]);
            dfs(ret, index + 1, s);
            swap(s[i], s[index]);
        }
    }
};