/*
    17. Letter Combinations of a Phone Number
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::vector<std::string>> solutions(2);
        int digit_i = 0;
        size_t i = 1, i_1 = 0;
        char length = 3;
        for (const char digit_i_c : digits) {
            length = 3;
            switch (digit_i_c) {
                case ('7'):
                    digit_i = 'p' - 'a';
                    length = 4;
                    break;
                case ('8'):
                    digit_i = 't' - 'a';
                    break;
                case ('9'):
                    digit_i = 'w' - 'a';
                    length = 4;
                    break;
                default:
                    digit_i = (digit_i_c - '2') * 3;
            };

            solutions[i].clear();
            for (char c_i = digit_i + 'a'; c_i < digit_i + 'a' + length;
                 ++c_i) {
                if (solutions[i_1].empty()) {
                    solutions[i].push_back(std::string(1, c_i));
                } else {
                    for (const std::string& s_i : solutions[i_1]) {
                        solutions[i].push_back(s_i + std::string(1, c_i));
                    }
                }
            }
            i_1 = i;
            i = (i + 1) % 2;
        }
        return solutions[i_1];
    }
};