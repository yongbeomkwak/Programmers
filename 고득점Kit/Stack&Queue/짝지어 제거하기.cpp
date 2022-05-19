#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    stack<char> st;

    for (const char &c : s)
    {
        if (st.empty())
            st.push(c);
        else
        {
            if (st.top() == c)
                st.pop();
            else
                st.push(c);
        }
    }

    if (!st.empty())
        return 0;
    else
        return 1;
}