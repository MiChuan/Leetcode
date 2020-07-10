class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < board.size(); ++row){
            for(int col = 0; col < board[0].size(); ++col){
                if (dfs(board, word, row, col, 0)) return true;//搜索矩阵所有元素
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int strIndex){
        if(row >= board.size() || row < 0 || col >= board[0].size() || 
            col < 0 || board[row][col] != word[strIndex]) return false;//越界或不匹配
        if(strIndex + 1 == word.size()) return true;//匹配完毕
        char tmp = board[row][col];//标记已检索
        board[row][col] = '/';
        bool res = dfs(board, word, row+1, col, strIndex+1) || 
            dfs(board, word, row-1, col, strIndex+1) ||
            dfs(board, word, row, col+1, strIndex+1) ||
            dfs(board, word, row, col-1, strIndex+1);//检索当前位置下上右左与下一个字符是否匹配
        board[row][col] = tmp;//恢复标记字符
        return res;
    }
};