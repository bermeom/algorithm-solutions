/*
    3121. Count the Number of Special Characters II
    Author: Miguel Angel Bermeo Ayerbe
*/
#[derive(Clone,PartialEq)]
enum Mark {
    None,
    Lowercase,
    Uppercase,
    NonSpecial
}

impl Solution {
    
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut letter_map: Vec<Mark> = vec![Mark::None; 26];
        let mut non_special_count: i32 = 0;
        for letter_i in word.as_bytes() {
            if b'a' <= *letter_i && *letter_i <= b'z'{
                let i = (*letter_i-b'a') as usize;
                if letter_map[i] != Mark::Lowercase && letter_map[i] != Mark::NonSpecial {
                    letter_map[i] = if letter_map[i] == Mark::None {Mark::Lowercase} 
                                    else {Mark::NonSpecial};
                    if (letter_map[i] == Mark::NonSpecial){
                        non_special_count+=1;
                    }
                }
            }else{
                let i = (*letter_i-b'A') as usize;
                if letter_map[i] != Mark::Uppercase && letter_map[i] != Mark::NonSpecial {
                    letter_map[i] = if letter_map[i] == Mark::Lowercase {Mark::Uppercase} 
                                        else {Mark::NonSpecial};
                    if (letter_map[i] == Mark::NonSpecial){
                        non_special_count+=1;
                    }
                }   
            }
            if non_special_count >= 26{
                return 0;
            }
        }

        let mut count: i32 = 0;
        for letter_i in letter_map {
            count += if letter_i == Mark::Uppercase {1} else {0};
        }
        count
    }
}