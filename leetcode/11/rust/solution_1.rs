/*
    11. Container With Most Water
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::cmp;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut max_water: i32 = 0;
        let mut min_height: i32 = 0;
        let mut min_height_k: i32 = 0;
        let mut max_water_k: i32 = 0;

        for i in 0..(height.len()-1) {
            if min_height < height[i] {
                for j in (i+1)..height.len() {
                    min_height_k = cmp::min(height[i], height[j]);
                    max_water_k = min_height_k*((j-i) as i32);
                    if max_water < max_water_k {
                        max_water = max_water_k;
                        min_height = min_height_k;
                    }
                    
                }
            }
        }
        return max_water;
    }
}