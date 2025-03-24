/*
    2685. Count the Number of Complete Components
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::collections::HashMap;
impl Solution {
    pub fn find_parent(parents: &mut Vec<usize>, id_node: usize) -> usize {
        let mut id_parent: usize = parents[id_node];
        if id_parent != parents[id_parent] {
            id_parent = Self::find_parent(parents, id_parent)
        }
        id_parent
    }

    pub fn union_nodes(
        parents: &mut Vec<usize>,
        ranks: &mut Vec<usize>,
        id_node_1: usize,
        id_node_2: usize,
    ) {
        let id_parent_1 = Self::find_parent(parents, id_node_1);
        let id_parent_2 = Self::find_parent(parents, id_node_2);
        if id_parent_1 != id_parent_2 {
            if ranks[id_parent_1] < ranks[id_parent_2] {
                parents[id_parent_1] = id_parent_2;
            } else if ranks[id_parent_1] > ranks[id_parent_2] {
                parents[id_parent_2] = id_parent_1;
            } else {
                parents[id_parent_2] = id_parent_1;
                ranks[id_parent_1] += 1;
            }
        }
    }

    pub fn count_complete_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut output: i32 = 0;
        let n_nodes = n as usize;
        let mut parents: Vec<usize> = (0..n_nodes).collect();
        let mut ranks: Vec<usize> = vec![0; n_nodes];
        // 1. Union edges
        for edge_i in &edges {
            Self::union_nodes(
                &mut parents,
                &mut ranks,
                edge_i[0] as usize,
                edge_i[1] as usize,
            );
        }
        // 2. Count number of nodes
        let mut map: HashMap<usize, (usize, usize)> = HashMap::new();
        for id_node in 0..n_nodes {
            map.entry(Self::find_parent(&mut parents, id_node))
                .or_insert((0, 0))
                .0 += 1;
        }
        // 3. Count number of edges
        for edge_i in &edges {
            map.entry(Self::find_parent(&mut parents, edge_i[0] as usize))
                .or_insert((0, 0))
                .1 += 1;
        }
        // 4. Compute complete components
        for (root, (num_nodes, num_edges)) in map.iter() {
            if *num_edges == (*num_nodes * (*num_nodes - 1)) / 2 {
                output += 1;
            }
        }
        output
    }
}
