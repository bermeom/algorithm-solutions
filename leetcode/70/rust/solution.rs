/*
    70. Climbing Stairs
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let length = (n+1) as usize;
        let mut memory: Vec<i32> = Vec::with_capacity(length);
        memory.push(1);
        for i in 1..length{
            memory.push(memory[i-1]);
            if i >= 2 {
                memory[i] += memory[i-2];
            }
        }
        memory[length-1]
    }
}