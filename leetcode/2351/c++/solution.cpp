/*
    2351. First Letter to Appear Twice
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    char repeatedCharacter(string s) {
        std::vector<bool> alphabet(30, false);
        for (char s_i : s) {
            if (!alphabet[s_i - 'a']) {
                alphabet[s_i - 'a'] = true;
            } else {
                return s_i;
            }
        }
        return s.back();
    }
};