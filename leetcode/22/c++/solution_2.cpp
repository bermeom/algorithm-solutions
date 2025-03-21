/*
    22. Generate Parentheses
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    void get_solution(int n, size_t open_parentheses, size_t close_parentheses,
                      std::string &solution, std::vector<std::string> &output) {
        if (open_parentheses == n && close_parentheses == n) {
            output.push_back(solution);
            return;
        }

        if (open_parentheses < n) {
            solution.push_back('(');
            get_solution(n, open_parentheses + 1, close_parentheses, solution,
                         output);
            solution.pop_back();
        }
        if (open_parentheses > close_parentheses) {
            solution.push_back(')');
            get_solution(n, open_parentheses, close_parentheses + 1, solution,
                         output);
            solution.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> output;
        std::string solution;
        solution.reserve(n * 2);
        get_solution(n, 0, 0, solution, output);
        return output;
    }
};
