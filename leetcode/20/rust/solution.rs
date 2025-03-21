/*
    20. Valid Parentheses
    Author: Miguel Angel Bermeo Ayerbe
*/
class Solution {
    public:
        bool isValid(string s) {
            std::stack<char> s_parentheses;
            char open_p;
            for (const char &s_i:s){
                if (s_i == '{' || s_i == '(' || s_i == '['){
                    s_paremtheses.push(s_i);
                }else{
                    open_p=' ';
                    switch(s_i){
                        case('}'): open_p='{'; break;
                        case(')'): open_p='('; break;
                        case(']'): open_p='['; break;
                    };
                    if (s_paremtheses.empty() || open_p != s_paremtheses.top() ){
                        return false;
                    }
                    s_paremtheses.pop();
                }
            }
            return s_paremtheses.empty();
        }
    };