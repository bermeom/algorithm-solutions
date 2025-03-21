/*
    300. Longest Increasing Subsequence
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::cmp;
use std::collections::HashMap; 
use std::collections::VecDeque;

impl Solution {

    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut graph:HashMap<usize, Vec<Vec<usize>>>=HashMap::new();
        let mut max_level:Vec<usize>=vec![0;nums.len()];
        let mut length:i32=0;
        for i in 0..nums.len(){
            max_level[i]=0;
            // Search
            let mut queue: VecDeque<(usize,usize)> = VecDeque::new();
            for index in graph.keys(){
                if (nums[*index]<nums[i]){
                    queue.push_back((*index,0));
                }
            }
            while (!queue.is_empty()){
                let mut front_opt=queue.front_mut();
                if let Some((mut root_index, mut level)) = front_opt {
                    let mut tree_index_opt = graph.get_mut(&root_index);
                    if let Some(mut tree_index)= tree_index_opt {
                        if (tree_index.len() == level){
                            tree_index.push(vec![i]);
                            max_level[i] = cmp::max(level+2,max_level[i]);
                        }else{
                            let mut go_to_next_level:bool=false;
                            for j in 0..tree_index[level].len(){
                                let index=tree_index[level][j];
                                if (nums[index]<nums[i]){
                                    let mut new_tuple=(((root_index),level+1));
                                    queue.push_back(new_tuple);
                                    go_to_next_level=true;
                                    break;
                                }
                            }
                            if (!go_to_next_level){
                                tree_index[level].push(i);
                                max_level[i] = cmp::max(level+2,max_level[i]);
                            }
                        }
                    }
                }
                queue.pop_front();
                
            }
            // --------------
            if (max_level[i]==0){
                max_level[i]=1;
                graph.insert(i,Vec::<Vec<usize>>::new());
            }
            length=cmp::max(length,max_level[i] as i32);
        }
                
        return cmp::max(length,1);
    }




}