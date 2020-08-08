class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> neighbor(n); // 构造图的邻接列表
        for (auto verPair : graph) neighbor[verPair[0]].push_back(verPair[1]);
        vector<int> visited(n); // 用于记录遍历到的顶点
        return dfsSearch(neighbor, visited, start, target);
    }

    bool dfsSearch(vector<vector<int>>& neighbor, vector<int>& visited, int start, int target){
        if (start == target) return true;
        visited[start] = 1; // 将起始点添加到遍历列表中
        for (auto vertex : neighbor[start]) // 若当前顶点未遍历且以当前开始递归到返回真
            if (visited[vertex] == 0 && dfsSearch(neighbor, visited, vertex, target))  return true; 
        return false;
    }
};