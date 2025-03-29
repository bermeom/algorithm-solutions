/*
    2115. Find All Possible Recipes from Given Supplies
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::collections::HashMap;
use std::collections::HashSet;
use std::collections::VecDeque;
impl Solution {
    pub fn find_all_recipes(
        recipes: Vec<String>,
        ingredients: Vec<Vec<String>>,
        supplies: Vec<String>,
    ) -> Vec<String> {
        let mut supplies_set: HashSet<String> = HashSet::from_iter(supplies.iter().cloned());
        let mut in_degree: Vec<usize> = vec![0; recipes.len()];
        let mut recipe_map: HashMap<String, Vec<usize>> = HashMap::new();
        let mut output: Vec<String> = Vec::new();
        let mut queue: VecDeque<usize> = VecDeque::new();
        for i in 0..recipes.len() {
            for j in 0..ingredients[i].len() {
                if !supplies_set.contains(&ingredients[i][j]) {
                    recipe_map
                        .entry(ingredients[i][j].clone())
                        .or_insert(Vec::new())
                        .push(i);
                    in_degree[i] += 1;
                }
            }
            if in_degree[i] == 0 {
                supplies_set.insert(recipes[i].clone());
                queue.push_back(i);
            }
        }
        while !queue.is_empty() {
            if let Some(i) = queue.pop_front() {
                output.push(recipes[i].clone());
                if let Some(ingredients_j) = recipe_map.get(&recipes[i]) {
                    for j in ingredients_j {
                        in_degree[*j] -= 1;
                        if in_degree[*j] == 0 {
                            queue.push_back(*j);
                        }
                    }
                }
            }
        }
        output
    }
}
