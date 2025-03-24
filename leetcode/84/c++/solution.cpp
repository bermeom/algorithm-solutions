/*
    84. Largest Rectangle in Histogram
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> stack_heights;
        stack_heights.push(-1);
        int output = 0, height = 0, width = 1;
        for (size_t i = 0; i <= heights.size(); ++i) {
            while (stack_heights.top() >= 0 &&
                   (i == heights.size() ||
                    (i < heights.size() &&
                     heights[i] <= heights[stack_heights.top()]))) {
                height = heights[stack_heights.top()];
                stack_heights.pop();
                width = i - stack_heights.top() - 1;
                output = max(output, height * width);
            }
            if (i < heights.size()) {
                stack_heights.push(i);
            }
        }
        return output;
    }
};
