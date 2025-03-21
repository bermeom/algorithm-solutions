/*
    22. Generate Parentheses
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::unordered_set<std::string>> result(n);
        for (size_t j = 0; j < n; ++j) {
            if (j == 0) {
                result[j].insert("()");
            } else {
                for (const std::string& s_i : result[j - 1]) {
                    result[j].insert("(" + s_i + ")");
                    result[j].insert(s_i + "()");
                    result[j].insert("()" + s_i);
                }
                if (j + 1 > 2) {
                    for (size_t k = j / 2; k < j - 1; ++k) {
                        for (const std::string& s_i_1 : result[k]) {
                            for (const std::string& s_i_2 : result[j - k - 1]) {
                                result[j].insert(s_i_1 + s_i_2);
                                result[j].insert(s_i_2 + s_i_1);
                            }
                        }
                    }
                }
            }
        }
        std::vector<std::string> output(result[n - 1].size());
        std::copy(result[n - 1].begin(), result[n - 1].end(), output.begin());
        return output;
    }
};
