/*
    2551. Put Marbles in Bags
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    long long putMarbles(vector<int>& weights, int k) {
        long long output = 0;
        if (k > 1) {
            std::priority_queue<int> max_w, min_w;
            for (size_t i = 1; i < weights.size(); ++i) {
                min_w.push(weights[i - 1] + weights[i]);
                max_w.push(-(weights[i - 1] + weights[i]));
                if (min_w.size() > k - 1) {
                    min_w.pop();
                    max_w.pop();
                }
            }
            long long min_score = weights[0] + weights[weights.size() - 1];
            long long max_score = weights[0] + weights[weights.size() - 1];
            while (!min_w.empty()) {
                min_score += min_w.top();
                min_w.pop();
                max_score += -max_w.top();
                max_w.pop();
            }
            output = max_score - min_score;
        }
        return output;
    }
};