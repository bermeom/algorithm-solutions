/*
    136. Single Number
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut result: i32 = 0;
        for num_i in nums.iter() {
            result ^=*num_i; 
        }
        result
    }
}