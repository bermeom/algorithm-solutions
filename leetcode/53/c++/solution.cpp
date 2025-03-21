/*
    53. Maximum Subarray
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], sum = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (max_sum < sum) {
                max_sum = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return max_sum;
    }
};