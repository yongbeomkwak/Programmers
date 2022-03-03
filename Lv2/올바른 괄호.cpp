#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for (const char &c : s)
    {
        if (st.empty())
        {
            st.push(c);
            continue;
        }
        else if (!st.empty() && st.top() == '(' && c == ')')
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}