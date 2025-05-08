/*
    354. Russian Doll Envelopes
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::vector<std::pair<uint64_t, int>> distances;
        distances.reserve(envelopes.size());
        uint64_t x, y;
        for (size_t i = 0; i < envelopes.size(); ++i) {
            x = envelopes[i][0];
            y = envelopes[i][1];
            distances.push_back(std::make_pair(x * x + y * y, i));
        }

        std::vector<int> tree(envelopes.size(), 1);
        // tree.reserve(envelopes.size());
        std::sort(distances.begin(), distances.end());
        int max_env = 1;
        for (size_t i = 0, k = 0, k1 = 0, k2 = 0, k3 = 0; i < distances.size();
             ++i) {
            for (size_t j = i; j > k3; --j) {
                if (envelopes[distances[j - 1].second][0] <
                        envelopes[distances[i].second][0] &&
                    envelopes[distances[j - 1].second][1] <
                        envelopes[distances[i].second][1]) {
                    if (tree[i] < tree[j - 1] + 1) {
                        tree[i] = tree[j - 1] + 1;
                    } else if (tree[i] > tree[j - 1] + 1) {
                        // break;
                    }
                }
            }
            if (tree[i] > max_env) {
                max_env = tree[i];
                k3 = k2;
                k2 = k1;
                k1 = k;
                k = i;
            }
        }

        return max_env;
    }
};