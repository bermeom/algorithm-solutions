/*
    10. Regular Expression Matching
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    bool getBit(std::vector<uint> &dp, size_t i, size_t j) {
        return dp[i] >> j & 1;
    }

    void setBit(std::vector<uint> &dp, size_t i, size_t j, bool value) {
        dp[i] = ((dp[i] >> (j + 1)) << (j + 1)) | (((1 << j) - 1) & dp[i]) |
                ((1 & value) << j);
    }

    bool isMatch(string s, string p) {
        std::vector<uint> dp(s.size() + 1, 0);
        setBit(dp, 0, 0, true);  // Empty string matches empty pattern
        bool state_i = false;
        for (size_t i = 1; i <= s.size(); ++i) {
            for (size_t j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '*' && j >= 2) {
                    if (i == 1) {
                        // Initialize the first row (s is empty, only '*' can
                        // match zero occurrences)
                        setBit(dp, 0, j, getBit(dp, 0, j - 2));
                    }
                    state_i =
                        getBit(dp, i, j - 2)  // Zero occurrences of the
                                              // preceding character
                                              //  One or more occurrences if the
                                              //  preceding character matches
                        || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') &&
                            getBit(dp, i - 1, j));
                } else {
                    // Direct match or '.' which matches any character
                    state_i = getBit(dp, i - 1, j - 1) &&
                              (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                setBit(dp, i, j, state_i);
            }
        }
        return getBit(dp, s.size(), p.size());
    }
};