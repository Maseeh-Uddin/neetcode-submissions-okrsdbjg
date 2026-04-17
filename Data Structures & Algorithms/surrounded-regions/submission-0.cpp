class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
            }
            if(board[m-1][i]=='O'){
            cout<<"A";
                q.push({m-1,i});
            }
        }
        vector<vector<int>> vis(m,vector<int>(n,0));
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            int i = node.first;
            int j = node.second;

            vis[i][j] = 1;
            
            if(i>0 && board[i-1][j]=='O' && !vis[i-1][j]) q.push({i-1,j});
            if(i<m-1 && board[i+1][j]=='O' && !vis[i+1][j]) q.push({i+1,j});
            if(j>0 && board[i][j-1]=='O' && !vis[i][j-1]) q.push({i,j-1});
            if(j<n-1 && board[i][j+1]=='O' && !vis[i][j+1]) q.push({i,j+1});
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
        
    }
};
