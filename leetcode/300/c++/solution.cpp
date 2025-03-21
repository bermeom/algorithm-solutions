/*
    300. Longest Increasing Subsequence
    Author: Miguel Angel Bermeo Ayerbe
*/
template <typename T>
typename std::vector<T>::iterator insert_sorted(std::vector<T>& vec,
                                                T const&& item) {
    return vec.insert(std::upper_bound(vec.begin(), vec.end(), item), item);
}

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int longest_length = 1;
        std::vector<std::pair<int, int>> sorter_vector;
        sorter_vector.reserve(nums.size());
        sorter_vector.push_back(std::make_pair(1, -nums[0]));
        bool was_inserted = false;
        for (size_t i = 1; i < nums.size(); ++i) {
            was_inserted = false;
            for (size_t j = sorter_vector.size(); j > 0; --j) {
                if (nums[i] > -sorter_vector[j - 1].second) {
                    longest_length =
                        max(longest_length, sorter_vector[j - 1].first + 1);
                    insert_sorted(sorter_vector,
                                  std::make_pair(sorter_vector[j - 1].first + 1,
                                                 -nums[i]));
                    was_inserted = true;
                    break;
                }
            }
            if (!was_inserted) {
                insert_sorted(sorter_vector, std::make_pair(1, -nums[i]));
            }
        }
        return longest_length;
    }
};

/*
    using T = int;
    std::priority_queue<T, std::vector<T>, std::less<T>> q;

    q.emplace(1); q.emplace(16); q.emplace(5); q.emplace(42); q.emplace(3);

    const T* base = &q.top(); // root of the binary heap
    for(size_t i = 0; i<q.size(); i++)
        std::cout << *(base+i)<<" ";
    std::cout << std::endl; // outputs "42 16 5 1 3"
*/