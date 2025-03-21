/*
    1. Two Sum
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> output(2, 0);
        int i_0 = 0, i_n = nums.size() - 1;
        while (i_0 < i_n) {
            if (nums[i_0] + nums[i_n] == target) {
                output[0] = i_0;
                output[1] = i_n;
                break;
            } else if (nums[i_0] + nums[i_n] < target) {
                ++i_0;
            } else if (nums[i_0] + nums[i_n] > target) {
                --i_n;
            }
        }
        return output;
    }
};