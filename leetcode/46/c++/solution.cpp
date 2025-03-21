/*
    46. Permutations
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> permutations;
        if (nums.size() == 1) {
            permutations.push_back(nums);
        } else {
            std::queue<std::pair<vector<int>, int>> q;
            int mark = 0, full = (1 << (nums.size())) - 1;
            std::vector<int> permutation(1);
            permutation.reserve(nums.size());
            for (size_t i = 0; i < nums.size(); ++i) {
                permutation[0] = nums[i];
                q.push(std::make_pair(permutation, 1 << i));
            }
            std::pair<vector<int>, int> curr;
            while (!q.empty()) {
                curr = q.front();
                q.pop();
                for (size_t i = 0; i < nums.size(); ++i) {
                    if (((curr.second >> i) & 1) == 0) {
                        curr.first.push_back(nums[i]);
                        if ((curr.second | 1 << i) == full) {
                            permutations.push_back(curr.first);
                        } else {
                            q.push(std::make_pair(curr.first,
                                                  (curr.second | 1 << i)));
                        }
                        curr.first.pop_back();
                    }
                }
            }
        }
        return permutations;
    }
};