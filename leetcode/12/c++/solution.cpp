/*
    12. Integer to Roman
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    std::string intToRoman(int num) {
        uint num_i = 0;
        std::string roman_num = "";
        std::unordered_map<uint, std::string> roman_map = {
            {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
            {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
            {500, "D"}, {900, "CM"}, {1000, "M"}};
        roman_num.reserve(10);
        for (uint i = 1; num > 0; i *= 10) {
            num_i = (num % 10);
            num /= 10;
            if (num_i == 1 || num_i == 4 || num_i == 5 || num_i == 9) {
                roman_num.insert(0, roman_map[num_i * i]);
            } else if (num_i > 0) {
                std::string temp_1 = roman_map[1 * i];
                for (size_t k = 0; k < num_i % 5; ++k) {
                    roman_num.insert(0, temp_1);
                }
                if (num_i > 5) {
                    roman_num.insert(0, roman_map[5 * i]);
                }
            }
        }
        return roman_num;
    }
};