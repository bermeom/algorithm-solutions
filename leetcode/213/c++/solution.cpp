/*
    213. House Robber II
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        return max(house_robber(nums, 0, nums.size() - 1),
                   house_robber(nums, 1, nums.size()));
    }

    int house_robber(vector<int>& nums, size_t i_0, int i_n) {
        int rob1 = 0, rob2 = 0, new_rob;
        for (size_t i = i_0; i < i_n; ++i) {
            new_rob = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = new_rob;
        }
        return rob2;
    }
};