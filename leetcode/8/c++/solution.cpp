/*
    8. String to Integer (atoi)
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
   public:
    int myAtoi(string s) {
        int output = 0;
        int min_int = std::numeric_limits<int>::min();
        int max_int = std::numeric_limits<int>::max();
        int sign = 0, aux;

        for (const char &s_i : s) {
            if ((sign == 0 && (s_i == '-' || s_i == '+')) ||
                ('0' <= s_i && s_i <= '9')) {
                if (sign == 0 && s_i == '-') {
                    sign = -1;
                } else if (sign == 0) {
                    sign = 1;
                }
                if ('0' <= s_i && s_i <= '9') {
                    aux = s_i - '0';
                    if ((max_int / 10 == output &&
                         aux >= 7 + static_cast<int>(sign == -1)) ||
                        (max_int / 10 < output)) {
                        if (sign == -1) {
                            output = min_int;
                        } else {
                            output = max_int;
                        }
                        break;
                    } else {
                        output = output * 10 + aux;
                    }
                }
            } else if (!(s_i == ' ' && sign == 0)) {
                break;
            }
        }
        return output == min_int ? output : sign * output;
    }
};