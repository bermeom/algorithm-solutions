/*
    354. Russian Doll Envelopes
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn max_envelopes(envelopes: Vec<Vec<i32>>) -> i32 {
        let mut envelopes = envelopes.clone();
        envelopes.sort_by(|a, b| {
            if a[0] == b[0] {
                b[1].cmp(&a[1])
            } else {
                a[0].cmp(&b[0])
            }
        });
        let mut dp: Vec<i32> = Vec::with_capacity(envelopes.len());
        for envelope_i in envelopes {
            let lower_bound = dp.partition_point(|x| x < &envelope_i[1]);
            if dp.len() == lower_bound {
                dp.push(envelope_i[1]);
            } else {
                dp[lower_bound] = envelope_i[1];
            }
        }
        dp.len() as i32
    }
}
