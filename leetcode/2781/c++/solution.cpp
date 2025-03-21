/*
    2781. Length of the Longest Valid Substring
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   private:
    std::vector<std::pair<std::vector<size_t>, bool>> m_forbidden_trees;
    size_t max_length = 0;

    void _add_forbidden_word(const std::string &forbidden) {
        size_t id_tree = 0;

        for (size_t i = 0, j = 0; i < forbidden.size(); ++i) {
            j = forbidden[i] - 'a';
            if (m_forbidden_trees[id_tree].first[j] > 0) {  // zero is null
                id_tree = m_forbidden_trees[id_tree].first[j] - 1;
            } else {
                m_forbidden_trees.push_back(
                    std::make_pair(std::vector<size_t>(26, 0), false));
                m_forbidden_trees[id_tree].first[j] = m_forbidden_trees.size();
                id_tree = m_forbidden_trees.size() - 1;
            }
        }
        m_forbidden_trees[id_tree].second = true;
    }

    bool _is_valid_substring(const std::string &word, size_t left, size_t right,
                             size_t &new_right) {
        for (size_t j = left, id_tree = 0, c = 0; j <= right; ++j) {
            c = word[j] - 'a';
            if (m_forbidden_trees[id_tree].first[c] > 0) {
                id_tree = m_forbidden_trees[id_tree].first[c] - 1;
                if (m_forbidden_trees[id_tree].second) {
                    new_right = j;
                    return false;
                }
            } else {
                break;
            }
        }
        return true;
    }

   public:
    int longestValidSubstring(string word, vector<string> &forbidden) {
        // Initialize the forbidden trees
        m_forbidden_trees = std::vector<std::pair<std::vector<size_t>, bool>>(
            1, std::make_pair(std::vector<size_t>(26, 0), false));
        size_t max_length = 0;
        for (const std::string &forbidden_word_i : forbidden) {
            this->_add_forbidden_word(forbidden_word_i);
            max_length = std::max(max_length, forbidden_word_i.size());
        }

        size_t output = 0;
        size_t left = word.size();
        size_t right = word.size(), new_right = 0;
        while (left > 0) {
            if (!_is_valid_substring(word, left - 1,
                                     std::min(right, left + max_length - 1) - 1,
                                     new_right)) {
                right = new_right;
            }
            output = std::max(output, right - left + 1);
            --left;
        }

        return static_cast<int>(output);
    }
};
