class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        stack<char> st;
        string res;

        for (char ch : s) 
        {
            if (ch == '(') 
            {
                // If stack is not empty, add '(' to result
                if (!st.empty()) 
                {
                    res += ch;
                }
                st.push(ch);
            } 
            else if (ch == ')') 
            {
                st.pop();
                // If stack is not empty after pop, add ')' to result
                if (!st.empty()) 
                {
                    res += ch;
                }
            }
        }
        return res;
    }
};