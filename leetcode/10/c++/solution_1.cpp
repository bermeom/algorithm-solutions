/*
    10. Regular Expression Matching
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    bool isMatch(string s, string p) {
        bool result = false;
        size_t i = 0, j = 0;
        std::queue<std::pair<size_t, size_t>> q;
        q.push(std::make_pair(0, 0));
        std::pair<size_t, size_t> state_i;
        auto fun = [](char p_i, char s_i) { return p_i == '.' || p_i == s_i; };
        while (!q.empty()) {
            state_i = q.front();
            q.pop();
            i = state_i.first;
            j = state_i.second;
            // std::cout<<i<<" "<<j<<std::endl;
            if (j == s.size() && i == p.size()) {
                result = true;
                break;
            }
            if (i < p.size()) {
                if (p[i] == '*' && (i == 0 || p[i - 1] == '*')) {
                    result = false;
                    break;
                } else if (p[i] != '*' && i + 1 < p.size() &&
                           p[i + 1] == '*') {  // zero or more
                    if (j < s.size() && fun(p[i], s[j])) {
                        q.push(std::make_pair(i, j + 1));
                    }
                    q.push(std::make_pair(i + 2, j));
                } else if (j < s.size() && fun(p[i], s[j])) {
                    q.push(std::make_pair(i + 1, j + 1));
                }
            }
        }
        return result;
    }
};