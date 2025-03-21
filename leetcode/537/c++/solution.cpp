/*
    537. Complex Number Multiplication
    Author: Miguel Angel Bermeo Ayerbe
*/
#include <complex>
#include <string>
class Solution {
   public:
    template <typename T,
              typename = std::enable_if_t<std::is_arithmetic<T>::value>>
    std::complex<T> strnum2complexnum(std::string str_num) {
        T array_num[2] = {0, 0};
        size_t part = 0;
        T sign = 1;
        for (size_t i = 0; i < str_num.size(); ++i) {
            if ('0' <= str_num[i] && str_num[i] <= '9') {
                array_num[part] = array_num[part] * 10 +
                                  static_cast<double>(str_num[i] - '0');
            } else if ('+' == str_num[i]) {
                array_num[part] *= sign;
                part = 1;
                sign = 1;
            } else if ('-' == str_num[i]) {
                sign = -1;
            }
        }
        array_num[part] *= sign;
        return std::complex<T>(array_num[0], array_num[1]);
    }

    string complexNumberMultiply(string num1, string num2) {
        std::complex<int64_t> n_1(strnum2complexnum<int64_t>(num1));
        std::complex<int64_t> n_2(strnum2complexnum<int64_t>(num2));
        std::complex<int64_t> results = n_1 * n_2;
        // std::cout<<n_1<<" * "<<n_2<<" = "<<results<<std::endl;
        return std::to_string(results.real()) + "+" +
               std::to_string(results.imag()) + "i";
    }
};