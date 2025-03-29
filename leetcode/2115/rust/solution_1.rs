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
        let mut recipes_map: HashMap<String, HashSet<String>> = HashMap::new();
        let mut ingredients_map: HashMap<String, HashSet<String>> = HashMap::new();
        let mut supplies_set: HashSet<String> = HashSet::from_iter(supplies.iter().cloned());
        let mut output: Vec<String> = Vec::with_capacity(recipes.len());
        for i in 0..recipes.len() {
            let mut need_ingredients = false;
            for j in 0..ingredients[i].len() {
                if !supplies_set.contains(&ingredients[i][j]) {
                    need_ingredients = true;
                    ingredients_map
                        .entry(ingredients[i][j].clone())
                        .or_insert(HashSet::new())
                        .insert(recipes[i].clone());
                    recipes_map
                        .entry(recipes[i].clone())
                        .or_insert(HashSet::new())
                        .insert(ingredients[i][j].clone());
                }
            }

            if !need_ingredients {
                output.push(recipes[i].clone());
                supplies_set.insert(recipes[i].clone());

                let mut queue: VecDeque<String> = VecDeque::new();
                queue.push_back(recipes[i].clone());
                while !queue.is_empty() {
                    if let Some(recipe_j) = queue.pop_front() {
                        if let Some(recipes_depends_of) = ingredients_map.get(&recipe_j) {
                            for recipe_k in recipes_depends_of {
                                if let Some(ingredients_k) = recipes_map.get_mut(recipe_k) {
                                    ingredients_k.remove(&recipe_j);
                                    if ingredients_k.len() == 0 {
                                        output.push(recipe_k.clone());
                                        queue.push_back(recipe_k.clone());
                                        supplies_set.insert(recipe_k.clone());
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        output
    }
}
