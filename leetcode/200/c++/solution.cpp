/*
    200. Number of Islands
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    bool is_valid_pos(int i, int lb, int ub) { return (lb <= i && i < ub); }

    void mark_island(vector<vector<char>>& marks, int i, int j) {
        int n = marks.size(), m = marks[0].size();
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};
        std::queue<std::pair<int, int>> q;
        std::pair<int, int> current_p;
        q.push(make_pair(i, j));
        marks[i][j] = '0';
        while (!q.empty()) {
            current_p = q.front();
            q.pop();
            for (size_t k = 0; k < 4; ++k) {
                i = current_p.first + x[k];
                j = current_p.second + y[k];
                if (is_valid_pos(i, 0, n) && is_valid_pos(j, 0, m) &&
                    marks[i][j] == '1') {
                    marks[i][j] = '0';
                    q.push(make_pair(i, j));
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n_islands = 0;
        vector<vector<char>> marks(grid);
        for (size_t i = 0; i < marks.size(); ++i) {
            for (size_t j = 0; j < marks[i].size(); ++j) {
                if (marks[i][j] == '1') {
                    ++n_islands;
                    mark_island(marks, i, j);
                }
            }
        }
        return n_islands;
    }
};