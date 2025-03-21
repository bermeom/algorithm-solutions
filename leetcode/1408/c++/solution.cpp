/*
    1408. String Matching in an Array
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int set_bit(int bits, int i, int val) {
        return (bits & (~(1 << i))) | ((val & 1) << i);
    }

    vector<string> aho_corasick_algorithm(vector<string>& words) {
        int max_length = 100 * 30, n_chars = 27;
        std::vector<std::vector<int>> graph(max_length,
                                            std::vector<int>(n_chars, -1));
        std::vector<int> suffix(max_length, -1);
        std::vector<int> out(max_length, 0);
        int state = 1, current_state = 0, ch;
        size_t i = 0;
        for (string s : words) {
            current_state = 0;
            for (char c : s) {
                ch = c - 'a';
                if (graph[current_state][ch] == -1) {
                    graph[current_state][ch] = state++;
                }
                current_state = graph[current_state][ch];
            }
            out[current_state] |= (1 << (i++));
        }

        std::queue<int> q;
        for (i = 0; i < n_chars; ++i) {
            if (graph[0][i] == -1) {
                graph[0][i] = 0;
            } else {
                suffix[graph[0][i]] = 0;
                q.push(graph[0][i]);
            }
        }
        int f;
        while (q.size()) {
            state = q.front();
            q.pop();

            for (i = 0; i < n_chars; ++i) {
                if (graph[state][ch] != -1) {
                    f = suffix[state];

                    while (graph[f][ch] == -1) {
                        f = suffix[f];
                    }

                    f = graph[f][ch];
                    suffix[graph[state][ch]] = f;

                    out[graph[state][ch]] |= out[f];

                    q.push(graph[state][ch]);
                }
            }
        }

        int result = 0, out_mask;
        i = 0;
        for (string s : words) {
            current_state = 0;
            for (char c : s) {
                ch = c - 'a';
                while (graph[current_state][ch] == -1) {
                    current_state = suffix[current_state];
                }
                current_state = graph[current_state][ch];
                result |= set_bit(out[current_state], i, 0);
            }
            ++i;
        }
        std::cout << result << std::endl;
        std::vector<string> output;
        output.reserve(words.size());

        for (i = 0; result != 0 && i < words.size(); ++i) {
            if (((result >> i) & 1) == 1) {
                output.push_back(words[i]);
            }
        }
        return output;
    }

    bool is_substring(std::string s_i, std::string s_j) {
        std::queue<int> match_first_index;
        for (size_t i = 0, j = 0; j < s_j.size(); ++j) {
            if (s_i[i] == s_j[j]) {
                ++i;
                if (s_i.size() == i) {
                    std::cout << s_i << " " << s_j << std::endl;
                    return true;
                }
            } else {
                i = 0;
                if (!match_first_index.empty()) {
                    j = match_first_index.front();
                    match_first_index.pop();
                }
            }

            if (s_i[0] == s_j[j]) {
                match_first_index.push(j);
            }
        }
        return false;
    }

    bool get_bit(int bits, int pos) { return ((bits >> pos) & 1) == 1; }

    vector<string> stringMatching(vector<string>& words) {
        std::vector<string> output;
        std::vector<int> index(words.size(), 0);
        int result = 0, aux;
        output.reserve(words.size());
        int size_words = words.size();
        for (size_t i = 0; i < words.size(); ++i) {
            index[i] = i;
        }
        for (size_t i = 0; i < size_words; ++i) {
            for (size_t j = i + 1; j < size_words; ++j) {
                if (words[index[i]].size() < words[index[j]].size()) {
                    if (words[index[j]].find(words[index[i]]) != string::npos) {
                        output.push_back(words[index[i]]);
                        index[i] = index[size_words - 1];
                        --size_words;
                        --i;
                        break;
                    }
                } else if (words[index[i]].find(words[index[j]]) !=
                           string::npos) {
                    output.push_back(words[index[j]]);
                    index[j] = index[size_words - 1];
                    --size_words;
                    --j;
                }
            }
        }

        return output;
    }
};