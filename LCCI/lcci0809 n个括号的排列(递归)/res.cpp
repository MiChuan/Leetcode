class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        help(n, n, "");
        return ans;
    }

    void help(int l, int r, string a) {
        if (l == 0 && r == 0) {
            ans.emplace_back(a);
            return;
        }
        if (l != 0) help(l - 1, r, a + '(');
        if (l < r) help(l, r - 1, a + ')');
    }
};