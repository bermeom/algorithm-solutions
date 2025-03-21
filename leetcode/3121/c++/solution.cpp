/*
    3121. Count the Number of Special Characters II
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int numberOfSpecialChars(string word) {
        std::vector<uint8_t> letter_map(26, 0);
        for (size_t i = 0, j; i < word.size(); ++i) {
            if ('a' <= word[i] && word[i] <= 'z') {
                j = word[i] - 'a';
                if (letter_map[j] == 0) {
                    letter_map[j] = 1;
                } else if (letter_map[j] == 2) {
                    letter_map[j] = 3;
                }

            } else {
                j = word[i] - 'A';
                if (letter_map[j] == 1) {
                    letter_map[j] = 2;
                } else if (letter_map[j] != 2) {
                    letter_map[j] = 3;
                }
            }
        }
        int count = 0;
        for (const uint8_t value : letter_map) {
            count += (value == 2) ? 1 : 0;
        }
        return count;
    }
};