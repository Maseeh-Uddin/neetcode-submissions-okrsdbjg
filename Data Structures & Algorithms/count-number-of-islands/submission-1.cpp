class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){

            if(grid[i][j]=='1' && !vis[i][j]){
                bfs(grid,vis,i,j);
                count++;
            } 
            }
        }
        return count;
        
    }
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis,int i, int j){
        int count = 0;

        queue<pair<int,int>> q;

        q.push({i,j});
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()){
            pair<int,int>  node= q.front();
            q.pop();
            i = node.first;
            j = node.second; 
            vis[i][j] = 1;
            if(i>0 && grid[i-1][j]=='1' && !vis[i-1][j]) q.push({i-1,j});
            if(i<m-1 && grid[i+1][j]=='1' && !vis[i+1][j]) q.push({i+1,j});
            if(j>0 && grid[i][j-1]=='1' && !vis[i][j-1]) q.push({i,j-1});
            if(j<n-1 && grid[i][j+1]=='1' && !vis[i][j+1]) q.push({i,j+1});
        }
        return;
    }
};
