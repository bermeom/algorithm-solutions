/*
    221. Maximal Square
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maximal_square = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int prev_dp;
        bool sw = true;
        int x[3] = {0, -1, -1};
        int y[3] = {-1, 0, -1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    prev_dp = -1;
                    for (int k = 0; k < 3; ++k) {
                        if ((i + x[k]) >= 0 && (j + y[k]) >= 0) {
                            if (prev_dp == -1 ||
                                prev_dp > dp[i + x[k]][j + y[k]]) {
                                prev_dp = dp[i + x[k]][j + y[k]];
                            }
                        } else {
                            prev_dp = 0;
                        }
                    }
                    if (prev_dp > 0 || (prev_dp != -1 && maximal_square == 0)) {
                        dp[i][j] += prev_dp;
                        maximal_square = std::max(maximal_square, dp[i][j]);
                    }
                }
            }
        }
        return maximal_square * maximal_square;
    }
};