class Solution {
    struct Node{
        int r,c,d;
    };
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));

        queue<Node> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) q.push({i,j,1});
            }
        }

        while(!q.empty()){
            Node node = q.front();
            q.pop();

            int r = node.r;
            int c = node.c;
            int d = node.d;

            //vis[r][c] = min(vis[r][c], d);
cout<<r<<" "<<c<<endl;
            if(r>0 && grid[r-1][c]==INT_MAX && vis[r-1][c]==-1){
                q.push({r-1,c,d+1});
                vis[r-1][c] = d;
            }
            if(r<m-1 && grid[r+1][c]==INT_MAX && vis[r+1][c]==-1){
                q.push({r+1,c,d+1});
                vis[r+1][c] = d;
            }
            if(c>0 && grid[r][c-1]==INT_MAX && vis[r][c-1]==-1){
                q.push({r,c-1,d+1});
                vis[r][c-1] = d;
            }
            if(c<n-1 && grid[r][c+1]==INT_MAX && vis[r][c+1]==-1){
                q.push({r,c+1,d+1});
                vis[r][c+1] = d;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==INT_MAX){
                    grid[i][j] = vis[i][j];
                }
            }
        }
        return;
        
    }
};
