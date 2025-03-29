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
        fn get_id(
            recipe: &String,
            str_id_map: &mut HashMap<String, usize>,
            id_str_map: &mut Vec<String>,
            id: &mut usize,
        ) -> usize {
            let recipe_id = *str_id_map.entry(recipe.clone()).or_insert(*id);
            if recipe_id == *id {
                id_str_map.push(recipe.clone());
                *id = str_id_map.len();
            }
            recipe_id
        }
        // Code
        let mut recipes_map: HashMap<usize, HashSet<usize>> = HashMap::new();
        let mut ingredients_map: HashMap<usize, HashSet<usize>> = HashMap::new();
        let mut supplies_set: HashSet<String> = HashSet::from_iter(supplies.iter().cloned());
        let mut output: Vec<String> = Vec::with_capacity(recipes.len());
        let mut str_id_map: HashMap<String, usize> = HashMap::new();
        let mut id_str_map: Vec<String> = Vec::with_capacity(recipes.len());
        let mut id = 0;
        for i in 0..recipes.len() {
            // Get ID
            let recipe_id: usize = get_id(&recipes[i], &mut str_id_map, &mut id_str_map, &mut id);

            let mut need_ingredients = false;
            for j in 0..ingredients[i].len() {
                if !supplies_set.contains(&ingredients[i][j]) {
                    need_ingredients = true;
                    let recipe_id_j: usize = get_id(
                        &ingredients[i][j],
                        &mut str_id_map,
                        &mut id_str_map,
                        &mut id,
                    );

                    ingredients_map
                        .entry(recipe_id_j)
                        .or_insert(HashSet::new())
                        .insert(recipe_id);
                    recipes_map
                        .entry(recipe_id)
                        .or_insert(HashSet::new())
                        .insert(recipe_id_j);
                }
            }

            if !need_ingredients {
                output.push(recipes[i].clone());
                supplies_set.insert(recipes[i].clone());

                let mut queue: VecDeque<usize> = VecDeque::new();
                queue.push_back(recipe_id);
                while !queue.is_empty() {
                    if let Some(recipe_id_j) = queue.pop_front() {
                        if let Some(recipes_depends_of) = ingredients_map.get_mut(&recipe_id_j) {
                            recipes_depends_of.retain(|recipe_id_k| {
                                let mut must_deleted = false;
                                if let Some(ingredients_k) = recipes_map.get_mut(recipe_id_k) {
                                    ingredients_k.remove(&recipe_id_j);
                                    if ingredients_k.len() == 0 {
                                        let recipe_str_k = id_str_map[*recipe_id_k].clone();
                                        output.push(recipe_str_k.clone());
                                        queue.push_back(*recipe_id_k);
                                        supplies_set.insert(recipe_str_k);
                                        must_deleted = true;
                                    }
                                }
                                must_deleted
                            });
                        }
                    }
                }
            }
        }
        output
    }
}
