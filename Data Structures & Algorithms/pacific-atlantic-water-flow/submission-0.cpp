class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // unordered_set<pair<int,int>> a;
        // unordered_set<pair<int,int>> p;

        int m = heights.size();
        int n = heights[0].size();
        // for(int i=0;i<m;i++){
        //     a.insert({heights[i][n-1]});
        // }
        // for(int j=0;j<n;j++){
        //     p.insert({heights[m-1][j]});
        // }

        vector<vector<int>> visa(m,vector<int>(n,0));
        vector<vector<int>> visp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            cout<<heights[i][n-1];
            dfs(heights,i,n-1,m,n,visa);
        }
        for(int j=0;j<n;j++){
            dfs(heights,m-1,j,m,n,visa);
        }

        for(int i=0;i<m;i++){
            cout<<heights[i][n-1];
            dfs(heights,i,0,m,n,visp);
        }
        for(int j=0;j<n;j++){
            dfs(heights,0,j,m,n,visp);
        }

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visa[i][j]==1 && visa[i][j]==visp[i][j]) ans.emplace_back(vector<int>{i,j});
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& adj,int i,int j,int m,int n,vector<vector<int>>& vis){
        if(vis[i][j]) return;
        
        vis[i][j] = 1;

        if(i>0 && adj[i-1][j] >= adj[i][j])
        dfs(adj,i-1,j,m,n,vis);
        if(i<m-1 && adj[i+1][j] >= adj[i][j])
        dfs(adj,i+1,j,m,n,vis);
        if(j>0 && adj[i][j-1] >= adj[i][j])
        dfs(adj,i,j-1,m,n,vis);
        if(j<n-1 && adj[i][j+1] >= adj[i][j])
        dfs(adj,i,j+1,m,n,vis);
    }
};
