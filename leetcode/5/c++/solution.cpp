/*
    5. Longest Palindromic Substring
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    string longestPalindrome(string s) {
        size_t max_palindrome_size = 1, max_i = 1;
        size_t first_position = 0;
        for (size_t i = 0; i < s.size() - 1; ++i) {
            for (size_t j = 0; j < 2 && i + j < s.size(); ++j) {
                max_i = isPalindrome(s, i, i + j);
                if (max_i > max_palindrome_size) {
                    max_palindrome_size = max_i;
                    first_position = max(i - max_i / 2 + j, 0UL);
                }
            }
        }
        return s.substr(first_position, max_palindrome_size);
    }

    int isPalindrome(string &s, int i, int j) {
        for (; 0 <= i && j < s.size() && s[i] == s[j]; --i, ++j) {
        }
        if (j < i) return 0;
        return (j - 1) - (i + 1) + 1;
    }
};