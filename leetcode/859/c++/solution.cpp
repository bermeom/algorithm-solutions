/*
    859. Buddy Strings
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        size_t num_mismatch = 0, j;
        std::vector<size_t> abc(26, 0);
        size_t max_rep = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                if (num_mismatch == 0) {
                    j = i;
                } else if (num_mismatch > 2 ||
                           (goal[j] != s[i] || goal[i] != s[j])) {
                    return false;
                }
                ++num_mismatch;
            }
            ++abc[s[i] - 'a'];
            max_rep = max(max_rep, abc[s[i] - 'a']);
        }
        return (num_mismatch == 0 && max_rep >= 2) || num_mismatch == 2;
    }
};