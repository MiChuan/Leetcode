class Solution 
{
    private:
        int rows;
        int cols;
        vector<vector<int>> path;

    public:
        bool findPath(vector<vector<int>>& obstacleGrid, int x, int y)
        {
            if(obstacleGrid[x][y] == 1) return false;
            
            path.push_back({x, y});

            if(x+1 == rows && y+1 == cols) return true;
            if(x+1 < rows && findPath(obstacleGrid, x+1, y)) return true;
            if(y+1 < cols && findPath(obstacleGrid, x, y+1)) return true;

            path.pop_back();
            obstacleGrid[x][y] = 1;
            return false;
        }

        vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) 
        {
            rows = obstacleGrid.size();
            cols = obstacleGrid[0].size();

            if(!rows && !cols) return path;
            findPath(obstacleGrid, 0, 0);

            return path;
        }
};