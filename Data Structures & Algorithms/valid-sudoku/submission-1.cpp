class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> m, n;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] != '.') {
                if (m.count(board[i][j])) return false;
                m.insert(board[i][j]);
            }

            if (board[j][i] != '.') {
                if (n.count(board[j][i])) return false;
                n.insert(board[j][i]);
            }
        }
        m.clear();
        n.clear();
    }

    unordered_set<char> p;

    for (int si = 0; si < 9; si += 3) {
        for (int sj = 0; sj < 9; sj += 3) {

            for (int i = si; i < si + 3; i++) {
                for (int j = sj; j < sj + 3; j++) {

                    if (board[i][j] != '.') {
                        if (p.count(board[i][j])) return false;
                        p.insert(board[i][j]);
                    }
                }
            }
            p.clear();
        }
    }

    return true;
}
};
