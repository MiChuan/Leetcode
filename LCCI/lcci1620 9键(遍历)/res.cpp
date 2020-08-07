class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<char> mp = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
        int n1 = num.size(), i;
        vector<string> ans;
        for (string& w : words) {
            for (i = 0; i < n1; ++i) if (mp[w[i] - 'a'] != num[i]) break;
            if (i == n1) ans.push_back(w);
        }
        return ans;
    }
};