/*
    1366. Rank Teams by Votes
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    string rankTeams(vector<string>& votes) {
        std::vector<std::vector<int16_t>> score(27,
                                                std::vector<int16_t>(27, 0));
        for (size_t i = 0; i < votes.size(); ++i) {
            for (size_t j = 0, k = 0; j < votes[i].size(); ++j) {
                k = votes[i][j] - 'A';
                --score[k][j];
                score[k][26] = k;
            }
        }
        std::string output;
        std::sort(score.begin(), score.end());
        size_t len = votes[0].size();
        output.reserve(len);
        for (size_t i = 0; i < len; ++i) {
            output.push_back(score[i][26] + 'A');
        }
        return output;
    }
};