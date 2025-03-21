/*
    239. Sliding Window Maximum
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k_length = k as usize;
        let mut result: Vec<i32> = Vec::with_capacity(nums.len() - k_length + 1 );
        let mut max_i: i32 = 0;
        for i in 0..result.capacity() {
            if i == 0 || (i > 0 && max_i == nums[i-1] && max_i > nums[i+k_length-1]) {
                max_i = *nums[i..(i+k_length)].iter().max().unwrap();
            }else {
                max_i = i32::max(max_i,nums[i+k_length-1] );
            }
            result.push(max_i);
        }
        result
    }
}