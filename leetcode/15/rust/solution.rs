/*
    15. 3Sum
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn argsort<T: Ord>(data: &[T]) -> Vec<usize> {
        let mut indices = (0..data.len()).collect::<Vec<_>>();
        indices.sort_by_key(|&i| &data[i]);
        indices
    }

    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let sorted_indices = Self::argsort(&nums);
        let mut output: Vec<Vec<i32>> = Vec::new();
        let mut sum3 = 0;
        let (mut left, mut right) = (0, 0);
        for i in 0..(sorted_indices.len() - 2) {
            if nums[sorted_indices[i]] <= 0
                && (i == 0 || (i > 0 && nums[sorted_indices[i]] != nums[sorted_indices[i - 1]]))
            {
                left = i + 1;
                right = sorted_indices.len() - 1;

                while left < right && nums[sorted_indices[i]] + nums[sorted_indices[left]] <= 0 {
                    sum3 = nums[sorted_indices[i]]
                        + nums[sorted_indices[left]]
                        + nums[sorted_indices[right]];
                    if sum3 == 0 {
                        output.push(vec![
                            nums[sorted_indices[i]],
                            nums[sorted_indices[left]],
                            nums[sorted_indices[right]],
                        ]);
                        left += 1;
                        while left < right
                            && nums[sorted_indices[left - 1]] == nums[sorted_indices[left]]
                        {
                            left += 1;
                        }
                    } else if sum3 < 0 {
                        left += 1;
                    } else {
                        //sum3 > 0
                        right -= 1;
                    }
                }
            }
        }
        output
    }
}
