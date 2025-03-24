/*
    1329. Sort the Matrix Diagonally
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        size_t n = mat.size();
        size_t m = mat[0].size();
        std::vector<vector<int>> output(n, std::vector<int>(m, 0));
        std::vector<int> diagonal;

        for (size_t i = 0; i < n; ++i) {
            diagonal.clear();
            for (size_t x = i, y = 0; x < n && y < m; ++x, ++y) {
                diagonal.push_back(mat[x][y]);
            }

            std::sort(diagonal.begin(), diagonal.end());
            for (size_t x = i, y = 0, k = 0; x < n && y < m; ++x, ++y, ++k) {
                output[x][y] = diagonal[k];
            }
        }

        for (size_t i = 1; i < m; ++i) {
            diagonal.clear();
            for (size_t x = 0, y = i; x < n && y < m; ++x, ++y) {
                diagonal.push_back(mat[x][y]);
            }

            std::sort(diagonal.begin(), diagonal.end());
            for (size_t x = 0, y = i, k = 0; x < n && y < m; ++x, ++y, ++k) {
                output[x][y] = diagonal[k];
            }
        }
        return output;
    }
};