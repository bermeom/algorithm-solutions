/*
    63. Unique Paths II
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let (n,m) = (obstacle_grid.len(),obstacle_grid[0].len());
        if obstacle_grid[0][0]+obstacle_grid[n-1][m-1] > 0{
            return 0;
        }

        let mut row_i: Vec<i32> = vec![0;m];
        
        row_i[0] = -1;
        for i in 0..n {
            for j in 0..m {
                if  obstacle_grid[i][j] == 0 {
                    if i > 0 && obstacle_grid[i-1][j] == 1 {
                        row_i[j] = 0;
                    }
                    if j > 0 && obstacle_grid[i][j-1] == 0 {
                        row_i[j] += row_i[j-1];
                    }

                }
            } 
        }
        -row_i[m-1]
    }
}