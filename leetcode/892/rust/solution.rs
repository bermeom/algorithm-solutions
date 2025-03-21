/*
    892. Surface Area of 3D Shapes
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::cmp;

impl Solution {
    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
            let mut res:i32=0;
            for i in 0..grid.len(){
                for j in 0..grid[i].len(){
                    if (grid[i][j] > 0){
                        res+= 4 * grid[i][j]+ 2 ;
                    }
                    
                    if (i > 0){
                        res-=2*cmp::min(grid[i][j],grid[i-1][j]);
                    }

                    if (j > 0){
                        res-=2*cmp::min(grid[i][j],grid[i][j-1]);
                    }
                }
            }
            return res;
    }
}