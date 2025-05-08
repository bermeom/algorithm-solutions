/*
    763. Partition Labels
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    vector<int> partitionLabels(string s) {
        int global_marks = 0, bit = 0;
        std::vector<int> output;
        std::vector<int> marks;

        for (size_t i = 0; i < s.size(); ++i) {
            bit = 1 << (s[i] - 'a');
            // std::cout<<i<<" "<<output.size()<<" "<<marks.size()<<"
            // "<<(bit&global_marks)<<std::endl;
            if (i == 0 || (bit & global_marks) == 0) {
                output.push_back(i + 1);
                marks.push_back(bit);
            } else if ((bit & marks.back()) != 0) {
                output.back() = i + 1;
            } else {
                while (marks.size() > 1 && (bit & marks.back()) == 0) {
                    marks[marks.size() - 2] |= marks.back();
                    marks.pop_back();
                    output.pop_back();
                }
                output.back() = i + 1;
            }
            global_marks |= bit;
        }
        for (size_t i = output.size() - 1; i > 0; --i) {
            output[i] -= output[i - 1];
        }
        return output;
    }
};