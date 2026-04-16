class Solution {
public:
   struct Node {
        int r, c, t;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int time = 0;
        queue<Node> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }

        while(!q.empty()){
            Node cur = q.front();
            q.pop();
            time = max(time,cur.t);

            int r = cur.r;
            int c = cur.c;
            int t = cur.t;
            if(r>0 && grid[r-1][c]==1 && !vis[r-1][c]){
                vis[r-1][c] = 1;
                q.push({r-1,c,t+1});
            }
            if(r<m-1 && grid[r+1][c]==1 && !vis[r+1][c]){
                vis[r+1][c] = 1;
                q.push({r+1,c,t+1});
            }
            if(c>0 && grid[r][c-1] ==1 && !vis[r][c-1]){
                vis[r][c-1] = 1;
                q.push({r,c-1,t+1});
            }
            if(c<n-1 && grid[r][c+1]==1 && !vis[r][c+1]){
                vis[r][c+1] = 1;
                q.push({r,c+1,t+1});
            }
        }
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                if(grid[a][b]==1 && vis[a][b]==0) return -1;
            }
        }
        return time;
    }
};
