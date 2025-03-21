/*
    7. Reverse Integer
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int reverse(int x) {
        bool is_negative = x < 0;
        int output = 0, max_int = -((1 << 32 - 1) / 10),
            last_digit = is_negative ? 7 : 6;
        int sign = is_negative ? -1 : 1;

        for (int x_i; x != 0 || output < 0; x /= 10) {
            x_i = sign * (x % 10);
            if (max_int >= output && !(max_int == output && x_i > last_digit)) {
                output = output * 10 + x_i;
            } else {
                output = -1;
                break;
            }
        }
        if (output < 0) {
            output = 0;
        }
        return sign * output;
    }
};