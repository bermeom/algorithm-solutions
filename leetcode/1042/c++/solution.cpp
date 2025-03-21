/*
    1042. Flower Planting With No Adjacent
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int getEnableFlowers2Gardens(int mask_1, int mask_2) {
        for (size_t i = 0; i < 4; ++i) {
            // std::cout<<((mask>>i)&1);
            if (((mask_1 >> i) & 1) == 0 && ((mask_2 >> i) & 1) == 0) {
                return i + 1;
            }
        }
        return 0;
    }

    int getEnableFlowers(int mask) {
        for (size_t i = 0; i < 4; ++i) {
            // std::cout<<((mask>>i)&1);
            if (((mask >> i) & 1) == 0) {
                return i + 1;
            }
        }
        return 0;
    }

    void plant_flowers(std::vector<std::vector<int>> &graph, int i_node,
                       std::vector<int> &output,
                       std::vector<int> &flowers_neighborhoods) {
        //  BSF
        int flower = 1, flower_1;
        output[i_node] = flower;
        flowers_neighborhoods[i_node] |= 1 << (flower - 1);
        std::queue<int> q;
        q.push(i_node);
        while (!q.empty()) {
            i_node = q.front();
            q.pop();
            flower = output[i_node] % 4 + 1;
            for (int j_node : graph[i_node]) {
                if (output[j_node] == -1 || output[j_node] == output[i_node]) {
                    q.push(j_node);
                    output[j_node] = flower;
                }
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        std::vector<int> output(n, -1);
        std::vector<int> flowers_neighborhoods(n, 0);
        std::vector<std::vector<int>> graph(n, std::vector<int>());
        for (size_t i = 0; i < paths.size(); ++i) {
            graph[paths[i][0] - 1].push_back(paths[i][1] - 1);
            graph[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }

        for (size_t i_g = 0; i_g < n; ++i_g) {
            if (output[i_g] == -1) {
                plant_flowers(graph, i_g, output, flowers_neighborhoods);
            }
        }
        return output;
    }
};