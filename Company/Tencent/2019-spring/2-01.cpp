#include<bits/stdc++.h>

int main()
{
    int n;
    string s;

    cin>>n >> s;
    stack<char> st;
    st.push(s[0]);

    for(int i = 1;i<n;i++)
    {
        if(!st.empty()) 
        {
            char tmp = st.top();
            if(tmp != s[i])
                st.pop();
            else if(tmp == s[i])
                st.push(s[i]);
        }
        else if(st.empty())
        {
            st.push(s[i]);
        }
    }
    cout<<st.size()<<endl;
    return 0;
}