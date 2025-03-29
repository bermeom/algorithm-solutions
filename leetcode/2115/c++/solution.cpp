/*
    2115. Find All Possible Recipes from Given Supplies
    Author: Miguel Angel Bermeo Ayerbe
*/
// Hashmap+Kahn's algorithm
class Solution {
   public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        std::unordered_set<std::string> supplies_set(supplies.begin(),
                                                     supplies.end());
        std::unordered_map<std::string, std::vector<size_t>> recipes_map;
        std::vector<std::string> output;
        std::queue<size_t> recipes_queue;
        std::vector<size_t> num_dep(recipes.size(), 0);
        for (size_t i = 0; i < recipes.size(); ++i) {
            for (const std::string& ingredient_i_j : ingredients[i]) {
                if (supplies_set.count(ingredient_i_j) == 0) {
                    recipes_map[ingredient_i_j].push_back(i);
                    ++num_dep[i];
                }
            }
            if (num_dep[i] == 0) {
                recipes_queue.push(i);
                supplies_set.insert(recipes[i]);
            }
        }
        while (!recipes_queue.empty()) {
            const size_t i = recipes_queue.front();
            recipes_queue.pop();
            output.push_back(recipes[i]);
            for (const size_t& j : recipes_map[recipes[i]]) {
                --num_dep[j];
                if (num_dep[j] == 0) {
                    recipes_queue.push(j);
                }
            }
        }
        return output;
    }
};