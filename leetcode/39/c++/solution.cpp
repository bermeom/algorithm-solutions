/*
    39. Combination Sum
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::set<int> candidates_set;
        for (const int& candidate_i : candidates) {
            candidates_set.insert(candidate_i);
        }

        return _combination_sum(candidates_set, candidates_set.begin(), target,
                                0);
    }

    vector<vector<int>> _combination_sum(std::set<int>& candidates_set,
                                         std::set<int>::iterator it_candidates,
                                         int target, int min_val) {
        std::set<std::vector<int>> output_set;
        std::vector<std::vector<int>> output;

        for (; it_candidates != candidates_set.end(); ++it_candidates) {
            if (*it_candidates >= min_val) {
                if (*it_candidates < target) {
                    std::vector<std::vector<int>> comb_sum_i = _combination_sum(
                        candidates_set, it_candidates, target - *it_candidates,
                        *it_candidates);
                    for (auto& comb_sum_j : comb_sum_i) {
                        comb_sum_j.insert(comb_sum_j.begin(), *it_candidates);
                        output.push_back(comb_sum_j);
                    }

                } else if (*it_candidates == target) {
                    output.push_back(std::vector<int>(1, target));
                } else {
                    break;
                }
            }
        }

        return output;
    }
};