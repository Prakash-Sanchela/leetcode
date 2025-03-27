#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else
            {
                if (s[i] == ')' || s[i] == '}' || s[i] == ']')
                {
                    if (!st.empty()) {
                        char ch = st.top();
                        st.pop();
                        if ((s[i] == ')' && ch == '(') || 
                            (s[i] == '}' && ch == '{')  || 
                            (s[i] == ']' && ch == '[')
                            ){ 
                            continue;
                            }
                        else
                            return false;
                    }
                    else
                        st.push(s[i]);
                }
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};
