class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        vector<vector<int>> vis = vector<vector<int>>(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col){
        queue<pair<int,int>> q;

        q.push(pair<int,int>{row,col});
        vis[row][col] = 1;

        while(!q.empty()){
            pair<int,int> node = q.front();
            int i = node.first;
            int j = node.second;
            q.pop();

            if(i>=0 && j>=1 && grid[i][j-1]=='1' && !vis[i][j-1]){
                q.push(pair<int,int>{i,j-1});
                vis[i][j-1] = 1;
            }
            if(i>=0 && j<grid[i].size()-1 && grid[i][j+1]=='1' && !vis[i][j+1]){
                q.push(pair<int,int>{i,j+1});
                vis[i][j+1] = 1;
            }
            if(i>=1 && j>=0 && grid[i-1][j]=='1' && !vis[i-1][j]){
                q.push(pair<int,int>{i-1,j});
                vis[i-1][j] = 1;
            }
            if(i<grid.size()-1 && j>=0 && grid[i+1][j]=='1' && !vis[i+1][j]){
                q.push(pair<int,int>{i+1,j});
                vis[i+1][j] = 1;
            }
            
        }
        return;
    }
};
