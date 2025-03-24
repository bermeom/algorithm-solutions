/*
    2685. Count the Number of Complete Components
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<size_t>> graph(n, std::vector<size_t>());
        std::vector<std::bitset<50>> matrix_graph(n, std::bitset<50>());
        for (const std::vector<int>& edge_i : edges) {
            graph[edge_i[0]].push_back(edge_i[1]);
            graph[edge_i[1]].push_back(edge_i[0]);
            matrix_graph[edge_i[0]][edge_i[1]] = true;
            matrix_graph[edge_i[1]][edge_i[0]] = true;
        }
        std::bitset<50> marks, temp;
        int output = 0, is_ccc = 0;
        for (size_t i = 0; i < n; ++i) {
            if (!marks[i]) {
                temp = matrix_graph[i];
                temp[i] = true;
                is_ccc = 1;
                for (const size_t& node_i : graph[i]) {
                    matrix_graph[node_i][node_i] = true;
                    if (temp != matrix_graph[node_i]) {
                        is_ccc = 0;
                    }
                    temp |= matrix_graph[node_i];
                }
                matrix_graph[i][i] = true;
                output += is_ccc;
                marks |= temp;
            }
        }
        return output;
    }
};