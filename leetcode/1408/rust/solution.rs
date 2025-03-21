/*
    1408. String Matching in an Array
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        let mut output: Vec<String> = Vec::with_capacity(words.len());
        for i in 0..words.len(){
            for j in 0..words.len(){
                if i!=j && words[j].contains(&words[i]) {
                    output.push(words[i].clone());
                    break;
                }
            }
        }
        output
    }
}