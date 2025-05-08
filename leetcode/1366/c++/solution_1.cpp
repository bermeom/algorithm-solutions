/*
    1366. Rank Teams by Votes
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    string rankTeams(vector<string>& votes) {
        std::unordered_map<uint8_t, std::vector<int16_t>> score;
        for (size_t i = 0; i < votes.size(); ++i) {
            for (size_t j = votes[i].size(), k = 1; j > 0; --j, k *= 10) {
                auto it = score.find(votes[i][j - 1] - 'A');
                if (it == score.end()) {
                    it = score
                             .emplace(votes[i][j - 1] - 'A',
                                      std::vector<int16_t>(27, 0))
                             .first;
                    it->second[26] = 26 - (votes[i][j - 1] - 'A');
                }
                it->second[j - 1] += 1;
            }
        }
        std::string output;
        output.reserve(votes[0].size());
        std::priority_queue<std::vector<int16_t>> q;
        for (const auto& it : score) {
            q.push(it.second);
        }

        while (!q.empty()) {
            const auto candidate = q.top();
            q.pop();
            output.push_back((26 - candidate[26]) + 'A');
        }  //*/
        return output;
    }
};