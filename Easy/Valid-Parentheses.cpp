#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        int x = 0;

        while(s[x] != '\0'){
            if(s[x] == '(') st.push(s[x]);
            else if(s[x] == '[') st.push(s[x]);
            else if(s[x] == '{') st.push(s[x]);

            else if(s[x] == ')'){
                if (st.empty())
                    return false;
                if(st.top() == '(')
                    st.pop();
                else
                    return false;

            }
            else if(s[x] == ']'){
                if (st.empty())
                    return false;
                if(st.top() == '[')
                    st.pop();
                else
                    return false;
            }
            else if(s[x] == '}'){
                if (st.empty())
                    return false;
                if(st.top() == '{')
                    st.pop();
                else
                    return false;
            }

            x++;
        }
        if(st.empty())
            return true;
        return false;
    }
};

int main() {
    Solution solution;
    std::string s = "{[()]}";
    if (solution.isValid(s)) {
        std::cout << "The string is valid." << std::endl;
    } else {
        std::cout << "The string is not valid." << std::endl;
    }
    return 0;
}