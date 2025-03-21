/*
    4. Median of Two Sorted Arrays
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        size_t n_m = nums1.size() + nums2.size();

        if (n_m > 1) {
            double val_i = 0, val_i_1 = 0;
            for (size_t i = 0, i1 = 0, i2 = 0; i <= n_m / 2; ++i) {
                val_i_1 = val_i;
                if (i1 < nums1.size() && i2 < nums2.size()) {
                    if (nums1[i1] < nums2[i2]) {
                        val_i = nums1[i1];
                        ++i1;
                    } else {
                        val_i = nums2[i2];
                        ++i2;
                    }
                } else if (i1 < nums1.size()) {
                    val_i = nums1[i1];
                    ++i1;
                } else {
                    val_i = nums2[i2];
                    ++i2;
                }
            }
            result = n_m % 2 == 0 ? (val_i + val_i_1) / 2 : val_i;
        } else if (n_m == 1) {
            result =
                static_cast<double>(nums1.size() > 0 ? nums1[0] : nums2[0]);
        }

        return result;
    }
};