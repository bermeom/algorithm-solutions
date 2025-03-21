/*
    2351. First Letter to Appear Twice
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut marks: usize = 0;
        for byte_i in s.as_bytes(){
            let i = usize::from(*byte_i - b'a');
            if 1 & (marks>>i) == 1 {
                return *byte_i as char;
            }
            marks |= 1<<i;
        }
        'a'
    }
}