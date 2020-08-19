class Solution {
public:
    int countEval(string s, int result) {
        // 1, 2, 3
        // 1->2->3, 3->2->1
        // 1^1, 2^2, 3^3;
        if (s.empty()) return 0; 
        if (s.size() == 1) return s[0] - '0' == result;
        
        int n = s.size(), m = n / 2;
        int f[m][m][2]; 
        memset(f, 0, sizeof f);
        
        for (int len = 1; len <= m; len ++)
            for (int i = 0; i + len - 1 < m; i ++) {
                int j = i + len - 1;
                if (len == 1) {
                    int t = i * 2;
                    f[i][j][get(s[t + 1], s[t] - '0', s[t + 2] - '0')] = 1;
                } else {
                    for (int k = i; k <= j; k ++) { // 一定要保证状态划分的边界线正确
                        int t = k * 2;
                        if (k == i) { 
                            if (f[k + 1][j][0]) f[i][j][get(s[t + 1], s[t] - '0', 0)] += f[k + 1][j][0];
                            if (f[k + 1][j][1]) f[i][j][get(s[t + 1], s[t] - '0', 1)] += f[k + 1][j][1];
                        } else if (k == j) {
                            if (f[i][k - 1][0]) f[i][j][get(s[t + 1], s[t + 2] - '0', 0)] += f[i][k - 1][0];
                            if (f[i][k - 1][1]) f[i][j][get(s[t + 1], s[t + 2] - '0', 1)] += f[i][k - 1][1];
                        } else {
                            if (f[i][k - 1][0] && f[k + 1][j][0]) f[i][j][get(s[t + 1], 0, 0)] += f[i][k - 1][0] * f[k + 1][j][0];
                            if (f[i][k - 1][0] && f[k + 1][j][1]) f[i][j][get(s[t + 1], 0, 1)] += f[i][k - 1][0] * f[k + 1][j][1];  
                            if (f[i][k - 1][1] && f[k + 1][j][0]) f[i][j][get(s[t + 1], 1, 0)] += f[i][k - 1][1] * f[k + 1][j][0];
                            if (f[i][k - 1][1] && f[k + 1][j][1]) f[i][j][get(s[t + 1], 1, 1)] += f[i][k - 1][1] * f[k + 1][j][1];  
                        }
                        // cout << k << ',' << f[i][j][0] << ',' << f[i][j][1] << endl;
                    }
                    // if (i == 2 && j == 3) exit(0);
                }
            }
        return f[0][m - 1][result];
    }
    
    bool get(char op, int t1, int t2) {
        if (op == '^') return t1 ^ t2;
        if (op == '|') return t1 | t2;
        return t1 & t2;
    }
};