/*
    53. Maximum Subarray
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut max_sum: i32 = nums[0];
        let mut local_sum: i32 = 0;
        for num_i in nums.iter() {
            local_sum += *num_i;
            max_sum = max_sum.max(local_sum);
            local_sum = local_sum.max(0);
        }
        max_sum
    }
}