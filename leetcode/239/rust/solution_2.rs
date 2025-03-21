/*
    239. Sliding Window Maximum
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::collections::VecDeque;

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k_usize = k as usize;
        let mut output: Vec<i32> = vec![0;nums.len()+1-k_usize];
        let mut deque: VecDeque<usize> = VecDeque::new();
        for i in 0..nums.len(){
            while !deque.is_empty() && nums[*deque.back().unwrap()] <= nums[i] {
                deque.pop_back();
            }
            deque.push_back(i);
            if i >= k_usize-1 {
                if *deque.front().unwrap() < (i+1)-k_usize {
                    deque.pop_front();
                }
                output[(i+1)-k_usize] = nums[*deque.front().unwrap()];
            }
        }
        output
    }
}