/*
    1358. Number of Substrings Containing All Three Characters
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    bool get_bit(uint8_t bitset, size_t position) {
        return (bitset >> position) & 1;
    }

    void set_bit(uint8_t &bitset, size_t position, bool value) {
        bitset = value ? bitset | (1 << position) : bitset & (~(1 << position));
    }

    int number_of_abc_substrings(
        string s, std::unordered_map<std::string, size_t> &abc_sub_str_map) {
        uint8_t marks_abc = 0;
        size_t count = 0;
        for (size_t i = 0; i < s.size() - 2; ++i) {
            for (size_t j = i, k = 1; j < s.size(); ++j) {
                set_bit(marks_abc, static_cast<size_t>(s[j] - 'a'), true);
                if (marks_abc == 7) {
                    count += s.size() - j;
                    break;
                }
            }
            marks_abc = 0;
        }
        return count;
    }

    int numberOfSubstrings(string s) {
        std::unordered_map<std::string, size_t> abc_sub_str_map;
        return number_of_abc_substrings(s, abc_sub_str_map);
    }
};