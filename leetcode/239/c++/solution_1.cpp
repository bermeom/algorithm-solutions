/*
    239. Sliding Window Maximum
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        std::vector<int> output(nums.size() - k + 1, 0);

        for (size_t i = 0, i_max = 0; i < nums.size(); ++i) {
            if (nums[i] >= nums[i_max]) {
                i_max = i;
            }
            if (i >= k - 1) {
                if (i_max < (i + 1) - k) {
                    i_max = (i + 1) - k;
                    for (size_t j = (i + 1) - k + 1; j <= i; ++j) {
                        if (nums[j] >= nums[i_max]) {
                            i_max = j;
                        }
                    }
                }

                output[((i + 1) - k)] = nums[i_max];
            }
        }
        return output;
    }
};