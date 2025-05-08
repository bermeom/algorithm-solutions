/*
    2551. Put Marbles in Bags
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
        let mut output: i64 = 0;
        let k: usize = k as usize - 1;
        if (k > 0 && weights.len() - 1 > k) {
            let mut weights_mut: Vec<i32> = Vec::with_capacity(weights.len());
            for i in 0..(weights.len() - 1) {
                weights_mut.push(weights[i] + weights[i + 1]);
            }
            weights_mut.select_nth_unstable(k);
            for i in 0..(k as usize) {
                output -= weights_mut[i] as i64;
            }
            let n = weights_mut.len() - k - 1;
            weights_mut.select_nth_unstable(n);
            for i in 0..(k as usize) {
                output += weights_mut[weights_mut.len() - i - 1] as i64;
            } //*/
        }
        output
    }
}
