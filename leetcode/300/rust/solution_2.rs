/*
    300. Longest Increasing Subsequence
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut memory: Vec<i32> = Vec::with_capacity(nums.len());
        for num_i in nums {
            if memory.len() == 0 || num_i > *memory.last().unwrap(){
                memory.push(num_i);
            }else{
                let index_lower_result = memory.binary_search(&num_i);
                if let Err(index) = index_lower_result {
                    if memory[index] > num_i {
                        memory[index] = num_i;
                    }
                }
            }
        }
        memory.len() as i32
    }
}