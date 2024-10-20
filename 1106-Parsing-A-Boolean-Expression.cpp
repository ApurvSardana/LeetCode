class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(int i = 0; i < expression.length(); i++)
        {
            if(expression[i] == ',' || expression[i] == '(')
            continue;

            else if(expression[i] == '&' || expression[i] == '|' || expression[i] == '!' || expression[i] == 't' || expression[i] == 'f')
            {
                st.push(expression[i]);
            }

            else
            {
                    bool hasTrue = false;
                    bool hasFalse = false;
                while(st.top() != '&' && st.top() != '|' && st.top() != '!')
                {
                    char t = st.top();
                    st.pop();
                    if(t == 't') hasTrue = true;
                    else hasFalse = true;
                }
                char op = st.top();
                st.pop();
                if(op == '&')
                {
                    if(hasFalse) st.push('f');
                    else st.push('t');
                }

                else if(op == '|')
                {
                    if(hasTrue) st.push('t');
                    else st.push('f');
                }

                else
                {
                    if(hasTrue) st.push('f');

                    else st.push('t');
                }
            }
        }

        return (st.top() == 't');
    }
};