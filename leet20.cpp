/* Valid Parentheses */
/*  Solution using stack
    Time : O(n)
    Space : O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                if(st.top() == '[' && s[i]!=']')
                    return false;
                if(st.top() == '{' && s[i]!='}' )
                    return false;
                if(st.top() == '(' && s[i]!=')' )
                    return false;
                st.pop();
            }

        if(!st.empty())
            return false;

        return true;
    }
};
