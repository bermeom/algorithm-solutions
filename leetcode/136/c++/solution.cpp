/*
    136. Single Number
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (const int& num_i : nums) {
            result = result ^ num_i;
        }
        return result;
    }
};