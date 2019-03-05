                        
class Solution {
public:
    bool isValid(string s) {
        //用栈做？
        stack<char> st;
        for(char c : s)
        {
            cout << c <<endl;
            if(c == ' ')
                continue;
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else 
            {
                if(st.empty())
                    return false;
                char tmp = st.top();
                cout << tmp << endl;
                if(c == ')')
                {
                    cout << "if" << endl;
                    if(tmp != '(')
                        return false;
                    else
                    {
                        st.pop();
                        continue;
                    }
                }
                else if(c == '}')
                {
                    if(tmp != '{')
                        return false;
                    else
                    {
                        st.pop();
                        continue;
                    }
                }
                else if(c == ']')
                {
                    if(tmp != '[')
                        return false;
                    else
                    {
                        st.pop();
                        continue;
                    }
                }
            }
        }
        cout << "test" <<endl;
        return st.empty() ? true: false;
    }
};