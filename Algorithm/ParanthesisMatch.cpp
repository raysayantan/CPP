/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        while(s[i] != '\0'){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(!st.empty()){
                    char top = st.top();
                    st.pop();
                    if(top == '(' && s[i] != ')') return false;
                    if(top == '{' && s[i] != '}') return false;
                    if(top == '[' && s[i] != ']') return false;
                } else {
                    return false;
                }
            }
            i++;
        }
        if(!st.empty()) return false;
        return true;
    }
};
