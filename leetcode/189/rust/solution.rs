/*
    189. Rotate Array
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn reverse(nums: &mut Vec<i32>,lb:usize,ub:usize){
        let middle:usize=(ub-lb)/2;
        for i in 0..(middle) {
            nums.swap(i+lb,ub-i-1);
        }
    }
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let k_movs:usize=(k as usize)%nums.len();
        nums.reverse();
        Solution::reverse(nums,0,k_movs);
        Solution::reverse(nums,k_movs,nums.len());
    }

}