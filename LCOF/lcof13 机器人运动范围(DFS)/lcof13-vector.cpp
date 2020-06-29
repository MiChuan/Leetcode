class Solution {
public:
    int m,n,k;
    vector<vector<bool>> visited;
    int movingCount(int m, int n, int k) {
        this->m = m, this->n = n, this->k = k;
        visited.resize(m,vector<bool>(n));
        return dfs(0, 0, 0, 0);
    }
    int dfs(int i,int j,int si,int sj){
        if(i>=m||j>=n||k<si+sj||visited[i][j]) return 0;
        visited[i][j]=true;
        return 1 + dfs(i+1,j,(i+1)%10!=0?si+1:si-8,sj) + dfs(i,j+1,si,(j + 1) % 10 != 0 ? sj + 1 : sj - 8);
    }
};