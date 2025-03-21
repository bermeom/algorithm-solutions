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
        std::deque<size_t> dq;
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k - 1) {
                if (dq.front() < (i + 1) - k) {
                    dq.pop_front();
                }
                output[((i + 1) - k)] = nums[dq.front()];
            }
        }
        return output;
    }
};