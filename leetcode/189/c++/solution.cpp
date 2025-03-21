/*
    189. Rotate Array
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int previous = nums[0], temp;
        for (size_t i = 0, current = 0, next = 0, start = 0; i < nums.size();
             ++i) {
            next = (current + k) % nums.size();
            temp = nums[next];
            nums[next] = previous;
            previous = temp;
            current = next;
            if (start == current && i + 1 < nums.size()) {
                ++current;
                ++start;
                previous = nums[start];
            }
        }
    }
};