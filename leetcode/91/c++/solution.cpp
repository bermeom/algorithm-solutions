/*
    91. Decode Ways
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int get_num_decodings(std::vector<std::vector<int>> &nums, int i, int opt) {
        if (i >= nums.size()) {
            return 0;
        }

        if (nums[i][opt] == -1) {
            nums[i][opt] = get_num_decodings(nums, i + 1, 1) +
                           get_num_decodings(nums, i + 2, 2);

            if (nums[i][opt] == 0) {
                nums[i][opt] = 1;
            }
        }
        return nums[i][opt];
    }

    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0;
        }

        std::vector<std::vector<int>> nums;
        std::vector<int> states(4, -1);
        nums.reserve(s.size());
        int n = 1, d_i;
        for (size_t i = 0; i < s.size(); ++i) {
            states[1] = -1;
            states[2] = -1;
            states[3] = 2;
            states[0] = (s[i] - '0');
            if (i + 1 < s.size() && '0' < s[i] && s[i] <= '2' &&
                s[i + 1] == '0') {
                states[0] *= 10;
                states[3] = 1;
                ++i;
            } else if (s[i] == '0') {
                return 0;
            } else if ((i > 0 && s[i - 1] >= '2' && s[i] > '6') ||
                       (i > 0 && nums.back()[0] > 2)) {
                states[3] = 1;
            }
            if (states[3] == 1) {
                states[2] = 0;
            }
            nums.push_back(states);
        }

        nums[0][3] = 1;

        if (nums.size() == 1) {
            return 1;
        }
        n = get_num_decodings(nums, 0, 1) + get_num_decodings(nums, 1, 2);

        return n;
    }
};