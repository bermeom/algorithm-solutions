/*
    84. Largest Rectangle in Histogram
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let mut stack: Vec<usize> = Vec::with_capacity(heights.len() + 1);
        stack.push(0);
        let mut max_area: i32 = 0;
        let mut stack_top: usize = 0;
        for i in 0..(heights.len() + 1) {
            stack_top = *stack.last().unwrap();
            while (stack_top != 0
                && (i == heights.len()
                    || (i < heights.len() && heights[i] < heights[stack_top - 1])))
            {
                let height = heights[stack_top - 1];
                stack.pop();
                stack_top = *stack.last().unwrap();
                let width = (i - stack_top) as i32;
                max_area = max_area.max(height * width);
            }
            stack.push(i + 1);
        }
        max_area
    }
}
