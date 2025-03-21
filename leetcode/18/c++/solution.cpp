/*
    18. 4Sum
    Author: Miguel Angel Bermeo Ayerbe
*/
#include <bits/stdc++.h>

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        vector<int> temp(4, 0);
        int64_t sum = 0;
        std::sort(nums.begin(), nums.end());

        if (nums.size() >= 4) {
            for (size_t i = 0; i < (nums.size() - 3); ++i) {
                if (i > 0 && nums[i - 1] == nums[i]) {
                    continue;
                }
                temp[0] = nums[i];
                for (size_t j = i + 1, l, r; j < nums.size() - 2; ++j) {
                    if (j > (i + 1) && nums[j - 1] == nums[j]) {
                        continue;
                    }
                    temp[1] = nums[j];
                    l = j + 1;
                    r = nums.size() - 1;
                    while (l < r && l < nums.size() - 1 && r < nums.size()) {
                        sum = static_cast<int64_t>(temp[0]) +
                              static_cast<int64_t>(temp[1]) +
                              static_cast<int64_t>(nums[l]) +
                              static_cast<int64_t>(nums[r]);
                        if (sum == target) {
                            temp[2] = nums[l];
                            temp[3] = nums[r];
                            output.push_back(temp);
                            do {
                                ++l;
                            } while (temp[2] == nums[l] && l < r);

                            do {
                                --r;
                            } while (temp[3] == nums[r] && l < r);
                        } else if (sum > target) {
                            --r;
                        } else if (sum < target) {
                            ++l;
                        }
                    }
                }
            }
        }
        //*/
        return output;
    }
};