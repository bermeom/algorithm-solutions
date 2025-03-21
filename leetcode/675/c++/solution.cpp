/*
    675. Cut Off Trees for Golf Event
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};

    bool is_valid_pos(int i, int lb, int ub) { return (lb <= i && i < ub); }

    int bsf(vector<vector<int>>& forest, int sx, int sy, int tx, int ty,
            std::vector<std::vector<int>>& marks) {
        int x_i, x_i_1, y_i, y_i_1;
        int n = forest.size();
        int m = forest[0].size();

        std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> q;
        std::pair<std::pair<int, int>, std::pair<int, int>> current_pos =
            make_pair(make_pair(0, 0), make_pair(sx, sy));
        q.push(current_pos);
        marks[sx][sy] = forest[tx][ty];
        int dist2trg;
        while (!q.empty()) {
            current_pos = q.front();
            q.pop();
            x_i_1 = current_pos.second.first;
            y_i_1 = current_pos.second.second;

            if (x_i_1 == tx && y_i_1 == ty) {
                return -current_pos.first.second;
            }

            for (size_t i = 0; i < 4; ++i) {
                x_i = x_i_1 + x[i];
                y_i = y_i_1 + y[i];
                if (is_valid_pos(x_i, 0, n) && is_valid_pos(y_i, 0, m) &&
                    marks[x_i][y_i] != forest[tx][ty] && forest[x_i][y_i] > 0) {
                    dist2trg = std::abs(tx - x_i) + std::abs(ty - y_i) +
                               -(-current_pos.first.second + 1);
                    q.push(make_pair(
                        make_pair(-dist2trg, -(-current_pos.first.second + 1)),
                        make_pair(x_i, y_i)));
                    // marks[x_i][y_i]=marks[x_i_1][y_i_1]+1;
                    marks[x_i][y_i] = forest[tx][ty];
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        if (forest[0][0] == 0) {
            return -1;
        }
        int n = forest.size();
        int m = forest[0].size();
        std::vector<std::vector<int>> marks(n, std::vector<int>(m, -1));
        std::priority_queue<std::pair<int, std::pair<int, int>>> trees;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (forest[i][j] > 1) {
                    trees.push(make_pair(-forest[i][j], make_pair(i, j)));
                }
            }
        }

        int dist = 0, dist_t;
        int sx = 0, sy = 0;
        std::pair<int, std::pair<int, int>> current_tree;
        while (!trees.empty()) {
            current_tree = trees.top();
            trees.pop();
            dist_t = bsf(forest, sx, sy, current_tree.second.first,
                         current_tree.second.second, marks);
            if (dist_t == -1) {
                return -1;
            }
            dist += dist_t;
            sx = current_tree.second.first;
            sy = current_tree.second.second;
        }

        return dist;
    }
};