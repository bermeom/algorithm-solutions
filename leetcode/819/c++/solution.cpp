/*
    819. Most Common Word
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    bool is_banned(std::string word, std::vector<std::string> &banned) {
        for (std::string s_i : banned) {
            if (word.compare(s_i) == 0) {
                return true;
            }
        }
        return false;
    }

    void to_lowercase(std::string &s) {
        for (size_t i = 0; i < s.size(); ++i) {
            s[i] = std::tolower(s[i]);
        }
    }

    std::string mostCommonWord(std::string paragraph,
                               std::vector<std::string> &banned) {
        std::unordered_map<std::string, int> map_words;
        std::unordered_map<std::string, int>::iterator it;
        std::stringstream ss(paragraph);
        std::string s_i;
        size_t i_0, i;
        for (i = 0, i_0 = 0; i < paragraph.size(); ++i) {
            paragraph[i] = std::tolower(paragraph[i]);
            if (!('a' <= paragraph[i] && paragraph[i] <= 'z') &&
                !('A' <= paragraph[i] && paragraph[i] <= 'Z')) {
                if (i_0 != i) {
                    s_i = paragraph.substr(i_0, i - i_0);
                    it = map_words.find(s_i);
                    if (it == map_words.end()) {
                        map_words[s_i] = 1;
                    } else {
                        it->second += 1;
                    }
                }
                i_0 = i + 1;
            }
        }
        if (i_0 != i) {
            s_i = paragraph.substr(i_0, i - i_0);
            it = map_words.find(s_i);
            if (it == map_words.end()) {
                map_words[s_i] = 1;
            } else {
                it->second += 1;
            }
        }

        std::unordered_map<std::string, int>::iterator it_max = map_words.end();
        for (it = map_words.begin(); it != map_words.end(); ++it) {
            if (!is_banned(it->first, banned) &&
                (it_max == map_words.end() || it->second > it_max->second)) {
                it_max = it;
            }
        }
        return it_max->first;
    }
};