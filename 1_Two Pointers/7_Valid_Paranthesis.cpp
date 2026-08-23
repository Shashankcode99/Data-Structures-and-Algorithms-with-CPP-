//CPP Solution

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {

            // Opening brackets
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            // Closing brackets
            else {
                // No opening bracket available
                if (st.empty()) {
                    return false;
                }

                char openingBracket = st.top();
                st.pop();

                if (s[i] == ')' && openingBracket != '(') {
                    return false;
                }

                if (s[i] == '}' && openingBracket != '{') {
                    return false;
                }

                if (s[i] == ']' && openingBracket != '[') {
                    return false;
                }
            }
        }

        // If stack is not empty, some opening brackets are unmatched
        if (!st.empty()) {
            return false;
        }

        return true;
    }
};