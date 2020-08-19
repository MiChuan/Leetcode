class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        sort(s.begin(), s.end());
        dfs(s, 0, ans);
        return ans;
    }
    void dfs(string& s, int idx, vector<string>& ans) {
        if (idx == s.size()) ans.push_back(s);
        for (int i = idx; i < s.size(); ++i) {
            if (i > idx && (s[i] == s[i - 1] ||s[i] == s[idx])) continue;
            swap(s[i], s[idx]);
            dfs(s, idx + 1, ans);
            swap(s[idx], s[i]);
        }
    }
};