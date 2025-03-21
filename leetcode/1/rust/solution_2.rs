/*
    1. Two Sum
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hash_map = HashMap::new();
        for i in 0..nums.len(){
            let temp = target-nums[i];
            match hash_map.get(&temp) {
                Some(j) => {
                    return vec![*j as i32,i as i32];
                },
                None => {
                    hash_map.insert(nums[i], i);
                }
            }
        }
        Vec::new()
    }
}