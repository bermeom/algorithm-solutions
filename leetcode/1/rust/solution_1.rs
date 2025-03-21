/*
    1. Two Sum
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn argsort<T: Ord>(data: &[T]) -> Vec<usize> {
        let mut indices = (0..data.len()).collect::<Vec<_>>();
        indices.sort_by_key(|&i| &data[i]);
        indices
    }

    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let sorted_indices = Self::argsort(&nums);
        let (mut left, mut right) = (0, nums.len()-1);
        let mut  output: Vec<i32> = vec![0,0];
        let mut sum2:i32 = 0;
        while (left < right){
            sum2 = nums[sorted_indices[left]] + nums[sorted_indices[right]];
            if (sum2 == target){
                output[0] = sorted_indices[left] as i32;
                output[1] = sorted_indices[right] as i32;
                break;
            }else if (sum2 > target){
                right-=1;
            }else{
                left+=1;
            }

        }
        output
    }
}