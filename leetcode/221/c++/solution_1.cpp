/*
    221. Maximal Square
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> num_matrix(matrix.size(),
                                       vector<int>(matrix[0].size(), 0));
        int solution = 0, min_local_val = 0;
        int x[4] = {-1, 0, -1};
        int y[4] = {-1, -1, 0};
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                num_matrix[i][j] = matrix[i][j] - '0';
                if (num_matrix[i][j] != 0) {
                    min_local_val = -1;
                    for (size_t k = 0; k < 3; ++k) {
                        if (i + x[k] >= 0 && j + y[k] >= 0 &&
                            num_matrix[i + x[k]][j + y[k]] != 0) {
                            min_local_val =
                                min_local_val == -1
                                    ? num_matrix[i + x[k]][j + y[k]]
                                    : (num_matrix[i + x[k]][j + y[k]] <
                                               min_local_val
                                           ? num_matrix[i + x[k]][j + y[k]]
                                           : min_local_val);
                        } else {
                            min_local_val = 0;
                            break;
                        }
                    }
                    num_matrix[i][j] = min_local_val + 1;
                    if (solution < num_matrix[i][j]) {
                        solution = num_matrix[i][j];
                    }
                }
            }
        }

        return solution * solution;
    }
};