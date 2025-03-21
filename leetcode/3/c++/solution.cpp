/*
    3. Longest Substring Without Repeating Characters
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int solution = 0;
        std::vector<int> ch(256, -1);
        int i_start = 0;

        for (int i = 0, c_i; i < s.size(); ++i) {
            c_i = static_cast<int>(s[i]);
            if (ch[c_i] != -1 && ch[c_i] >= i_start) {
                if (i - i_start > solution) {
                    solution = i - i_start;
                }
                i_start = ch[c_i] + 1;
            }
            ch[c_i] = i;
        }
        if (s.size() - i_start > solution) {
            solution = s.size() - i_start;
        }
        return solution;
    }
};