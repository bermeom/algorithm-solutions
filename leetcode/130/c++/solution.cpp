/*
    130. Surrounded Regions
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    bool is_valid_pos(int i, int lb, int ub) { return lb <= i && i < ub; }

    void mark_islan_from_border(vector<vector<char>>& board, int i, int j) {
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};
        int n = board.size(), m = board[0].size();
        std::queue<std::pair<int, int>> q;
        q.push(make_pair(i, j));
        board[i][j] = '1';
        std::pair<int, int> p;
        while (!q.empty()) {
            p = q.front();
            q.pop();
            for (size_t k = 0; k < 4; ++k) {
                i = p.first + x[k];
                j = p.second + y[k];
                if (is_valid_pos(i, 0, n) && is_valid_pos(j, 0, m) &&
                    board[i][j] == 'O') {
                    board[i][j] = '1';
                    q.push(make_pair(i, j));
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int increment = 1;
        for (size_t i = 0; i < board.size(); ++i) {
            if (i == 0 || i + 1 == board.size()) {
                increment = 1;
            } else {
                increment = board[i].size() - 1;
            }
            for (size_t j = 0; j < board[i].size(); j += increment) {
                if (board[i][j] == 'O') {
                    mark_islan_from_border(board, i, j);
                }
            }
        }

        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};