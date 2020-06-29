class Solution {
public:
    int m,n,k;
    int** visited;
    int movingCount(int m, int n, int k) {
        this->m = m, this->n = n, this->k = k;
        this->visited = new int*[m];
        for(int i = 0; i < m; ++i){
            visited[i] = new int[n];
        }
        int res = dfs(0, 0, 0, 0);
        for(int i = 0; i < m; ++i){//释放动态数组防止内存泄漏
            delete [] visited[i];
        }
        return res;
    }
    bool dfs(int row, int col, int sumR, int sumC){
        if(row >= m || col >= n || k < sumR+sumC || visited[row][col]==1) return 0;//越界或访问过
        visited[row][col] = 1;
        //向下、向右搜索
        return 1 + dfs(row + 1, col, (row + 1) % 10 != 0 ? sumR + 1 : sumR - 8, sumC) +
            dfs(row, col + 1, sumR, (col + 1) % 10 != 0 ? sumC + 1 : sumC - 8);
    }
};