/*
    6. Zigzag Conversion
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) {
            return s;
        }
        std::string output(s.size(), ' ');
        size_t jumps = 2 * numRows - 2;
        for (size_t i = 0, k = 0; i < numRows; ++i) {
            for (size_t j = i; j < s.size() || j - 2 * i < s.size();
                 j += jumps) {
                if (j - 2 * i < s.size() && j - 2 * i > 0 && j >= numRows &&
                    i > 0 && i < numRows - 1) {
                    output[k] = s[j - 2 * i];
                    ++k;
                }
                if (j < s.size()) {
                    output[k] = s[j];
                    ++k;
                }
            }
        }
        return output;
    }
};